/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main page
*/

#include "rpg.h"

void main_page(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->windo->window, sfColor_fromRGB(41, 45, 54));
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->font_floue, NULL);
    all_bouton(rpg);
    sfRenderWindow_display(rpg->windo->window);
    set_view(rpg, rpg->player->player_pos, 0);
    sfSprite_setPosition(rpg->player->player, rpg->player->player_pos);
}
