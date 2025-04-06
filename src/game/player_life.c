/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** gestion life of player
*/

#include "rpg.h"

int if_anyone_attack(rpg_t *rpg)
{
    if (boss_attack(rpg) == 1)
        return (1);
    if (vilain_attack(rpg, rpg->vilain->vilain1,
    rpg->vilain->status1) == 1)
        return (1);
    if (vilain_attack(rpg, rpg->vilain->vilain2,
    rpg->vilain->status2) == 1)
        return (1);
    if (vilain_attack(rpg, rpg->vilain->vilain3,
    rpg->vilain->status3) == 1)
        return (1);
    if (vilain_attack(rpg, rpg->vilain->vilain4,
    rpg->vilain->status4) == 1)
        return (1);
    if (vilain_attack(rpg, rpg->vilain->vilain5,
    rpg->vilain->status5) == 1)
        return (1);
    return (0);
}

int dev_fonction_game(int quantity_of_life, rpg_t *rpg)
{
    if (if_anyone_attack(rpg) == 1) {
        quantity_of_life = 1;
        rpg->player->vie = rpg->player->vie - 1;
    }
    return quantity_of_life;
}

void move_rect_life(rpg_t *rpg, int offset, int max_value)
{
    rpg->player->life_rect.top = rpg->player->life_rect.top + offset;
    if (rpg->player->life_rect.top >= max_value) {
        rpg->player->life_rect.top = 0;
        rpg->player->vie = 5;
    }
}

void display_xp(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->player->xp, (sfVector2f){t_static(40, rpg) -
    (rpg->zoom * 1920 / 2 - 1920 / 2),
    t2_static(130, rpg) - (rpg->zoom * 1080 / 2.5 - 1080 / 2.5)});
    sfSprite_setScale(rpg->player->xp, (sfVector2f){rpg->zoom / 2.5,
    rpg->zoom / 2.5});
    if (rpg->player->attack >= 6)
        rpg->player->xp_rect.top = 184 * 5;
    else
        rpg->player->xp_rect.top = 185 * (rpg->player->attack - 1);
    sfSprite_setTextureRect(rpg->player->xp, rpg->player->xp_rect);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->xp, NULL);
}

void display_life(rpg_t *rpg)
{
    int quantity_of_life = 0;

    if (!rpg->player->life)
        return;
    sfSprite_setPosition(rpg->player->life, (sfVector2f){t_static(10, rpg) -
    (rpg->zoom * 1920 / 2 - 1920 / 2),
    t2_static(10, rpg) - (rpg->zoom * 1080 / 2 - 1080 / 2)});
    sfSprite_setScale(rpg->player->life, (sfVector2f){rpg->zoom, rpg->zoom});
    quantity_of_life = dev_fonction_game(quantity_of_life, rpg);
    if (rpg->player->vie % 75 == 0 && quantity_of_life == 1)
        move_rect_life(rpg, 116, 500);
    quantity_of_life = 0;
    sfSprite_setTextureRect(rpg->player->life, rpg->player->life_rect);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->life, NULL);
    display_xp(rpg);
}
