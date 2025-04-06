/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

int vilain_attack(rpg_t *rpg, sfSprite *vilain, int status)
{
    int distance = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(vilain).x, 2)
    + pow(sfSprite_getPosition(rpg->player->player).y -
    sfSprite_getPosition(vilain).y, 2));

    if (distance <= 50 && status != 0)
        return (1);
    return (0);
}
