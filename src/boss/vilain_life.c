/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

void which_mob2(rpg_t *rpg)
{
    if (player_attack_vilain(rpg) == 1 && rpg->vilain->status1 != 0) {
        rpg->vilain->attack1 = 2;
        sfSprite_setColor(rpg->vilain->vilain1, sfWhite);
    }
    if (player_attack_vilain(rpg) == 2 && rpg->vilain->status2 != 0) {
        rpg->vilain->attack2 = 2;
        sfSprite_setColor(rpg->vilain->vilain2, sfWhite);
    }
    if (player_attack_vilain(rpg) == 3 && rpg->vilain->status3 != 0) {
        rpg->vilain->attack3 = 2;
        sfSprite_setColor(rpg->vilain->vilain3, sfWhite);
    }
    if (player_attack_vilain(rpg) == 4 && rpg->vilain->status4 != 0) {
        rpg->vilain->attack4 = 2;
        sfSprite_setColor(rpg->vilain->vilain4, sfWhite);
    }
    if (player_attack_vilain(rpg) == 5 && rpg->vilain->status5 != 0) {
        rpg->vilain->attack5 = 2;
        sfSprite_setColor(rpg->vilain->vilain5, sfWhite);
    }
}

int distance_to_kill2(rpg_t *rpg)
{
    int distance = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(rpg->vilain->vilain4).x, 2) + pow(sfSprite_getPosition(
    rpg->player->player).y - sfSprite_getPosition(rpg->vilain->vilain4).y, 2));
    int distance1 = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(rpg->vilain->vilain5).x, 2) + pow(sfSprite_getPosition
    (rpg->player->player).y - sfSprite_getPosition(rpg->vilain->vilain5).y, 2));

    if (rpg->player->weapon == 0) {
        if (distance <= 100)
            return (4);
        if (distance1 <= 100)
            return (5);
    }
    if (rpg->player->weapon == 1) {
        if (distance <= 150)
            return (4);
        if (distance1 <= 150)
            return (5);
    }
    return (0);
}

int distance_to_kill(rpg_t *rpg, int dist1, int dist2, int dist3)
{
    if (rpg->player->weapon == 0) {
        if (dist1 <= 100)
            return (1);
        if (dist2 <= 100)
            return (2);
        if (dist3 <= 100)
            return (3);
    }
    if (rpg->player->weapon == 1) {
        if (dist1 <= 150)
            return (1);
        if (dist2 <= 150)
            return (2);
        if (dist3 <= 150)
            return (3);
    }
    return (0);
}

int player_attack_vilain(rpg_t *rpg)
{
    int nb = 0;
    int distance = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(rpg->vilain->vilain1).x, 2)
    + pow(sfSprite_getPosition(rpg->player->player).y -
    sfSprite_getPosition(rpg->vilain->vilain1).y, 2));
    int distance1 = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(rpg->vilain->vilain2).x, 2)
    + pow(sfSprite_getPosition(rpg->player->player).y -
    sfSprite_getPosition(rpg->vilain->vilain2).y, 2));
    int distance2 = sqrt(pow(sfSprite_getPosition(rpg->player->player).x -
    sfSprite_getPosition(rpg->vilain->vilain3).x, 2)
    + pow(sfSprite_getPosition(rpg->player->player).y -
    sfSprite_getPosition(rpg->vilain->vilain3).y, 2));

    nb = distance_to_kill(rpg, distance, distance1, distance2);
    nb = distance_to_kill2(rpg);
    return (nb);
}

void game_vilain(rpg_t *rpg)
{
    set_color_no_weapon(rpg);
    set_color_weapon(rpg);
    if (rpg->vilain->vie1 <= 0 && rpg->vilain->status1 != 0) {
        rpg->player->attack += 1;
        rpg->vilain->status1 = 0;
        rpg->vilain->vie1 = 1;
    }
    if (rpg->vilain->vie2 <= 0 && rpg->vilain->status2 != 0) {
        rpg->player->attack += 1;
        rpg->vilain->status2 = 0;
        rpg->vilain->vie2 = 1;
    }
    if (rpg->vilain->vie3 <= 0 && rpg->vilain->status3 != 0) {
        rpg->player->attack += 1;
        rpg->vilain->status3 = 0;
        rpg->vilain->vie3 = 1;
    }
    set_status_vilain(rpg);
}
