/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init boss rpg
*/

#include "rpg.h"

int init_boss(rpg_t *rpg)
{
    sfTexture *texture = sfTexture_createFromFile("assets/perso/boss.png",
    NULL);

    if (!texture)
        return 1;
    rpg->boss->vie = 250;
    rpg->boss->attack = 0;
    rpg->boss->status = 1;
    rpg->boss->boss = sfSprite_create();
    rpg->boss->boss_rect = create_rect(193, 285, 48, 48);
    rpg->boss->boss_pos = (sfVector2f) {2500, 1300};
    sfSprite_setTexture(rpg->boss->boss, texture, sfTrue);
    sfSprite_setScale(rpg->boss->boss, (sfVector2f) {6.5, 6.5});
    sfSprite_setPosition(rpg->boss->boss, rpg->boss->boss_pos);
    sfSprite_setTextureRect(rpg->boss->boss, rpg->boss->boss_rect);
    return (0);
}
