/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event for rpg
*/

#include "rpg.h"

static int just_pressed[sfKeyCount];

void update_keys(rpg_t *rpg)
{
    static int last[sfKeyCount];
    sfKeyCode keys[5] = {sfKeyE, sfKeyP, sfKeyI, sfKeyLeft, sfKeyRight};
    int now = 0;

    for (int i = 0; i < 5; i++) {
        now = sfKeyboard_isKeyPressed(keys[i]) &&
        sfRenderWindow_hasFocus(rpg->windo->window);
        just_pressed[keys[i]] = now && !last[keys[i]];
        last[keys[i]] = now;
    }
}

int key_just_pressed(sfKeyCode key)
{
    return (just_pressed[key]);
}

void key_consume(sfKeyCode key)
{
    just_pressed[key] = 0;
}

int in_dialog(rpg_t *rpg)
{
    return (rpg->dialog_pass < 4 || rpg->pnj_a->interact == 1);
}

void dev_fonction_event(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue && rpg->zoom < 1.35 &&
    rpg->page == 1)
        rpg->zoom += 0.01;
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && rpg->zoom > 1 &&
    rpg->page == 1)
        rpg->zoom -= 0.01;
    if (rpg->page != 1)
        rpg->zoom = 1;
}

void resize(rpg_t *rpg)
{
    if (sfEvtResized == rpg->windo->event.type) {
        rpg->windo->video_mode.width = rpg->windo->event.size.width;
        rpg->windo->video_mode.height = rpg->windo->event.size.height;
    }
}

void echap_key(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        if (rpg->page == 5) {
            rpg->resume = 0;
            rpg->continue_game = 0;
            set_view(rpg, (sfVector2f){5520 / 2, 7680 -
            rpg->windo->video_mode.height / 2}, 1);
        }
        rpg->page = 0;
    }
}

void event(rpg_t *rpg)
{
    update_keys(rpg);
    while (sfRenderWindow_pollEvent(rpg->windo->window, &rpg->windo->event)) {
        if (rpg->windo->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->windo->window);
        resize(rpg);
        echap_key(rpg);
    }
    if (rpg->page == 1 && !in_dialog(rpg) && attack_val(0) <= 0)
        all_mouv(rpg);
    if (rpg->page == 1)
        deplace_map(rpg);
    player_attack(rpg);
    dev_fonction_event(rpg);
    game_boss(rpg);
    boss_detection(rpg);
    vilain_detection(rpg);
    game_vilain(rpg);
}
