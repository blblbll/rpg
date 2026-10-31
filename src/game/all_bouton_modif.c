/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** all_bouton_modif
*/

#include "rpg.h"

void all_bouton_modi(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->windo->window);

    int ids[4] = {MENU_RESUME, MENU_OPTION2, MENU_CHARACTER, MENU_MENU};

    menu_begin(rpg, ids, 4);
    bouton_resume(rpg, edd, mouse);
    bouton_optiontwo(rpg, edd, mouse);
    bouton_character(rpg, edd, mouse);
    bouton_menu(rpg, edd, mouse);
}
