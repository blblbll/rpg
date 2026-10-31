/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pnj
*/

#include "rpg.h"

void text_un(rpg_t *rpg)
{
    sfText_setString(rpg->text_dialog, "Bienvenue a toi cher aventurier "
    "dans ce donjon.\n"
    "Aide-moi a libere le donjon du monstre squelette.");
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->dialog, NULL);
    sfRenderWindow_drawText(rpg->windo->window, rpg->text_dialog, NULL);
}

void text_two(rpg_t *rpg)
{
    sfText_setString(rpg->text_dialog, "Ta quete est de reussir a tuer "
    "ce monstre soit a \n"
    "main nu, soit a l'aide d'une epee que tu peut recuperer\n"
    "dans des coffres. Dans ces coffres tu peut trouver");
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->dialog, NULL);
    sfRenderWindow_drawText(rpg->windo->window, rpg->text_dialog, NULL);
}

void text_three(rpg_t *rpg)
{
    sfText_setString(rpg->text_dialog, "une epee et une cle te permetant "
    "de trouver le monstre.\nMais attention des squelettes ce balade "
    "dans le donjon.\n"
    "Attention a toi et bonne chance.");
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->dialog, NULL);
    sfRenderWindow_drawText(rpg->windo->window, rpg->text_dialog, NULL);
}

void pnj_interact(rpg_t *rpg)
{
    rpg->pnj_a->pnj_rect.left = PNJ_LEFT;
    rpg->pnj_a->pnj_rect.top = PNJ_ROW_FRONT;
    if (rpg->pnj_a->interact == 0) {
        sfVector2f pos = {rpg->pnj_a->pnj_pos.x + 140, rpg->pnj_a->pnj_pos.y -
        30};
        sfSprite_setPosition(rpg->player->interact, pos);
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->interact,
        NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE))
            rpg->pnj_a->interact = 1;
    }
}

void pnj_game(rpg_t *rpg)
{
    if (rpg->player->player_pos.x > rpg->pnj_a->pnj_pos.x - 50 &&
    rpg->player->player_pos.x < rpg->pnj_a->pnj_pos.x + 90 &&
    rpg->player->player_pos.y > rpg->pnj_a->pnj_pos.y &&
    rpg->player->player_pos.y < rpg->pnj_a->pnj_pos.y + 230) {
        pnj_interact(rpg);
    } else
        chrono_pnj(rpg, rpg->pnj_a->clock_pnj, 300000.0, 540);
    if (rpg->pnj_a->interact == 1)
        box_dialogg(rpg);
    sfSprite_setTextureRect(rpg->pnj_a->pnj, rpg->pnj_a->pnj_rect);
    sfSprite_setPosition(rpg->pnj_a->pnj, rpg->pnj_a->pnj_pos);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->pnj_a->pnj, NULL);
}
