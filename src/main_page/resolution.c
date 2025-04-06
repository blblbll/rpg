/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** set resolution for page
*/

#include "rpg.h"

void res_one(rpg_t *rpg,  sfText *res)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        rpg->windo->video_mode.width = 1920;
        rpg->windo->video_mode.height = 1080;
        sfRenderWindow_setSize(rpg->windo->window, (sfVector2u){1920, 1080});
    }
    sfText_setColor(res, sfYellow);
}

void first_res(rpg_t *rpg, sfText *res, sfVector2i mouse, sfVector2f edd)
{
    sfText_setString(res, "1920x1080");
    sfText_setCharacterSize(res, 100);
    sfText_setPosition(res, (sfVector2f){edd.x - 250, edd.y + 120});
    if (rpg->windo->video_mode.width == 1920 &&
    rpg->windo->video_mode.height == 1080)
        sfText_setColor(res, sfRed);
    else
        sfText_setColor(res, sfWhite);
    sfFloatRect rect = sfText_getGlobalBounds(res);
    if (sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg)))
        res_one(rpg, res);
    sfRenderWindow_drawText(rpg->windo->window, res, NULL);
}

void res_two(rpg_t *rpg, sfText *res)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        rpg->windo->video_mode.width = 1600;
        rpg->windo->video_mode.height = 900;
        sfRenderWindow_setSize(rpg->windo->window, (sfVector2u){1600, 900});
    }
    sfText_setColor(res, sfYellow);
}

void second_res(rpg_t *rpg, sfText *res, sfVector2i mouse, sfVector2f edd)
{
    sfText_setString(res, "1600x900");
    sfText_setCharacterSize(res, 100);
    sfText_setPosition(res, (sfVector2f){edd.x - 250, edd.y + 250});
    if (rpg->windo->video_mode.width == 1600 &&
    rpg->windo->video_mode.height == 900)
        sfText_setColor(res, sfRed);
    else
        sfText_setColor(res, sfWhite);
    sfFloatRect rect = sfText_getGlobalBounds(res);
    if (sfFloatRect_contains(&rect, t_static(mouse.x, rpg),
    t2_static(mouse.y, rpg)))
        res_two(rpg, res);
    sfRenderWindow_drawText(rpg->windo->window, res, NULL);
}

void resolution(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->windo->window);

    sfText_setString(rpg->player->text, "Resolution: ");
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 280, edd.y});
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    first_res(rpg, rpg->player->text, mouse, edd);
    second_res(rpg, rpg->player->text, mouse, edd);
    set_view(rpg, rpg->player->player_pos, 0);
}
