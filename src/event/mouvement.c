/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouvement of player
*/

#include "rpg.h"

void player_movement_up(rpg_t *rpg)
{
    if (rpg->windo->event.type == sfEvtKeyPressed &&
    rpg->windo->event.key.code == sfKeyUp) {
        movement_up(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void player_movement_down(rpg_t *rpg)
{
    if (rpg->windo->event.type == sfEvtKeyPressed &&
    rpg->windo->event.key.code == sfKeyDown) {
        movement_down(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void player_movement_right(rpg_t *rpg)
{
    if (rpg->windo->event.type == sfEvtKeyPressed &&
    rpg->windo->event.key.code == sfKeyRight) {
        movement_right(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void player_movement_left(rpg_t *rpg)
{
    if (rpg->windo->event.type == sfEvtKeyPressed &&
    rpg->windo->event.key.code == sfKeyLeft) {
        movement_left(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void all_mouv(rpg_t *rpg)
{
    if (rpg->page != 1)
        return;
    player_movement_left(rpg);
    player_movement_right(rpg);
    player_movement_up(rpg);
    player_movement_down(rpg);
}
