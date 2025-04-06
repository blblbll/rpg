/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init player and sword sprite
*/

#include "rpg.h"

int init_sword(rpg_t *rpg)
{
    sfTexture *texture = sfTexture_createFromFile("assets/perso/sword2.png",
    NULL);
    sfVector2f s_pos = {3000, 6500};
    sfIntRect rect = create_rect(1300, 553, 30, 60);

    if (!texture)
        return 1;
    rpg->player->sword = sfSprite_create();
    sfSprite_setTexture(rpg->player->sword, texture, sfTrue);
    sfSprite_setScale(rpg->player->sword, (sfVector2f) {3.25, 3.25});
    sfSprite_setPosition(rpg->player->sword, s_pos);
    sfSprite_setTextureRect(rpg->player->sword, rect);
    return 0;
}

int ini_pnj(rpg_t *rpg)
{
    rpg->pnj_a->pnj = create_sprite("assets/perso/pnj.png");

    if (!rpg->pnj_a->pnj)
        return 1;
    rpg->pnj_a->pnj_rect = create_rect(0, 700, 64 , 64);
    rpg->pnj_a->pnj_pos = (sfVector2f) {1720, 6150};
    sfSprite_setScale(rpg->pnj_a->pnj, (sfVector2f) {3.2, 3.2});
    sfSprite_setPosition(rpg->pnj_a->pnj, rpg->pnj_a->pnj_pos);
    sfSprite_setTextureRect(rpg->pnj_a->pnj, rpg->pnj_a->pnj_rect);
    rpg->pnj_a->clock_pnj = sfClock_create();
    rpg->pnj_a->pnj__dialog = 0;
    rpg->pnj_a->mouv_un = 0;
    rpg->pnj_a->mouv_deux = 0;
    rpg->pnj_a->interact = 0;
    rpg->player->vie = 375;
    rpg->player->sword1 = 0;
    rpg->player->sword2 = 0;
    return 0;
}

int init_xp(rpg_t *rpg)
{
    rpg->player->xp = create_sprite("assets/sprite/xp_bar.png");

    if (!rpg->player->xp)
        return 1;
    rpg->player->xp_rect = create_rect(0, 0, 620, 170);
    rpg->player->xp_pos = (sfVector2f) {t_static(0, rpg), t2_static(0, rpg)};
    sfSprite_setScale(rpg->player->xp, (sfVector2f) {0.3, 0.3});
    sfSprite_setPosition(rpg->player->xp, rpg->player->xp_pos);
    return 0;
}

int init_player(rpg_t *rpg)
{
    sfTexture *texture = sfTexture_createFromFile("assets/perso/Perso1.png",
    NULL);
    rpg->player->life = create_sprite("assets/sprite/life.png");
    if (!texture || !rpg->player->life)
        return 1;
    rpg->player->vitesse = 30;
    rpg->player->attack_id = 0;
    rpg->player->attack = 1;
    rpg->player->player = sfSprite_create();
    rpg->player->player_rect = create_rect(900, 64, 50, 63);
    rpg->player->player_pos = (sfVector2f) {t_static(780, rpg),
    t2_static(540, rpg)};
    rpg->player->inv = init_inv();
    sfSprite_setTexture(rpg->player->player, texture, sfTrue);
    sfSprite_setScale(rpg->player->player, (sfVector2f) {3.25, 3.25});
    sfSprite_setPosition(rpg->player->player, rpg->player->player_pos);
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
    if (ini_pnj(rpg) == 1 || init_xp(rpg) == 1)
        return 1;
    return 0;
}
