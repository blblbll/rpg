/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** bouton for main page
*/

#include "rpg.h"

void bouton_start(rpg_t *rpg, sfVector2i mouse)
{
    sfFloatRect rect;

    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setString(rpg->player->text, "START");
    sfText_setFont(rpg->player->text, rpg->player->font);
    rect = sfText_getGlobalBounds(rpg->player->text);
    if (sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg)) == sfTrue) {
        sfText_setColor(rpg->player->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            all_reset(rpg);
    }
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_option(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfFloatRect rect;

    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 250, edd.y -
    200});
    sfText_setColor(rpg->player->text, sfBlack);
    sfText_setString(rpg->player->text, "Options");
    sfText_setFont(rpg->player->text, rpg->player->font);
    rect = sfText_getGlobalBounds(rpg->player->text);
    if (sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg)) == sfTrue) {
        sfText_setColor(rpg->player->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            rpg->page = 3;
    }
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_credit(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfFloatRect rect;

    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 230, edd.y});
    sfText_setColor(rpg->player->text, sfBlack);
    sfText_setString(rpg->player->text, "Credits");
    sfText_setFont(rpg->player->text, rpg->player->font);
    rect = sfText_getGlobalBounds(rpg->player->text);
    if (sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg)) == sfTrue) {
        sfText_setColor(rpg->player->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            rpg->page = 2;
    }
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_quit(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfFloatRect rect;

    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 200, edd.y +
    200});
    sfText_setString(rpg->player->text, "Quit");
    sfText_setFont(rpg->player->text, rpg->player->font);
    sfText_setColor(rpg->player->text, sfColor_fromRGBA(255, 120, 120, 255));
    rect = sfText_getGlobalBounds(rpg->player->text);
    if (sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg)) == sfTrue) {
        sfText_setColor(rpg->player->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(rpg->windo->window);
    }
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void bouton_continue(rpg_t *rpg, sfVector2f edd, sfVector2i mouse)
{
    sfFloatRect rect;

    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x, edd.y -400});
    sfText_setColor(rpg->player->text, sfColor_fromRGB(200, 200, 200));
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setString(rpg->player->text, "Continue");
    sfText_setFont(rpg->player->text, rpg->player->font);
    rect = sfText_getGlobalBounds(rpg->player->text);
    if (sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg)) == sfTrue) {
        sfText_setColor(rpg->player->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            rpg->page = 1;
        }
    }
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}
