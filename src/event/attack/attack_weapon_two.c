/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** second part attack for player
*/

#include "rpg.h"

void move_rect_attack(sfIntRect *rect, int offset, int max_value, int dir)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value) {
        if (dir == 1 || dir == 3)
            rect->left = 30;
        if (dir == 2)
            rect->left = 50;
        if (dir == 4)
            rect->left = 10;
    }
}

void chrono_player_attack(rpg_t *rpg, sfClock *clock, float secc, int max)
{
    sfTime time;
    float sec;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / secc;
    if (sec > 0.55) {
        move_rect_attack(&rpg->player->player_rect, 129, max,
        rpg->player->direction);
        sfClock_restart(clock);
    }
}

void attack_id(rpg_t *rpg)
{
    if (rpg->player->attack_id == 1 && attack_step_ready(0)) {
        chrono_player_attack(rpg, rpg->windo->clock, 10000.0, 760);
        attack_val(attack_val(0) + 1);
    }
    rpg->player->attack_id = 0;
}

int attack_step_ready(int reset)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (reset) {
        sfClock_restart(clock);
        return (0);
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 75)
        return (0);
    sfClock_restart(clock);
    return (1);
}
