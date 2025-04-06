/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** third_chest
*/

#include "rpg.h"

int open_third_chest(rpg_t *rpg, int l)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){5050, 4300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue);
        l = 1;
    }
    return (l);
}

void third_chest(rpg_t *rpg)
{
    static int l = 0;
    if (rpg->player->player_pos.x >= 4700 && rpg->player->player_pos.x <= 4900
    && rpg->player->player_pos.y >= 4450 && rpg->player->player_pos.y <= 4570
    && l == 0) {
        l = open_third_chest(rpg, l);
    }
    if (l == 1) {
        rpg->player->rect_chest.left = 460;
    } else
        rpg->player->rect_chest.left = 250;
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){5150, 4500});
    sfSprite_setRotation(rpg->player->coffre, 90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
    four_chest(rpg);
}
