/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouvement two of player
*/

#include "rpg.h"

void movement_left(rpg_t *rpg)
{
    if (rpg->effect->door_open == 0 && rpg->player->player_pos.x <= 3990 &&
    rpg->player->player_pos.x >= 3700 && rpg->player->player_pos.y <= 1590 &&
    rpg->player->player_pos.y >= 1100)
        return;
    if (blocked_move(rpg, -rpg->player->vitesse, 0))
        return;
    rpg->player->player_pos.x -= rpg->player->vitesse;
    rpg->player->player_rect.top = 590;
    if (rpg->player->weapon == 1 && rpg->player->sword1 == 0) {
        rpg->player->player_rect.left = 63;
        rpg->player->sword1 = 1;
    }
    sfSprite_setPosition(rpg->player->player, rpg->player->player_pos);
    chrono_player(rpg, rpg->windo->clock, 180000.0, 550);
    rpg->player->direction = 4;
    rpg->player->sword2 = 0;
}

void movement_right(rpg_t *rpg)
{
    if (rpg->effect->door_open == 0 && rpg->player->player_pos.x >= 1050 &&
    rpg->player->player_pos.x <= 1350 && rpg->player->player_pos.y <= 1590 &&
    rpg->player->player_pos.y >= 1100)
        return;
    if (blocked_move(rpg, rpg->player->vitesse, 0))
        return;
    rpg->player->player_pos.x += rpg->player->vitesse;
    rpg->player->player_rect.top = 717;
    if (rpg->player->weapon == 1 && rpg->player->sword2 == 0) {
        rpg->player->player_rect.left = 67;
        rpg->player->sword2 = 1;
    }
    sfSprite_setPosition(rpg->player->player, rpg->player->player_pos);
    chrono_player(rpg, rpg->windo->clock, 180000.0, 560);
    rpg->player->direction = 2;
    rpg->player->sword1 = 0;
}

void movement_down(rpg_t *rpg)
{
    if (blocked_move(rpg, 0, rpg->player->vitesse))
        return;
    rpg->player->player_pos.y += rpg->player->vitesse;
    rpg->player->player_rect.top = 650;
    sfSprite_setPosition(rpg->player->player, rpg->player->player_pos);
    chrono_player(rpg, rpg->windo->clock, 180000.0, 550);
    rpg->player->direction = 3;
    rpg->player->sword1 = 0;
    rpg->player->sword2 = 0;
}

void movement_up(rpg_t *rpg)
{
    if (rpg->effect->door_open == 0 && rpg->player->player_pos.x >= 2460 &&
    rpg->player->player_pos.x <= 2840 && rpg->player->player_pos.y <= 3270)
        return;
    if (blocked_move(rpg, 0, -rpg->player->vitesse))
        return;
    rpg->player->player_pos.y -= rpg->player->vitesse;
    rpg->player->player_rect.top = 520;
    sfSprite_setPosition(rpg->player->player, rpg->player->player_pos);
    chrono_player(rpg, rpg->windo->clock, 180000.0, 560);
    rpg->player->direction = 1;
    rpg->player->sword1 = 0;
    rpg->player->sword2 = 0;
}
