/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** bouton for resume page in game
*/

#include "rpg.h"

void bouton_resume(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 320, edd.y -
    320});
    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setCharacterSize(rpg->player->text, 90);
    sfText_setString(rpg->player->text, "RESUME");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_RESUME))
        rpg->page = 1;
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_optiontwo(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 250, edd.y -
    190});
    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setString(rpg->player->text, "Options");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_OPTION2))
        rpg->page = 3;
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_character(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 250, edd.y -
    60});
    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setString(rpg->player->text, "Character");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_CHARACTER))
        rpg->page = 4;
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void while_menu(rpg_t *rpg)
{
    while (sfMouse_isButtonPressed(sfMouseLeft) != sfFalse);
    rpg->resume = 0;
}

void bouton_menu(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 230, edd.y +
    100});
    sfText_setColor(rpg->player->text, sfColor_fromRGBA(255, 120, 120, 255));
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setString(rpg->player->text, "Menu");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_MENU))
        while_menu(rpg);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}
