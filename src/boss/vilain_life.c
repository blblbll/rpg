/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

void hit_vilains(rpg_t *rpg, int mode)
{
    int *attack[5] = {&rpg->vilain->attack1, &rpg->vilain->attack2,
    &rpg->vilain->attack3, &rpg->vilain->attack4, &rpg->vilain->attack5};
    int *status[5] = {&rpg->vilain->status1, &rpg->vilain->status2,
    &rpg->vilain->status3, &rpg->vilain->status4, &rpg->vilain->status5};
    sfSprite *sprite[5] = {rpg->vilain->vilain1, rpg->vilain->vilain2,
    rpg->vilain->vilain3, rpg->vilain->vilain4, rpg->vilain->vilain5};

    for (int i = 0; i < 5; i++) {
        if (*status[i] != 0 && hit_sprite(rpg, sprite[i])) {
            *attack[i] = mode;
            sfSprite_setColor(sprite[i], sfWhite);
        }
    }
}

void which_mob2(rpg_t *rpg)
{
    hit_vilains(rpg, 2);
}

int player_attack_vilain(rpg_t *rpg)
{
    sfSprite *sprite[5] = {rpg->vilain->vilain1, rpg->vilain->vilain2,
    rpg->vilain->vilain3, rpg->vilain->vilain4, rpg->vilain->vilain5};
    int status[5] = {rpg->vilain->status1, rpg->vilain->status2,
    rpg->vilain->status3, rpg->vilain->status4, rpg->vilain->status5};

    for (int i = 0; i < 5; i++) {
        if (status[i] != 0 && hit_sprite(rpg, sprite[i]))
            return (i + 1);
    }
    return (0);
}

void game_vilain(rpg_t *rpg)
{
    clear_flash(rpg);
    set_color_no_weapon(rpg);
    set_color_weapon(rpg);
    if (rpg->vilain->vie1 <= 0 && rpg->vilain->status1 != 0) {
        level_up(rpg);
        rpg->vilain->status1 = 0;
        rpg->vilain->vie1 = 1;
    }
    if (rpg->vilain->vie2 <= 0 && rpg->vilain->status2 != 0) {
        level_up(rpg);
        rpg->vilain->status2 = 0;
        rpg->vilain->vie2 = 1;
    }
    if (rpg->vilain->vie3 <= 0 && rpg->vilain->status3 != 0) {
        level_up(rpg);
        rpg->vilain->status3 = 0;
        rpg->vilain->vie3 = 1;
    }
    set_status_vilain(rpg);
}
