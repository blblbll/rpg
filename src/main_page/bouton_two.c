/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** bouton_two
*/

#include "rpg.h"

static struct {
    int sel;
    int moved;
    int edge[sfKeyCount];
    int last[sfKeyCount];
    sfVector2i mouse;
} g_menu = {-1, 0, {0}, {0}, {0, 0}};

static void update_menu_keys(rpg_t *rpg)
{
    sfKeyCode keys[5] = {sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight,
    sfKeyReturn};
    int now = 0;

    for (int i = 0; i < 5; i++) {
        now = sfKeyboard_isKeyPressed(keys[i]) &&
        sfRenderWindow_hasFocus(rpg->windo->window);
        g_menu.edge[keys[i]] = now && !g_menu.last[keys[i]];
        g_menu.last[keys[i]] = now;
    }
}

void menu_begin(rpg_t *rpg, const int *ids, int n)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->windo->window);
    int idx = -1;

    update_menu_keys(rpg);
    g_menu.moved = (mouse.x != g_menu.mouse.x || mouse.y != g_menu.mouse.y);
    g_menu.mouse = mouse;
    for (int i = 0; i < n; i++)
        if (ids[i] == g_menu.sel)
            idx = i;
    if (idx == -1)
        idx = 0;
    else if (g_menu.edge[sfKeyUp])
        idx = (idx + n - 1) % n;
    else if (g_menu.edge[sfKeyDown])
        idx = (idx + 1) % n;
    g_menu.sel = ids[idx];
}

int menu_edge(sfKeyCode key)
{
    return (g_menu.edge[key]);
}

int menu_selected(int id)
{
    return (g_menu.sel == id);
}

int menu_moved(void)
{
    return (g_menu.moved);
}

void menu_select(int id)
{
    g_menu.sel = id;
}

int menu_item(rpg_t *rpg, sfVector2i mouse, int id)
{
    sfFloatRect rect = sfText_getGlobalBounds(rpg->player->text);
    int hover = sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg));

    if (hover && g_menu.moved)
        g_menu.sel = id;
    if (g_menu.sel == id)
        sfText_setColor(rpg->player->text, sfRed);
    if (hover && sfMouse_isButtonPressed(sfMouseLeft)) {
        g_menu.sel = id;
        return (1);
    }
    return (g_menu.sel == id && g_menu.edge[sfKeyReturn]);
}

void all_bouton(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->windo->window);
    int with_continue[5] = {MENU_CONTINUE, MENU_START, MENU_OPTION,
    MENU_CREDIT, MENU_QUIT};

    if (rpg->continue_game == 1)
        menu_begin(rpg, with_continue, 5);
    else
        menu_begin(rpg, with_continue + 1, 4);
    if (rpg->continue_game == 1) {
        bouton_continue(rpg, edd, mouse);
        sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 500, edd.y -
        400});
    } else
        sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 300, edd.y -
        400});
    bouton_start(rpg, mouse);
    bouton_option(rpg, edd, mouse);
    bouton_credit(rpg, edd, mouse);
    bouton_quit(rpg, edd, mouse);
}

static void reset_monsters(rpg_t *rpg)
{
    sfSprite *v[5] = {rpg->vilain->vilain1, rpg->vilain->vilain2,
    rpg->vilain->vilain3, rpg->vilain->vilain4, rpg->vilain->vilain5};
    sfVector2f p[5] = {rpg->vilain->vilain1_pos, rpg->vilain->vilain2_pos,
    rpg->vilain->vilain3_pos, rpg->vilain->vilain4_pos,
    rpg->vilain->vilain5_pos};

    set_stat(rpg);
    for (int i = 0; i < 5; i++) {
        sfSprite_setPosition(v[i], p[i]);
        sfSprite_setColor(v[i], sfWhite);
    }
    rpg->boss->vie = 100;
    rpg->boss->attack = 0;
    rpg->boss->status = 1;
    sfSprite_setPosition(rpg->boss->boss, rpg->boss->boss_pos);
    sfSprite_setColor(rpg->boss->boss, sfWhite);
}

static void reset_inventory(rpg_t *rpg)
{
    item_t *item = NULL;

    for (int i = 0; i < INV_SIZE; i++) {
        item = rpg->player->inv->list_item[i];
        item->empty = 1;
        item->name = NULL;
        item->sprite = NULL;
        item->description = NULL;
    }
    rpg->player->inv->hand = 0;
    rpg->player->have_key = 0;
    rpg->player->potion_have = 0;
    rpg->effect->door_open = 0;
}

void reset_world(rpg_t *rpg)
{
    reset_monsters(rpg);
    reset_inventory(rpg);
    reset_second_chest();
    reset_third_chest();
    reset_four_chest();
    reset_fith_chest();
    reset_six_chest();
    reset_level();
    attack_val(-1);
    rpg->pnj_a->interact = 0;
    rpg->player->sword1 = 0;
    rpg->player->sword2 = 0;
    rpg->player->player_rect = create_rect(900, 64, 50, 63);
}

void all_reset(rpg_t *rpg)
{
    reset_world(rpg);
    rpg->dialog_sound = 0;
    rpg->player->chest = 0;
    rpg->dialog_pass = 0;
    rpg->defil = 0;
    rpg->player->weapon = 0;
    rpg->player->chest = 0;
    rpg->player->player = create_sprite("assets/perso/Perso1.png");
    sfSprite_setPosition(rpg->player->player, (sfVector2f){2550, 7100});
    sfSprite_setScale(rpg->player->player, (sfVector2f){3.5, 3.5});
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
    rpg->player->direction = 0;
    rpg->player->attack = 1;
    rpg->player->life_rect.top = 0;
    rpg->player->vie = 375;
    rpg->player->player_pos = (sfVector2f) {2550, 7100};
    set_view(rpg, (sfVector2f){5520 / 2, 7680 -
    rpg->windo->video_mode.height / 2}, 1);
    rpg->page = 1;
}
