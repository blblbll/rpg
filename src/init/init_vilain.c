/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init sound
*/

#include "rpg.h"

void set_stat(rpg_t *rpg)
{
    rpg->vilain->vie1 = 25;
    rpg->vilain->vie2 = 25;
    rpg->vilain->vie3 = 25;
    rpg->vilain->vie4 = 55;
    rpg->vilain->vie5 = 55;
    rpg->vilain->attack1 = 0;
    rpg->vilain->attack2 = 0;
    rpg->vilain->attack3 = 0;
    rpg->vilain->attack4 = 0;
    rpg->vilain->attack5 = 0;
    rpg->vilain->status1 = 1;
    rpg->vilain->status2 = 1;
    rpg->vilain->status3 = 1;
    rpg->vilain->status4 = 1;
    rpg->vilain->status5 = 1;
}

void set_texture_vilain(rpg_t *rpg, sfTexture *texture)
{
    rpg->vilain->vilain_rect1 = create_rect(193, 242, 45, 45);
    rpg->vilain->vilain_rect2 = create_rect(193, 242, 45, 45);
    rpg->vilain->vilain_rect3 = create_rect(193, 242, 45, 45);
    rpg->vilain->vilain_rect4 = create_rect(193, 480, 47, 48);
    rpg->vilain->vilain_rect5 = create_rect(193, 480, 47, 48);
    sfSprite_setTexture(rpg->vilain->vilain1, texture, sfTrue);
    sfSprite_setTexture(rpg->vilain->vilain2, texture, sfTrue);
    sfSprite_setTexture(rpg->vilain->vilain3, texture, sfTrue);
    sfSprite_setTexture(rpg->vilain->vilain4, texture, sfTrue);
    sfSprite_setTexture(rpg->vilain->vilain5, texture, sfTrue);
    sfSprite_setTextureRect(rpg->vilain->vilain1, rpg->vilain->vilain_rect1);
    sfSprite_setTextureRect(rpg->vilain->vilain2, rpg->vilain->vilain_rect2);
    sfSprite_setTextureRect(rpg->vilain->vilain3, rpg->vilain->vilain_rect3);
    sfSprite_setTextureRect(rpg->vilain->vilain4, rpg->vilain->vilain_rect4);
    sfSprite_setTextureRect(rpg->vilain->vilain5, rpg->vilain->vilain_rect5);
}

void set_data_sprite(rpg_t *rpg)
{
    sfSprite_setScale(rpg->vilain->vilain1, (sfVector2f) {3, 3});
    sfSprite_setScale(rpg->vilain->vilain2, (sfVector2f) {3, 3});
    sfSprite_setScale(rpg->vilain->vilain3, (sfVector2f) {3, 3});
    sfSprite_setScale(rpg->vilain->vilain4, (sfVector2f) {3, 3});
    sfSprite_setScale(rpg->vilain->vilain5, (sfVector2f) {3, 3});
    sfSprite_setPosition(rpg->vilain->vilain1, rpg->vilain->vilain1_pos);
    sfSprite_setPosition(rpg->vilain->vilain2, rpg->vilain->vilain2_pos);
    sfSprite_setPosition(rpg->vilain->vilain3, rpg->vilain->vilain3_pos);
    sfSprite_setPosition(rpg->vilain->vilain4, rpg->vilain->vilain4_pos);
    sfSprite_setPosition(rpg->vilain->vilain5, rpg->vilain->vilain5_pos);
}

int init_vilain(rpg_t *rpg)
{
    sfTexture *texture = sfTexture_createFromFile("assets/perso/boss.png",
    NULL);

    if (!texture)
        return 1;
    set_stat(rpg);
    rpg->vilain->vilain1 = sfSprite_create();
    rpg->vilain->vilain1_pos = (sfVector2f) {4620, 2350};
    rpg->vilain->vilain2 = sfSprite_create();
    rpg->vilain->vilain2_pos = (sfVector2f) {4620, 4850};
    rpg->vilain->vilain3 = sfSprite_create();
    rpg->vilain->vilain3_pos = (sfVector2f) {1320, 6850};
    rpg->vilain->vilain4 = sfSprite_create();
    rpg->vilain->vilain4_pos = (sfVector2f) {2320, 4850};
    rpg->vilain->vilain5 = sfSprite_create();
    rpg->vilain->vilain5_pos = (sfVector2f) {850, 5150};
    set_data_sprite(rpg);
    set_texture_vilain(rpg, texture);
    return (0);
}
