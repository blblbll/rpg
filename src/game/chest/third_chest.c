/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** third_chest
*/

#include "rpg.h"

int open_third_chest(rpg_t *rpg, int m)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){5050, 4300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE)) {
        key_consume(sfKeyE);
        m = 1;
    }
    return (m);
}

int recup_gem(rpg_t *rpg, int m)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){4850, 4300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE) && has_free_slot(rpg)) {
        m = 2;
        give_item(rpg, "Gemme d'experience",
        "Donne un niveau.\nAppuyer sur E pour l'utiliser.",
        rpg->player->gem);
    }
    return (m);
}

static int g_state = 0;

void reset_third_chest(void)
{
    g_state = 0;
}

void third_chest(rpg_t *rpg)
{
    int m = g_state;
    if (rpg->player->player_pos.x >= 4700 && rpg->player->player_pos.x <= 4900
    && rpg->player->player_pos.y >= 4450 && rpg->player->player_pos.y <= 4570
    && m == 0)
        m = open_third_chest(rpg, m);
    if (rpg->player->player_pos.x >= 4600 && rpg->player->player_pos.x <= 4900
    && rpg->player->player_pos.y >= 4450 && rpg->player->player_pos.y <= 4570
    && m == 1)
        m = recup_gem(rpg, m);
    if (m == 1) {
        rpg->player->rect_chest.left = 460;
        sfSprite_setPosition(rpg->player->gem, (sfVector2f){4790, 4520});
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->gem, NULL);
    } else if (m == 2)
        rpg->player->rect_chest.left = 460;
    else
        rpg->player->rect_chest.left = 250;
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){5150, 4500});
    sfSprite_setRotation(rpg->player->coffre, 90);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
    g_state = m;
    four_chest(rpg);
}
