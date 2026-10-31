/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"

int touch_player(rpg_t *rpg, sfSprite *sprite, float margin)
{
    sfVector2f pos = rpg->player->player_pos;
    sfFloatRect body = {pos.x + 50, pos.y + 20, 90, 170};
    sfFloatRect box = sfSprite_getGlobalBounds(sprite);

    box.left -= margin;
    box.top -= margin;
    box.width += 2 * margin;
    box.height += 2 * margin;
    return (sfFloatRect_intersects(&body, &box, NULL));
}

int boss_attack(rpg_t *rpg)
{
    if (rpg->boss->status != 0 && touch_player(rpg, rpg->boss->boss, 10))
        return (1);
    return (0);
}
