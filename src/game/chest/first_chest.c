/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** first chest in map
*/

#include "rpg.h"

void open_chest(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){4160, 7120});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE)) {
        key_consume(sfKeyE);
        rpg->player->chest = 1;
    }
}

void add_sword_to_inv(rpg_t *rpg, sfSprite *sword)
{
    for (int i = 0; i < INV_SIZE; i++) {
        if (rpg->player->inv->list_item[i]->empty == 1) {
            rpg->player->inv->list_item[i]->empty = 0;
            rpg->player->inv->list_item[i]->name = "Longue epee";
            rpg->player->inv->list_item[i]->description =
            "Longue epee permettant de tuer\nles monstres plus vite.";
            sfSprite_scale(sword, (sfVector2f) {0.70, 0.70});
            rpg->player->inv->list_item[i]->sprite = sword;
            break;
        }
    }
}

void recup_sword(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){4060, 7120});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE) && has_free_slot(rpg)) {
        rpg->player->chest = 2;
        rpg->player->weapon = 1;
        rpg->player->attack += 1;
        rpg->player->player = create_sprite("assets/perso/sword1.png");
        sfSprite_setPosition(rpg->player->player,
        (sfVector2f){rpg->player->player_pos.x, rpg->player->player_pos.y});
        rpg->player->player_rect = (sfIntRect){0, 0, 66, 61};
        sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
        sfSprite_setScale(rpg->player->player, (sfVector2f) {3.25, 3.25});
        add_sword_to_inv(rpg, rpg->player->sword);
    }
}

void sprite_first(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){4560, 6920});
    sfSprite_setRotation(rpg->player->coffre, 90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
}

void first_chest(rpg_t *rpg)
{
    if (rpg->player->player_pos.x >= 4155 && rpg->player->player_pos.x <= 4270
    && rpg->player->player_pos.y >= 6850 && rpg->player->player_pos.y <= 7000
    && rpg->player->chest == 0)
        open_chest(rpg);
    if (rpg->player->player_pos.x >= 4070 && rpg->player->player_pos.x <= 4220
    && rpg->player->player_pos.y >= 6850 && rpg->player->player_pos.y <= 7000
    && rpg->player->chest == 1)
        recup_sword(rpg);
    if (rpg->player->chest == 1) {
        rpg->player->rect_chest.left = 460;
        sfSprite_setPosition(rpg->player->sword, (sfVector2f){4260, 6920});
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->sword,NULL);
    } if (rpg->player->chest == 2)
        rpg->player->rect_chest.left = 460;
    else
        rpg->player->rect_chest.left = 250;
    sprite_first(rpg);
    second_chest(rpg);
}
