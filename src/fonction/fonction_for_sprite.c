/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** fonction for declare sprite and text
*/

#include "rpg.h"

sfSprite *create_sprite(char *path)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (!texture)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfText *generate_text(char *text_str, sfVector2f pos, int size, sfColor co)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/Seagramtfb.ttf");

    if (!font)
        return NULL;
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, co);
    sfText_setPosition(text, pos);
    sfText_setString(text, text_str);
    sfFont_destroy(font);
    return text;
}
