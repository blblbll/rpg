/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack_no_weapon
*/

#include "rpg.h"

void which_mob(rpg_t *rpg)
{
    hit_vilains(rpg, 1);
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
    attack_step_ready(1);
    attack_val(1);
}

void attack_no_weapon(rpg_t *rpg, int fire)
{
    if (fire && rpg->player->direction != 0 && attack_val(0) <= 0) {
        attack_condition(rpg);
        if (player_attack_boss(rpg) == 1) {
            rpg->boss->attack = 1;
            sfSprite_setColor(rpg->boss->boss, sfWhite);
        }
        which_mob(rpg);
    }
    player_attack_two(rpg);
}
