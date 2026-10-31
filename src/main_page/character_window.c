/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** option_window
*/

#include "rpg.h"

void display_description(rpg_t *rpg, sfVector2f edd)
{
    if (rpg->player->inv->list_item[rpg->player->inv->hand]->empty == 0) {
        sfText_setString(rpg->player->text, rpg->player->inv->list_item
        [rpg->player->inv->hand]->name);
        sfText_setPosition(rpg->player->text, (sfVector2f)
        {edd.x - 300, edd.y + 180});
        sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
        sfText_setString(rpg->player->text, rpg->player->inv->list_item
        [rpg->player->inv->hand]->description);
        sfText_setPosition(rpg->player->text, (sfVector2f)
        {edd.x - 200, edd.y + 280});
        sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    }
}

void display_inv(rpg_t *rpg, sfVector2f edd)
{
    display_slot(rpg, edd);
    if (sfKeyboard_isKeyPressed(sfKeyNum1) == sfTrue)
        select_slot(rpg, 0);
    if (sfKeyboard_isKeyPressed(sfKeyNum2) == sfTrue)
        select_slot(rpg, 1);
    if (sfKeyboard_isKeyPressed(sfKeyNum3) == sfTrue)
        select_slot(rpg, 2);
    if (sfKeyboard_isKeyPressed(sfKeyNum4) == sfTrue)
        select_slot(rpg, 3);
    if (sfKeyboard_isKeyPressed(sfKeyNum5) == sfTrue)
        select_slot(rpg, 4);
    if (sfKeyboard_isKeyPressed(sfKeyNum6) == sfTrue)
        select_slot(rpg, 5);
    if (key_just_pressed(sfKeyRight))
        select_slot(rpg, (rpg->player->inv->hand + 1) % INV_SIZE);
    if (key_just_pressed(sfKeyLeft))
        select_slot(rpg, (rpg->player->inv->hand + INV_SIZE - 1) % INV_SIZE);
    select_slot(rpg, rpg->player->inv->hand);
    if (key_just_pressed(sfKeyE))
        use_item(rpg);
    display_description(rpg, edd);
}

void display_life_stat(rpg_t *rpg, sfVector2f edd)
{
    sfText_setString(rpg->player->text, my_itoa(rpg->player->vitesse));
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x, edd.y - 180});
    sfText_setCharacterSize(rpg->player->text, 50);
    sfText_setColor(rpg->player->text, sfWhite);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    sfText_setString(rpg->player->text,  "Life:");
    sfText_setPosition(rpg->player->text, (sfVector2f) {edd.x - 220, edd.y -
    80});
    sfText_setCharacterSize(rpg->player->text, 50);
    sfText_setColor(rpg->player->text, sfBlue);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    sfText_setString(rpg->player->text,  my_itoa(rpg->player->vie / 75));
    sfText_setPosition(rpg->player->text, (sfVector2f) {edd.x, edd.y - 80});
    sfText_setCharacterSize(rpg->player->text, 50);
    sfText_setColor(rpg->player->text, sfWhite);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void display_stats(rpg_t *rpg, sfVector2f edd)
{
    sfText_setString(rpg->player->text,  "Attack:");
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 220, edd.y -
    280});
    sfText_setCharacterSize(rpg->player->text, 50);
    sfText_setColor(rpg->player->text, sfBlue);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    sfText_setString(rpg->player->text,  my_itoa(rpg->player->attack));
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x, edd.y - 280});
    sfText_setCharacterSize(rpg->player->text, 50);
    sfText_setColor(rpg->player->text, sfWhite);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    sfText_setString(rpg->player->text,  "Speed:");
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 220, edd.y -
    180});
    sfText_setCharacterSize(rpg->player->text, 50);
    sfText_setColor(rpg->player->text, sfBlue);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    display_life_stat(rpg, edd);
}

void character_window(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    sfIntRect i = create_rect(900, 0, 50, 63);

    sfRenderWindow_clear(rpg->windo->window, sfColor_fromRGB(41, 45, 54));
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->font_floue, NULL);
    sfSprite_setTextureRect(rpg->player->player, i);
    sfSprite_setPosition(rpg->player->player, (sfVector2f){edd.x - 110, edd.y -
    540});
    sfSprite_setScale(rpg->player->player, (sfVector2f) {3.25, 3.25});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->player, NULL);
    display_stats(rpg, edd);
    display_inv(rpg, edd);
    sfRenderWindow_display(rpg->windo->window);
    set_view(rpg, rpg->player->player_pos, 0);
    if (key_just_pressed(sfKeyI)) {
        key_consume(sfKeyI);
        rpg->page = 1;
    }
    sfSprite_setPosition(rpg->player->player, (sfVector2f)
    {rpg->player->player_pos.x, rpg->player->player_pos.y});
}
