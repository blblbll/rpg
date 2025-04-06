/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** option_window
*/

#include "rpg.h"

void select_slot(rpg_t *rpg, int indice)
{
    rpg->player->inv->hand = indice;
    for (int i = 0; i < 4; i++) {
        if (i == indice)
            sfRectangleShape_setOutlineColor
            (rpg->player->inv->list_item[i]->square, sfRed);
        else
            sfRectangleShape_setOutlineColor
            (rpg->player->inv->list_item[i]->square, sfBlack);
    }
}

void display_slot(rpg_t *rpg, sfVector2f edd)
{
    int a = -285;
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_setPosition(rpg->player->inv->list_item[i]->square,
        (sfVector2f) {edd.x + a, edd.y + 20});
        sfText_setString(rpg->player->text, rpg->player->inv->
        list_item[i]->input);
        sfText_setPosition(rpg->player->text, (sfVector2f)
        {edd.x + a + 35, edd.y + 115});
        if (rpg->player->inv->list_item[i]->empty == 0) {
            sfSprite_setPosition(rpg->player->inv->list_item[i]->sprite,
            (sfVector2f) {edd.x + a + 20 , edd.y + 25});
            sfRenderWindow_drawSprite(rpg->windo->window,
            rpg->player->inv->list_item[i]->sprite, NULL);
        }
        sfRenderWindow_drawRectangleShape(rpg->windo->window,
        rpg->player->inv->list_item[i]->square, NULL);
        sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
        a = a + 150;
    }
}
