/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** simple fonction for rpg
*/

#include "rpg.h"

int t_static(int v, rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);

    return (v + edd.x - (rpg->windo->video_mode.width / 2));
}

int t2_static(int v, rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);

    return (v + edd.y - (rpg->windo->video_mode.height / 2));
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value) {
        rect->left = 60;
    }
}
