/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

int vilain_attack(rpg_t *rpg, sfSprite *vilain, int status)
{
    if (status != 0 && touch_player(rpg, vilain, 5))
        return (1);
    return (0);
}
