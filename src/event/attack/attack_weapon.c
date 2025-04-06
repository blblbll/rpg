/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack_weapon
*/

#include "rpg.h"

int attack_val(int nb)
{
    static int attack = 0;

    if (nb != 0)
        attack = nb;
    return (attack);
}

void attack_rect_position(rpg_t *rpg)
{
    rpg->player->player_rect.width = 64;
    rpg->player->player_rect.left = 64;
    if (rpg->player->direction == 1)
        rpg->player->player_rect.top = 520;
    if (rpg->player->direction == 2)
        rpg->player->player_rect.top = 717;
    if (rpg->player->direction == 3 || rpg->player->direction == 0)
        rpg->player->player_rect.top = 650;
    if (rpg->player->direction == 4)
        rpg->player->player_rect.top = 590;
}

void player_attack_two_w(rpg_t *rpg)
{
    if (attack_val(0) >= 1 && attack_val(0) < 7) {
        if (rpg->player->direction == 1)
            rpg->player->player_rect.top = 1885;
        if (rpg->player->direction == 2)
            rpg->player->player_rect.top = 2275;
        if (rpg->player->direction == 3 || rpg->player->direction == 0)
            rpg->player->player_rect.top = 2158;
        if (rpg->player->direction == 4)
            rpg->player->player_rect.top = 2025;
        rpg->player->player_rect.width = 64;
        rpg->player->attack_id = 1;
        attack_id(rpg);
        sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
    }
    if (attack_val(0) >= 7) {
        attack_val(-1);
        attack_rect_position(rpg);
    }
}

void attack_condition_w(rpg_t *rpg)
{
    sfVector2f pos2 = {rpg->player->player_pos.x, rpg->player->player_pos.y};

    if (rpg->player->direction == 1) {
        rpg->player->player_rect.left = 30;
        pos2.y -= 50;
    }
    if (rpg->player->direction == 2) {
        rpg->player->player_rect.left = 50;
        pos2.y -= 30;
        pos2.x += 52;
    }
    if (rpg->player->direction == 3)
        rpg->player->player_rect.left = 30;
    if (rpg->player->direction == 4) {
        rpg->player->player_rect.left = 10;
        pos2.x -= 52;
        pos2.y -= 14;
    }
    sfSprite_setPosition(rpg->player->player, pos2);
    attack_val(1);
}

void attack_with_weapon(rpg_t *rpg)
{
    if ((sfKeyboard_isKeyPressed(sfKeySpace)) && rpg->player->direction != 0) {
        while (sfKeyboard_isKeyPressed(sfKeySpace));
        if (attack_val(0) <= 0 || attack_val(0) >= 7) {
            attack_condition_w(rpg);
        }
        if (player_attack_boss(rpg) == 1) {
            rpg->boss->attack = 2;
            sfSprite_setColor(rpg->boss->boss, sfWhite);
        }
        which_mob2(rpg);
        sfSound_setVolume(rpg->sound->sound_sword, rpg->sound->volume / 2);
        sfSound_play(rpg->sound->sound_sword);
    }
    player_attack_two_w(rpg);
}
