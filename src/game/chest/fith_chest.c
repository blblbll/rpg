/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** fith_chest
*/

#include "rpg.h"

int open_fith_chest(rpg_t *rpg, int o)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){1900, 4800});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE)) {
        key_consume(sfKeyE);
        o = 1;
    }
    return (o);
}

int has_free_slot(rpg_t *rpg)
{
    for (int i = 0; i < INV_SIZE; i++)
        if (rpg->player->inv->list_item[i]->empty == 1)
            return (1);
    return (0);
}

void give_item(rpg_t *rpg, char *name, char *desc, sfSprite *sprite)
{
    for (int i = 0; i < INV_SIZE; i++) {
        if (rpg->player->inv->list_item[i]->empty == 1) {
            rpg->player->inv->list_item[i]->empty = 0;
            rpg->player->inv->list_item[i]->sprite = sprite;
            rpg->player->inv->list_item[i]->name = name;
            rpg->player->inv->list_item[i]->description = desc;
            break;
        }
    }
}

void add_power_potion(rpg_t *rpg)
{
    give_item(rpg, "Potion de force",
    "Augmente l'attaque de 2.\nAppuyer sur E pour l'utiliser.",
    rpg->player->power_potion);
}

int recup_power_potion(rpg_t *rpg, int o)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){2240, 4800});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE) && has_free_slot(rpg)) {
        o = 2;
        add_power_potion(rpg);
    }
    return (o);
}

static int g_state = 0;

void reset_fith_chest(void)
{
    g_state = 0;
}

void fith_chest(rpg_t *rpg)
{
    int o = g_state;
    if (rpg->player->player_pos.x >= 1990 && rpg->player->player_pos.x <= 2200
    && rpg->player->player_pos.y >= 4700 && rpg->player->player_pos.y <= 5100
    && o == 0)
        o = open_fith_chest(rpg, o);
    if (rpg->player->player_pos.x >= 2180 && rpg->player->player_pos.x <= 2420
    && rpg->player->player_pos.y >= 4700 && rpg->player->player_pos.y <= 5100
    && o == 1)
        o = recup_power_potion(rpg, o);
    if (o == 1) {
        rpg->player->rect_chest.left = 460;
        sfSprite_setPosition(rpg->player->power_potion, (sfVector2f){2330,
        4900});
        sfRenderWindow_drawSprite(rpg->windo->window,
        rpg->player->power_potion, NULL);
    } else if (o == 2)
        rpg->player->rect_chest.left = 460;
    else
        rpg->player->rect_chest.left = 250;
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){2040, 5000});
    sfSprite_setRotation(rpg->player->coffre, -90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
    g_state = o;
    six_chest(rpg);
}
