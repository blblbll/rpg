/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack_no_weapon
*/

#include "rpg.h"

void which_mob(rpg_t *rpg)
{
    if (player_attack_vilain(rpg) == 1 && rpg->vilain->status1 != 0) {
        rpg->vilain->attack1 = 1;
        sfSprite_setColor(rpg->vilain->vilain1, sfWhite);
    }
    if (player_attack_vilain(rpg) == 2 && rpg->vilain->status2 != 0) {
        rpg->vilain->attack2 = 1;
        sfSprite_setColor(rpg->vilain->vilain2, sfWhite);
    }
    if (player_attack_vilain(rpg) == 3 && rpg->vilain->status3 != 0) {
        rpg->vilain->attack3 = 1;
        sfSprite_setColor(rpg->vilain->vilain3, sfWhite);
    }
    if (player_attack_vilain(rpg) == 4 && rpg->vilain->status4 != 0) {
        rpg->vilain->attack4 = 1;
        sfSprite_setColor(rpg->vilain->vilain4, sfWhite);
    }
    if (player_attack_vilain(rpg) == 5 && rpg->vilain->status5 != 0) {
        rpg->vilain->attack5 = 1;
        sfSprite_setColor(rpg->vilain->vilain5, sfWhite);
    }
}

void player_attack_two(rpg_t *rpg)
{
    if (attack_val(0) >= 1 && attack_val(0) < 7) {
        if (rpg->player->direction == 1)
            rpg->player->player_rect.top = 780;
        if (rpg->player->direction == 2)
            rpg->player->player_rect.top = 969;
        if (rpg->player->direction == 3 || rpg->player->direction == 0)
            rpg->player->player_rect.top = 905;
        if (rpg->player->direction == 4)
            rpg->player->player_rect.top = 845;
        rpg->player->player_rect.width = 64;
        rpg->player->attack_id = 1;
        attack_id_no_w(rpg);
        sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
    }
    if (attack_val(0) >= 7) {
        attack_val(-1);
    }
}

void attack_condition(rpg_t *rpg)
{
    sfVector2f pos2 = {rpg->player->player_pos.x, rpg->player->player_pos.y};
    rpg->player->player_rect.left = 0;
    sfSprite_setPosition(rpg->player->player, pos2);
    attack_val(1);
}

void attack_no_weapon(rpg_t *rpg)
{
    if ((sfKeyboard_isKeyPressed(sfKeySpace)) && rpg->player->direction != 0) {
        while (sfKeyboard_isKeyPressed(sfKeySpace));
        if (attack_val(0) <= 0 || attack_val(0) >= 7) {
            attack_condition(rpg);
        }
        if (player_attack_boss(rpg) == 1) {
            rpg->boss->attack = 1;
            sfSprite_setColor(rpg->boss->boss, sfWhite);
        }
        which_mob(rpg);
    }
    player_attack_two(rpg);
}
