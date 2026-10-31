/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

void boss_mouvement(rpg_t *rpg)
{
    int distance = sqrt(pow(sfSprite_getPosition(rpg->boss->boss).x -
    sfSprite_getPosition(rpg->player->player).x, 2)
    + pow(sfSprite_getPosition(rpg->boss->boss).y -
    sfSprite_getPosition(rpg->player->player).y, 2));
    float dx;
    float dy;
    float angle;
    float vx;
    float vy;

    if (distance > 20) {
        dx = sfSprite_getPosition(rpg->player->player).x -
        sfSprite_getPosition(rpg->boss->boss).x;
        dy = sfSprite_getPosition(rpg->player->player).y -
        sfSprite_getPosition(rpg->boss->boss).y;
        angle = atan2(dy, dx);
        vx = cos(angle) * 2;
        vy = sin(angle) * 2;
        sfSprite_move(rpg->boss->boss, (sfVector2f){vx, vy});
    }
}

void boss_detection(rpg_t *rpg)
{
    sfVector2f pos1 = {rpg->boss->boss_pos.x - 900,
    rpg->boss->boss_pos.y - 900};
    sfVector2f pos2 = {rpg->boss->boss_pos.x + 900,
    rpg->boss->boss_pos.y + 900};

    if (rpg->player->player_pos.x >= pos1.x &&
    rpg->player->player_pos.x <= pos2.x &&
    rpg->player->player_pos.y >= pos1.y
    && rpg->player->player_pos.y <= pos2.y) {
        boss_mouvement(rpg);
    }
}
