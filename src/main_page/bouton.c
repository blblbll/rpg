/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** bouton for main page
*/

#include "rpg.h"

void bouton_start(rpg_t *rpg, sfVector2i mouse)
{
    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setString(rpg->player->text, "START");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_START))
        all_reset(rpg);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_option(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 250, edd.y -
    200});
    sfText_setColor(rpg->player->text, sfBlack);
    sfText_setString(rpg->player->text, "Options");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_OPTION))
        rpg->page = 3;
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_credit(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 230, edd.y});
    sfText_setColor(rpg->player->text, sfBlack);
    sfText_setString(rpg->player->text, "Credits");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_CREDIT))
        rpg->page = 2;
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_quit(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 200, edd.y +
    200});
    sfText_setString(rpg->player->text, "Quit");
    sfText_setFont(rpg->player->text, rpg->player->font);
    sfText_setColor(rpg->player->text, sfColor_fromRGBA(255, 120, 120, 255));
    if (menu_item(rpg, mouse, MENU_QUIT))
        sfRenderWindow_close(rpg->windo->window);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_continue(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x, edd.y -400});
    sfText_setColor(rpg->player->text, sfColor_fromRGB(200, 200, 200));
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setString(rpg->player->text, "Continue");
    sfText_setFont(rpg->player->text, rpg->player->font);
    if (menu_item(rpg, mouse, MENU_CONTINUE))
        rpg->page = 1;
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}
