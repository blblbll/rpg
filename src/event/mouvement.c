/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouvement of player
*/

#include "rpg.h"

void player_movement_up(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        movement_up(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void player_movement_down(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        movement_down(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void player_movement_right(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        movement_right(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void player_movement_left(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        movement_left(rpg);
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

void all_mouv(rpg_t *rpg)
{
    if (rpg->page != 1 || !sfRenderWindow_hasFocus(rpg->windo->window))
        return;
    player_movement_left(rpg);
    player_movement_right(rpg);
    player_movement_up(rpg);
    player_movement_down(rpg);
}
