/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack_no_weapon_two
*/

#include "rpg.h"

void move_rect_attack_no_w(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}

void chrono_player_attack_no_w(rpg_t *rpg, sfClock *clock, float secc, int max)
{
    sfTime time;
    float sec;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / secc;
    if (sec > 0.55) {
        move_rect_attack_no_w(&rpg->player->player_rect, 64, max);
        sfClock_restart(clock);
    }
}

void attack_id_no_w(rpg_t *rpg)
{
    if (rpg->player->attack_id == 1 && attack_step_ready(0)) {
        chrono_player_attack_no_w(rpg, rpg->windo->clock, 10000.0, 370);
        attack_val(attack_val(0) + 1);
    }
    rpg->player->attack_id = 0;
}
