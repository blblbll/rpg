/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_sprite
*/

#include "rpg.h"

int init_text_dialog(rpg_t *rpg)
{
    rpg->text_dialog = sfText_create();
    sfText_setString(rpg->text_dialog, "");
    sfText_setFont(rpg->text_dialog, sfFont_createFromFile
    ("assets/font/Cardinal.ttf"));

    if (!rpg->text_dialog)
        return 1;
    sfText_setCharacterSize(rpg->text_dialog, 60);
    sfText_setColor(rpg->text_dialog, sfWhite);
    rpg->message = "P to pass A to unzoom Z to zoom\n\
E to up the sound  R to down the sound C reduct life";
    return 0;
}

int init_dialog(rpg_t *rpg)
{
    rpg->dialog = create_sprite("assets/sprite/dialog.png");
    rpg->effect->rect = sfRectangleShape_create();
    rpg->effect->circle = sfCircleShape_create();

    if (!rpg->dialog || !rpg->effect->rect || !rpg->effect->circle)
        return 1;
    init_text_dialog(rpg);
    rpg->dialog_pass = 0;
    rpg->defil = 0;
    rpg->dialog_sound = 0;
    return 0;
}

int init_sprite(rpg_t *rpg)
{
    rpg->player->interact = create_sprite("assets/sprite/interact.png");
    rpg->player->coffre = create_sprite("assets/sprite/chest.png");
    rpg->font = create_sprite("assets/map/Fonts.jpg");
    rpg->player->key = create_sprite("assets/sprite/key.png");
    sfSprite_setTextureRect(rpg->player->key, (sfIntRect) {58, 0, 200, 200});
    if (!rpg->player->interact || !rpg->player->coffre || !rpg->font ||
        !rpg->player->key)
        return 1;
    rpg->player->life_rect = create_rect(0, 0, 350, 100);
    rpg->player->rect_chest = create_rect(0, 250, 200, 300);
    sfSprite_setScale(rpg->player->interact, (sfVector2f){0.3, 0.3});
    rpg->player->chest = 0;
    sfSprite_setScale(rpg->player->coffre, (sfVector2f){0.7, 0.7});
    sfSprite_setScale(rpg->player->key, (sfVector2f){0.7, 0.7});
    rpg->option = 0;
    rpg->player->have_key = 0;
    return 0;
}

int font_floue(rpg_t *rpg)
{
    rpg->font_floue = create_sprite("assets/map/Fonts_floue.jpg");
    rpg->player->life_potion = create_sprite("assets/sprite/life_potion.png");

    if (!rpg->font_floue || !rpg->player->life_potion)
        return 1;
    rpg->effect->door_open = 0;
    rpg->player->potion_have = 0;
    return 0;
}

int init_collision_image(rpg_t *rpg)
{
    rpg->image_font = sfImage_createFromFile
    ("assets/map/Fonts_colision.jpg");

    if (!rpg->image_font)
        return 1;
    return 0;
}
