/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** four_chest
*/

#include "rpg.h"

int open_four_chest(rpg_t *rpg, int i)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){5200, 1730});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE)) {
        key_consume(sfKeyE);
        i = 1;
    }
    return (i);
}

void add_key_to_inv(rpg_t *rpg)
{
    for (int i = 0; i < INV_SIZE; i++) {
        if (rpg->player->inv->list_item[i]->empty == 1) {
            rpg->player->inv->list_item[i]->empty = 0;
            rpg->player->inv->list_item[i]->name = "Cle";
            rpg->player->inv->list_item[i]->description =
            "Cette cle vous donne acces a la salle du boss.";
            rpg->player->inv->list_item[i]->sprite = rpg->player->key;
            break;
        }
    }
}

int recup_key(rpg_t *rpg, int i)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){5000, 1730});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE) && has_free_slot(rpg)) {
        i = 2;
        rpg->player->have_key = 1;
        add_key_to_inv(rpg);
    }
    return (i);
}

void sprite_fout(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){5370, 1800});
    sfSprite_setRotation(rpg->player->coffre, 90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
}

static int g_state = 0;

void reset_four_chest(void)
{
    g_state = 0;
}

void four_chest(rpg_t *rpg)
{
    int i = g_state;
    if (rpg->player->player_pos.x >= 4950 && rpg->player->player_pos.x <= 5200
    && rpg->player->player_pos.y >= 1720 && rpg->player->player_pos.y <= 1920
    && i == 0)
        i = open_four_chest(rpg, i);
    if (rpg->player->player_pos.x >= 4850 && rpg->player->player_pos.x <= 5100
    && rpg->player->player_pos.y >= 1720 &&
    rpg->player->player_pos.y <= 1920 && i == 1)
        i = recup_key(rpg, i);
    if (i == 1) {
        rpg->player->rect_chest.left = 460;
        sfSprite_setPosition(rpg->player->key, (sfVector2f){5000, 1800});
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->key, NULL);
    } if (i == 2)
        rpg->player->rect_chest.left = 460;
    else
        rpg->player->rect_chest.left = 250;
    sprite_fout(rpg);
    g_state = i;
    fith_chest(rpg);
}
