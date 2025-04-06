/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** credit window rpg
*/

#include "rpg.h"

void credit_window(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    char *str = "Credits: \n- Marcq Julien\n- Rogez Jules\n- Wozniak Thomas\n\
- Isore Gabriel\n";

    sfText_setString(rpg->player->text, str);
    sfText_setColor(rpg->player->text, sfColor_fromRGB(245, 245, 245));
    sfText_setPosition(rpg->player->text, (sfVector2f){2350, edd.y - 400});
    sfRenderWindow_clear(rpg->windo->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->font_floue, NULL);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    sfRenderWindow_display(rpg->windo->window);
    set_view(rpg, (sfVector2f){5520 / 2, 7680 -
    rpg->windo->video_mode.height / 2}, 1);
}
