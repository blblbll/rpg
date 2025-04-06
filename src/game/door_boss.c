/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** door_boss
*/

#include "rpg.h"

void draw_arch(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->windo->window,
    rpg->effect->first_door, NULL);
    sfRenderWindow_drawSprite(rpg->windo->window,
    rpg->effect->second_door, NULL);
    sfRenderWindow_drawSprite(rpg->windo->window,
    rpg->effect->third_door, NULL);
}

void draw_all_door(rpg_t *rpg)
{
    sfSprite_setRotation(rpg->effect->door, 0);
    sfSprite_setPosition(rpg->effect->door, (sfVector2f){2482, 3108});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->effect->door, NULL);
    sfSprite_setPosition(rpg->effect->door, (sfVector2f){3860, 1560});
    sfSprite_setRotation(rpg->effect->door, -90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->effect->door, NULL);
    sfSprite_setPosition(rpg->effect->door, (sfVector2f){1440, 1220});
    sfSprite_setRotation(rpg->effect->door, 90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->effect->door, NULL);
}

void door_for_boss(rpg_t *rpg)
{
    draw_arch(rpg);
    if (rpg->player->have_key == 1)
        rpg->effect->door_open = 1;
    if (rpg->effect->door_open == 0)
        draw_all_door(rpg);
}
