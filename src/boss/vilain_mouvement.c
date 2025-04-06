/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

void vilain_mouvement(rpg_t *rpg, sfSprite *vilain)
{
    int distance = sqrt(pow(sfSprite_getPosition(vilain).x -
    sfSprite_getPosition(rpg->player->player).x, 2)
    + pow(sfSprite_getPosition(vilain).y -
    sfSprite_getPosition(rpg->player->player).y, 2));
    float dx;
    float dy;
    float angle;
    float vx;
    float vy;

    if (distance > 5) {
        dx = sfSprite_getPosition(rpg->player->player).x -
        sfSprite_getPosition(vilain).x;
        dy = sfSprite_getPosition(rpg->player->player).y -
        sfSprite_getPosition(vilain).y;
        angle = atan2(dy, dx);
        vx = cos(angle) * 2;
        vy = sin(angle) * 2;
        sfSprite_move(vilain, (sfVector2f){vx, vy});
    }
}

void vilain_zone(rpg_t *rpg, sfVector2f pos1,
sfVector2f pos2, sfSprite *vilain)
{
    if (rpg->player->player_pos.x >= pos1.x &&
    rpg->player->player_pos.x <= pos2.x &&
    rpg->player->player_pos.y >= pos1.y
    && rpg->player->player_pos.y <= pos2.y) {
        vilain_mouvement(rpg, vilain);
    }
}

void vilain_detection_bis(rpg_t *rpg)
{
    sfVector2f pos1 = {rpg->vilain->vilain4_pos.x - 300,
    rpg->vilain->vilain4_pos.y - 300};
    sfVector2f pos2 = {rpg->vilain->vilain4_pos.x + 300,
    rpg->vilain->vilain4_pos.y + 300};
    sfVector2f pos3 = {rpg->vilain->vilain5_pos.x - 300,
    rpg->vilain->vilain5_pos.y - 300};
    sfVector2f pos4 = {rpg->vilain->vilain5_pos.x + 300,
    rpg->vilain->vilain5_pos.y + 300};

    vilain_zone(rpg, pos1, pos2, rpg->vilain->vilain4);
    vilain_zone(rpg, pos3, pos4, rpg->vilain->vilain5);
}

void vilain_detection(rpg_t *rpg)
{
    sfVector2f pos1 = {rpg->vilain->vilain1_pos.x - 300,
    rpg->vilain->vilain1_pos.y - 300};
    sfVector2f pos2 = {rpg->vilain->vilain1_pos.x + 300,
    rpg->vilain->vilain1_pos.y + 300};
    sfVector2f pos3 = {rpg->vilain->vilain2_pos.x - 300,
    rpg->vilain->vilain2_pos.y - 300};
    sfVector2f pos4 = {rpg->vilain->vilain2_pos.x + 300,
    rpg->vilain->vilain2_pos.y + 300};
    sfVector2f pos5 = {rpg->vilain->vilain3_pos.x - 300,
    rpg->vilain->vilain3_pos.y - 300};
    sfVector2f pos6 = {rpg->vilain->vilain3_pos.x + 300,
    rpg->vilain->vilain3_pos.y + 300};

    vilain_zone(rpg, pos1, pos2, rpg->vilain->vilain1);
    vilain_zone(rpg, pos3, pos4, rpg->vilain->vilain2);
    vilain_zone(rpg, pos5, pos6, rpg->vilain->vilain3);
    vilain_detection_bis(rpg);
}
