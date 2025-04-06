/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack for player
*/

#include "rpg.h"

void player_attack(rpg_t *rpg)
{
    int we = rpg->player->weapon;
    if (we == 0)
        attack_no_weapon(rpg);
    if (we == 1)
        attack_with_weapon(rpg);
}
