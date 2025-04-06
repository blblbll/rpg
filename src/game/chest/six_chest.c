/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** six_chest
*/

#include "rpg.h"

int open_six_chest(rpg_t *rpg, int m)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){140, 1300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue);
        m = 1;
    }
    return (m);
}

void add_potion_inv(rpg_t *rpg)
{
    for (int i = 0; i < 4; i++) {
        if (rpg->player->inv->list_item[i]->empty == 1) {
            rpg->player->inv->list_item[i]->empty = 0;
            rpg->player->inv->list_item[i]->sprite = rpg->player->life_potion;
            rpg->player->inv->list_item[i]->name = "Life potion";
            rpg->player->inv->list_item[i]->description =
            "Heal the character life's bar.";
            break;
        }
    }
}

int recup_potion_vie(rpg_t *rpg, int m)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){340, 1300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue);
        m = 2;
        rpg->player->potion_have = 1;
        add_potion_inv(rpg);
    }
    return m;
}

void spite_six(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){160, 1400});
    sfSprite_setRotation(rpg->player->coffre, -90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
}

void six_chest(rpg_t *rpg)
{
    static int m = 0;
    if (rpg->player->player_pos.x >= 140 && rpg->player->player_pos.x <= 380
    && rpg->player->player_pos.y >= 1220 && rpg->player->player_pos.y <= 1380
    && m == 0)
        m = open_six_chest(rpg, m);
    if (rpg->player->player_pos.x >= 300 && rpg->player->player_pos.x <= 500
    && rpg->player->player_pos.y >= 1220 && rpg->player->player_pos.y <= 1500
    && m == 1)
        m = recup_potion_vie(rpg, m);
    if (m == 1) {
        rpg->player->rect_chest.left = 460;
        sfSprite_setPosition(rpg->player->life_potion, (sfVector2f){450,1300});
        sfSprite_setScale(rpg->player->life_potion, (sfVector2f){0.1, 0.1});
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->life_potion,
        NULL);
    } else if (m == 2)
        rpg->player->rect_chest.left = 460;
    else
        rpg->player->rect_chest.left = 250;
    spite_six(rpg);
}
