/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init effect for boss
*/

#include "rpg.h"

int init_effect(rpg_t *rpg)
{
    rpg->effect->first_door = create_sprite("assets/door/first_door.png");
    rpg->effect->second_door = create_sprite("assets/door/second_door.png");
    rpg->effect->third_door = create_sprite("assets/door/third_door.png");
    rpg->effect->door = create_sprite("assets/door/door.png");

    if (!rpg->effect->first_door || !rpg->effect->second_door ||
    !rpg->effect->third_door || !rpg->effect->door)
        return 1;
    sfSprite_setScale(rpg->effect->first_door, (sfVector2f){1, 1});
    sfSprite_setPosition(rpg->effect->first_door, (sfVector2f){2296, 2956});
    sfSprite_setScale(rpg->effect->second_door, (sfVector2f){1, 1});
    sfSprite_setPosition(rpg->effect->second_door, (sfVector2f){3686, 1106});
    sfSprite_setScale(rpg->effect->third_door, (sfVector2f){1, 1});
    sfSprite_setPosition(rpg->effect->third_door, (sfVector2f){1297, 1090});
    sfSprite_setScale(rpg->effect->door, (sfVector2f){1, 1});
    sfSprite_setPosition(rpg->effect->door, (sfVector2f){2482, 3108});
    return 0;
}
