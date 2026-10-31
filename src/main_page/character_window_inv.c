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
    for (int i = 0; i < INV_SIZE; i++) {
        if (i == indice)
            sfRectangleShape_setOutlineColor
            (rpg->player->inv->list_item[i]->square, sfRed);
        else
            sfRectangleShape_setOutlineColor
            (rpg->player->inv->list_item[i]->square, sfBlack);
    }
}

static sfFloatRect scan_art(sfSprite *sprite)
{
    sfImage *img = sfTexture_copyToImage(sfSprite_getTexture(sprite));
    sfIntRect r = sfSprite_getTextureRect(sprite);
    int x1 = r.width;
    int y1 = r.height;
    int x2 = 0;
    int y2 = 0;
    sfVector2u size = sfImage_getSize(img);

    for (int y = 0; y < r.height; y++)
        for (int x = 0; x < r.width; x++) {
            if (r.left + x >= (int) size.x || r.top + y >= (int) size.y ||
            sfImage_getPixel(img, r.left + x, r.top + y).a < 30)
                continue;
            x1 = x < x1 ? x : x1;
            y1 = y < y1 ? y : y1;
            x2 = x > x2 ? x : x2;
            y2 = y > y2 ? y : y2;
        }
    sfImage_destroy(img);
    if (x2 < x1 || y2 < y1)
        return ((sfFloatRect){0, 0, r.width, r.height});
    return ((sfFloatRect){x1, y1, x2 - x1 + 1, y2 - y1 + 1});
}

static sfFloatRect art_box(sfSprite *sprite)
{
    static sfSprite *cache_key[16];
    static sfFloatRect cache_box[16];
    static int count = 0;

    for (int i = 0; i < count; i++)
        if (cache_key[i] == sprite)
            return (cache_box[i]);
    if (count == 16)
        return (scan_art(sprite));
    cache_key[count] = sprite;
    cache_box[count] = scan_art(sprite);
    return (cache_box[count++]);
}

void fit_sprite(sfSprite *sprite, sfVector2f center, float size)
{
    sfFloatRect box = art_box(sprite);
    float side = box.width > box.height ? box.width : box.height;
    float scale = size / side;

    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
    sfSprite_setPosition(sprite, (sfVector2f){center.x - (box.left +
    box.width / 2) * scale, center.y - (box.top + box.height / 2) * scale});
}

void display_slot(rpg_t *rpg, sfVector2f edd)
{
    int a = -425;
    sfVector2f old_scale;

    for (int i = 0; i < INV_SIZE; i++) {
        sfRectangleShape_setPosition(rpg->player->inv->list_item[i]->square,
        (sfVector2f) {edd.x + a, edd.y + 20});
        sfText_setString(rpg->player->text, rpg->player->inv->
        list_item[i]->input);
        sfText_setPosition(rpg->player->text, (sfVector2f)
        {edd.x + a + 35, edd.y + 115});
        if (rpg->player->inv->list_item[i]->empty == 0) {
            old_scale = sfSprite_getScale(rpg->player->inv->list_item[i]->sprite);
            fit_sprite(rpg->player->inv->list_item[i]->sprite,
            (sfVector2f) {edd.x + a + 50, edd.y + 70}, 70);
            sfRenderWindow_drawSprite(rpg->windo->window,
            rpg->player->inv->list_item[i]->sprite, NULL);
            sfSprite_setScale(rpg->player->inv->list_item[i]->sprite,
            old_scale);
        }
        sfRenderWindow_drawRectangleShape(rpg->windo->window,
        rpg->player->inv->list_item[i]->square, NULL);
        sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
        a = a + 150;
    }
}

static void consume_item(item_t *item)
{
    item->empty = 1;
    item->name = NULL;
    item->sprite = NULL;
    item->description = NULL;
}

void use_item(rpg_t *rpg)
{
    item_t *item = rpg->player->inv->list_item[rpg->player->inv->hand];

    if (item->empty == 1 || item->name == NULL)
        return;
    if (strcmp(item->name, "Life potion") == 0 && rpg->player->vie < 375) {
        rpg->player->vie = 375;
        rpg->player->life_rect.top = 0;
        rpg->player->potion_have = 0;
        consume_item(item);
    } else if (strcmp(item->name, "Potion de force") == 0) {
        rpg->player->attack += 2;
        consume_item(item);
    } else if (strcmp(item->name, "Pomme") == 0 && rpg->player->vie < 375) {
        rpg->player->vie = rpg->player->vie + 75 > 375 ? 375 :
        rpg->player->vie + 75;
        rpg->player->life_rect.top = 116 * ((375 - rpg->player->vie) / 75);
        consume_item(item);
    } else if (strcmp(item->name, "Gemme d'experience") == 0) {
        level_up(rpg);
        consume_item(item);
    }
}
