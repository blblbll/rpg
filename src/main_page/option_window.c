/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** option window
*/

#include "rpg.h"

void display_level_sound(rpg_t *rpg)
{
    char *str = rpg->sound->volume == 0 ? "Mute" :
    my_itoa(rpg->sound->volume);
    sfVector2f edd = sfView_getCenter(rpg->windo->view);

    sfText_setString(rpg->player->text, "Sound: ");
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 300, edd.y -
    280});
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    sfText_setString(rpg->player->text, str);
    sfText_setCharacterSize(rpg->player->text, 100);
    sfText_setColor(rpg->player->text, sfWhite);
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x, edd.y - 280});
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
}

void set_pos_circle(rpg_t *rpg, sfVector2f edd)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->windo->window);

    if (rpg->sound->pos_vol_two == 0 || rpg->sound->volume <= 0)
        rpg->sound->pos_vol = edd.x - 125;
    if (sfMouse_isButtonPressed(sfMouseLeft) && t_static(mouse.x, rpg) > edd.x
    - 250 && t_static(mouse.x, rpg) < edd.x + 50 && t2_static(mouse.y, rpg) >
    edd.y - 120
    && t2_static(mouse.y, rpg) < edd.y - 80) {
        rpg->sound->pos_vol = t_static(mouse.x, rpg);
        rpg->sound->pos_vol_two = 1;
    }
    if (menu_selected(MENU_SOUND)) {
        rpg->sound->pos_vol += sfKeyboard_isKeyPressed(sfKeyRight) * 4;
        rpg->sound->pos_vol -= sfKeyboard_isKeyPressed(sfKeyLeft) * 4;
        if (sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyLeft))
            rpg->sound->pos_vol_two = 1;
        rpg->sound->pos_vol = fmax(edd.x - 240, fmin(edd.x + 47,
        rpg->sound->pos_vol));
    }
    rpg->sound->volume = (rpg->sound->pos_vol - edd.x) * 100 / 297 + 83;
    rpg->sound->pos_circle = (sfVector2f){edd.x - 250 +
    ((rpg->sound->volume * 297) / 100), edd.y - 110};
}

void slicer(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);

    sfRectangleShape_setSize(rpg->effect->rect, (sfVector2f){300, 4});
    sfRectangleShape_setPosition(rpg->effect->rect, (sfVector2f){edd.x - 250,
    edd.y - 100});
    sfRectangleShape_setFillColor(rpg->effect->rect, sfWhite);
    sfRenderWindow_drawRectangleShape(rpg->windo->window, rpg->effect->rect,
    NULL);
    sfCircleShape_setRadius(rpg->effect->circle, 10);
    set_pos_circle(rpg, edd);
    sfCircleShape_setPosition(rpg->effect->circle, rpg->sound->pos_circle);
    sfCircleShape_setFillColor(rpg->effect->circle, sfWhite);
    sfRenderWindow_drawCircleShape(rpg->windo->window, rpg->effect->circle,
    NULL);
}

void option_window(rpg_t *rpg)
{
    int ids[3] = {MENU_SOUND, MENU_RES1, MENU_RES2};

    menu_begin(rpg, ids, 3);
    sfRenderWindow_clear(rpg->windo->window, sfColor_fromRGB(41, 45, 54));
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->font_floue, NULL);
    display_level_sound(rpg);
    slicer(rpg);
    resolution(rpg);
    sfRenderWindow_display(rpg->windo->window);
    set_view(rpg, rpg->player->player_pos, 0);
    if (rpg->resume != 1)
        set_view(rpg, (sfVector2f){5520 / 2, 7680 -
        rpg->windo->video_mode.height / 2}, 1);
}
