/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** second_chest
*/

#include "rpg.h"

int open_second_chest(rpg_t *rpg, int m)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){1557, 2300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE)) {
        key_consume(sfKeyE);
        m = 1;
    }
    return (m);
}

int recup_apple(rpg_t *rpg, int m)
{
    sfSprite_setPosition(rpg->player->interact, (sfVector2f){1740, 2300});
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact, NULL);
    if (key_just_pressed(sfKeyE) && has_free_slot(rpg)) {
        m = 2;
        give_item(rpg, "Pomme", "Rend un coeur.\nAppuyer sur E pour la manger.",
        rpg->player->apple);
    }
    return (m);
}

static int g_state = 0;

void reset_second_chest(void)
{
    g_state = 0;
}

void second_chest(rpg_t *rpg)
{
    int m = g_state;
    if (rpg->player->player_pos.x >= 1500 && rpg->player->player_pos.x <= 1610
    && rpg->player->player_pos.y >= 2360 && rpg->player->player_pos.y <= 2570
    && m == 0)
        m = open_second_chest(rpg, m);
    if (rpg->player->player_pos.x >= 1500 && rpg->player->player_pos.x <= 1760
    && rpg->player->player_pos.y >= 2360 && rpg->player->player_pos.y <= 2570
    && m == 1)
        m = recup_apple(rpg, m);
    if (m == 1) {
        rpg->player->rect_chest.left = 460;
        sfSprite_setPosition(rpg->player->apple, (sfVector2f){1740, 2440});
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->apple, NULL);
    } else if (m == 2)
        rpg->player->rect_chest.left = 460;
    else
        rpg->player->rect_chest.left = 250;
    sfSprite_setTextureRect(rpg->player->coffre, rpg->player->rect_chest);
    sfSprite_setPosition(rpg->player->coffre, (sfVector2f){1560, 2360});
    sfSprite_setRotation(rpg->player->coffre, 0);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->coffre, NULL);
    g_state = m;
    third_chest(rpg);
}
