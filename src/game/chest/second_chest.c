/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** second_chest
*/

#include "rpg.h"

int open_second_chest(rpg_t *rpg, int m)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){1557, 2300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue);
        m = 1;
    }
    return (m);
}

void second_chest(rpg_t *rpg)
{
    static int m = 0;
    if (rpg->player->player_pos.x >= 1500 && rpg->player->player_pos.x <= 1610
    && rpg->player->player_pos.y >= 2360 && rpg->player->player_pos.y <= 2570
    && m == 0) {
        m = open_second_chest(rpg, m);
    }
    if (m == 1) {
        rpg->player->rect_chest.left = 460;
    } else
        rpg->player->rect_chest.left = 250;
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){1560, 2360});
    sfSprite_setRotation(rpg->player->coffre, 0);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
    third_chest(rpg);
}
