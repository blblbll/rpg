/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** fith_chest
*/

#include "rpg.h"

int open_fith_chest(rpg_t *rpg, int o)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){1900, 4800});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue);
        o = 1;
    }
    return (o);
}

void fith_chest(rpg_t *rpg)
{
    static int o = 0;
    if (rpg->player->player_pos.x >= 1990 && rpg->player->player_pos.x <= 2200
    && rpg->player->player_pos.y >= 4700 && rpg->player->player_pos.y <= 5100
    && o == 0) {
        o = open_fith_chest(rpg, o);
    }
    if (o == 1) {
        rpg->player->rect_chest.left = 460;
    } else
        rpg->player->rect_chest.left = 250;
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){2040, 5000});
    sfSprite_setRotation(rpg->player->coffre, -90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
    six_chest(rpg);
}
