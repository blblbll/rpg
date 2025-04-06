/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

void set_color_no_weapon2(rpg_t *rpg)
{
    if (rpg->vilain->attack4 == 1) {
        rpg->vilain->vie4 -= rpg->player->attack;
        if (rpg->vilain->vie4 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain4, sfRed);
        rpg->vilain->attack4 = 0;
    }
    if (rpg->vilain->attack5 == 1) {
        rpg->vilain->vie5 -= rpg->player->attack;
        if (rpg->vilain->vie5 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain5, sfRed);
        rpg->vilain->attack5 = 0;
    }
}

void set_color_no_weapon(rpg_t *rpg)
{
    if (rpg->vilain->attack1 == 1) {
        rpg->vilain->vie1 -= rpg->player->attack;
        if (rpg->vilain->vie1 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain1, sfRed);
        rpg->vilain->attack1 = 0;
    }
    if (rpg->vilain->attack2 == 1) {
        rpg->vilain->vie2 -= rpg->player->attack;
        if (rpg->vilain->vie2 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain2, sfRed);
        rpg->vilain->attack2 = 0;
    }
    if (rpg->vilain->attack3 == 1) {
        rpg->vilain->vie3 -= rpg->player->attack;
        if (rpg->vilain->vie3 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain3, sfRed);
        rpg->vilain->attack3 = 0;
    }
    set_color_no_weapon2(rpg);
}

void set_color_weapon2(rpg_t *rpg)
{
    if (rpg->vilain->attack4 == 2) {
        rpg->vilain->vie4 -= rpg->player->attack;
        if (rpg->vilain->vie4 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain4, sfRed);
        rpg->vilain->attack4 = 0;
    }
    if (rpg->vilain->attack5 == 2) {
        rpg->vilain->vie5 -= rpg->player->attack;
        if (rpg->vilain->vie5 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain5, sfRed);
        rpg->vilain->attack5 = 0;
    }
}

void set_color_weapon(rpg_t *rpg)
{
    if (rpg->vilain->attack1 == 2) {
        rpg->vilain->vie1 -= rpg->player->attack;
        if (rpg->vilain->vie1 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain1, sfRed);
        rpg->vilain->attack1 = 0;
    }
    if (rpg->vilain->attack2 == 2) {
        rpg->vilain->vie2 -= rpg->player->attack;
        if (rpg->vilain->vie2 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain2, sfRed);
        rpg->vilain->attack2 = 0;
    }
    if (rpg->vilain->attack3 == 2) {
        rpg->vilain->vie3 -= rpg->player->attack;
        if (rpg->vilain->vie3 % 2 == 0)
            sfSprite_setColor(rpg->vilain->vilain3, sfRed);
        rpg->vilain->attack3 = 0;
    }
    set_color_weapon2(rpg);
}

void set_status_vilain(rpg_t *rpg)
{
    if (rpg->vilain->vie4 <= 0 && rpg->vilain->status4 != 0) {
        rpg->player->attack += 1;
        rpg->vilain->status4 = 0;
        rpg->vilain->vie4 = 1;
    }
    if (rpg->vilain->vie5 <= 0 && rpg->vilain->status5 != 0) {
        rpg->player->attack += 1;
        rpg->vilain->status5 = 0;
        rpg->vilain->vie5 = 1;
    }
}
