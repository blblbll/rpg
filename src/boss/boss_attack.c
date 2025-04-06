/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

int boss_attack(rpg_t *rpg)
{
    int distance = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(rpg->boss->boss).x, 2)
    + pow(sfSprite_getPosition(rpg->player->player).y -
    sfSprite_getPosition(rpg->boss->boss).y, 2));

    if (distance <= 75 && rpg->boss->status != 0)
        return (1);
    return (0);
}
