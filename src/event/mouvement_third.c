/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouvement_third
*/

#include "rpg.h"

void cond_move_rect(rpg_t *rpg)
{
    if (rpg->player->weapon == 1 && rpg->player->direction == 2)
        rpg->player->player_rect.left = 67;
    else if (rpg->player->weapon == 1 && rpg->player->direction == 4)
        rpg->player->player_rect.left = 63;
    else
        rpg->player->player_rect.left = 60;
}

void move_rect_pl(rpg_t *rpg, int offset, int max_value)
{
    rpg->player->player_rect.left = rpg->player->player_rect.left + offset;
    if (rpg->player->player_rect.left >= max_value) {
        cond_move_rect(rpg);
    }
}

void chrono_player(rpg_t *rpg, sfClock *clock, float secc, int max)
{
    sfTime time;
    float sec;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / secc;
    if (sec > 0.55) {
        move_rect_pl(rpg, 64, max);
        sfClock_restart(clock);
    }
}

int touch_bordure_two(rpg_t *rpg, sfColor col)
{
    for (int i = 20;  i < 190; i++) {
        col = sfImage_getPixel(rpg->image_font, rpg->player->player_pos.x + 50,
        rpg->player->player_pos.y + i);
        if (col.r == 255 && col.g == 255 && col.b == 255)
            return (1);
        col = sfImage_getPixel(rpg->image_font, rpg->player->player_pos.x +
        140, rpg->player->player_pos.y + i);
        if (col.r == 255 && col.g == 255 && col.b == 255)
            return (1);
    }
    return (0);
}

int touch_bordure(rpg_t *rpg)
{
    sfColor col = sfImage_getPixel(rpg->image_font, rpg->player->player_pos.x
    + 50, rpg->player->player_pos.y + 20);
    for (int i = 50;  i < 140; i++) {
        col = sfImage_getPixel(rpg->image_font, rpg->player->player_pos.x + i,
        rpg->player->player_pos.y + 20);
        if (col.r == 255 && col.g == 255 && col.b == 255)
            return (1);
        col = sfImage_getPixel(rpg->image_font, rpg->player->player_pos.x + i,
        rpg->player->player_pos.y + 190);
        if (col.r == 255 && col.g == 255 && col.b == 255)
            return (1);
    }
    if (touch_bordure_two(rpg, col) == 1)
        return (1);
    return (0);
}
