/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** resume_pause window in game
*/

#include "rpg.h"

void pause_window(rpg_t *rpg)
{
    rpg->dialog_sound = 0;

    set_view(rpg, rpg->player->player_pos, 0);
    sfRenderWindow_clear(rpg->windo->window, sfColor_fromRGB(41, 45, 54));
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->font_floue, NULL);
    all_bouton_modi(rpg);
    sfRenderWindow_display(rpg->windo->window);
}
