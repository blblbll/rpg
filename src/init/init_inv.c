/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init player and sword sprite
*/

#include "rpg.h"

item_t *create_item_empty(char *input)
{
    item_t *item = malloc(sizeof(item_t));
    item->description = NULL;
    item->empty = 1;
    item->input = input;
    item->name = NULL;
    item->sprite = NULL;
    item->square = sfRectangleShape_create();
    sfRectangleShape_setSize(item->square, (sfVector2f) {100, 100});
    sfRectangleShape_setOutlineColor (item->square, sfBlack);
    sfRectangleShape_setFillColor(item->square, sfTransparent);
    sfRectangleShape_setOutlineThickness (item->square, 5.0);
    return item;
}

inventaire_t *init_inv(void)
{
    inventaire_t *inv = malloc(sizeof(inventaire_t));
    inv->hand = 0;

    inv->list_item = malloc(sizeof(item_t) * 4);
    inv->list_item[0] = create_item_empty("1");
    inv->list_item[1] = create_item_empty("2");
    inv->list_item[2] = create_item_empty("3");
    inv->list_item[3] = create_item_empty("4");
    sfRectangleShape_setOutlineColor(inv->list_item[0]->square, sfRed);
    return inv;
}
