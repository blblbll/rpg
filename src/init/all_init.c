/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** all init for rpg
*/

#include "rpg.h"

int all_init_two(rpg_t *rpg, int i)
{
    if (i == 6)
        if (init_vilain(rpg) == 1)
            return 1;
    if (i == 6)
        if (init_collision_image(rpg) == 1)
            return 1;
    if (i == 7)
        if (init_effect(rpg) == 1)
            return 1;
    if (i == 8)
        if (init_boss(rpg) == 1)
            return 1;
    return 0;
}

int all_init(rpg_t *rpg, int i)
{
    if (i == 0)
        if (init_window(rpg) == 1)
            return 1;
    if (i == 1)
        if (init_player(rpg) == 1 || init_sword(rpg) == 1)
            return 1;
    if (i == 2)
        if (init_sound(rpg) == 1)
            return 1;
    if (i == 3)
        if (font_floue(rpg) == 1)
            return 1;
    if (i == 4)
        if (init_sprite(rpg) == 1)
            return 1;
    if (i == 5)
        if (init_dialog(rpg) == 1)
            return 1;
    return all_init_two(rpg, i);
}
