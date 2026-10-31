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

int is_wall(rpg_t *rpg, int x, int y)
{
    sfVector2u size = sfImage_getSize(rpg->image_font);
    sfColor col;

    if (x < 0 || y < 0 || x >= (int) size.x || y >= (int) size.y)
        return (1);
    col = sfImage_getPixel(rpg->image_font, x, y);
    return (col.r == 255 && col.g == 255 && col.b == 255);
}

int touch_bordure_two(rpg_t *rpg, sfVector2f pos)
{
    for (int i = 20; i < 190; i++) {
        if (is_wall(rpg, pos.x + 50, pos.y + i) ||
        is_wall(rpg, pos.x + 140, pos.y + i))
            return (1);
    }
    return (0);
}

int touch_bordure_at(rpg_t *rpg, sfVector2f pos)
{
    for (int i = 50; i < 140; i++) {
        if (is_wall(rpg, pos.x + i, pos.y + 20) ||
        is_wall(rpg, pos.x + i, pos.y + 190))
            return (1);
    }
    return (touch_bordure_two(rpg, pos));
}

int touch_bordure(rpg_t *rpg)
{
    return (touch_bordure_at(rpg, rpg->player->player_pos));
}

int blocked_move(rpg_t *rpg, int dx, int dy)
{
    sfVector2f pos = rpg->player->player_pos;
    sfVector2f next = {pos.x + dx, pos.y + dy};

    return (touch_bordure_at(rpg, next) && !touch_bordure_at(rpg, pos));
}
