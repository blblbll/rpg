/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

int player_attack_boss(rpg_t *rpg)
{
    int distance = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(rpg->boss->boss).x, 2)
    + pow(sfSprite_getPosition(rpg->player->player).y -
    sfSprite_getPosition(rpg->boss->boss).y, 2));

    if (rpg->player->weapon == 0) {
        if (distance <= 100) {
            return (1);
        }
    }
    if (rpg->player->weapon == 1) {
        if (distance <= 150) {
            return (1);
        }
    }
    return (0);
}

void game_boss(rpg_t *rpg)
{
    if (rpg->boss->attack == 1) {
        rpg->boss->vie -= rpg->player->attack;
        if (rpg->boss->vie % 2 == 0)
            sfSprite_setColor(rpg->boss->boss, sfRed);
    }
    if (rpg->boss->attack == 2) {
        if (rpg->boss->vie % 2 == 0)
            sfSprite_setColor(rpg->boss->boss, sfRed);
        rpg->boss->vie -= rpg->player->attack;
    }
    rpg->boss->attack = 0;
    if (rpg->boss->vie <= 0) {
        rpg->boss->status = 0;
    }
}
