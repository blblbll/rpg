/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** attack for player
*/

#include "rpg.h"

sfFloatRect attack_zone(rpg_t *rpg)
{
    sfVector2f pos = rpg->player->player_pos;
    int reach = rpg->player->weapon == 1 ? 120 : 60;
    sfFloatRect body = {pos.x + 50, pos.y + 20, 90, 170};

    if (rpg->player->direction == 1)
        return ((sfFloatRect){body.left - 30, body.top - reach,
        body.width + 60, reach + body.height / 2});
    if (rpg->player->direction == 2)
        return ((sfFloatRect){body.left + body.width / 2, body.top - 20,
        body.width / 2 + reach, body.height + 40});
    if (rpg->player->direction == 4)
        return ((sfFloatRect){body.left - reach, body.top - 20,
        reach + body.width / 2, body.height + 40});
    return ((sfFloatRect){body.left - 30, body.top + body.height / 2,
    body.width + 60, body.height / 2 + reach});
}

int damage_for(int attack, int mode)
{
    if (mode == 2)
        return (4 + attack / 2);
    return (2 + attack / 4);
}

int player_damage(rpg_t *rpg, int mode)
{
    return (damage_for(rpg->player->attack, mode));
}

int hit_sprite(rpg_t *rpg, sfSprite *sprite)
{
    sfFloatRect zone = attack_zone(rpg);
    sfFloatRect box = sfSprite_getGlobalBounds(sprite);

    return (sfFloatRect_intersects(&zone, &box, NULL));
}

void player_attack(rpg_t *rpg)
{
    static int was_pressed = 0;
    int pressed = sfKeyboard_isKeyPressed(sfKeySpace) &&
    sfRenderWindow_hasFocus(rpg->windo->window);
    int fire = pressed && !was_pressed;
    int we = rpg->player->weapon;

    was_pressed = pressed;
    if (rpg->page != 1 || in_dialog(rpg))
        return;
    if (we == 0)
        attack_no_weapon(rpg, fire);
    if (we == 1)
        attack_with_weapon(rpg, fire);
}
