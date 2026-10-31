/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

int player_attack_boss(rpg_t *rpg)
{
    return (rpg->boss->status != 0 && hit_sprite(rpg, rpg->boss->boss));
}

void game_boss(rpg_t *rpg)
{
    if (rpg->boss->attack == 1) {
        rpg->boss->vie -= player_damage(rpg, 1);
        flash_red(rpg->boss->boss);
    }
    if (rpg->boss->attack == 2) {
        flash_red(rpg->boss->boss);
        rpg->boss->vie -= player_damage(rpg, 2);
    }
    rpg->boss->attack = 0;
    if (rpg->boss->vie <= 0) {
        rpg->boss->status = 0;
    }
}

sfClock *flash_clock(void)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    return (clock);
}

void flash_red(sfSprite *sprite)
{
    sfSprite_setColor(sprite, sfRed);
    sfClock_restart(flash_clock());
}

void clear_flash(rpg_t *rpg)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(flash_clock())) < 150)
        return;
    sfSprite_setColor(rpg->boss->boss, sfWhite);
    sfSprite_setColor(rpg->vilain->vilain1, sfWhite);
    sfSprite_setColor(rpg->vilain->vilain2, sfWhite);
    sfSprite_setColor(rpg->vilain->vilain3, sfWhite);
    sfSprite_setColor(rpg->vilain->vilain4, sfWhite);
    sfSprite_setColor(rpg->vilain->vilain5, sfWhite);
}
