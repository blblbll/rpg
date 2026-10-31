/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouve the map
*/

#include "rpg.h"

int x_static(int nouveauNombre)
{
    static int nombre = 0;

    if (nouveauNombre != 0)
        nombre = nouveauNombre;
    return nombre;
}

int y_static(int nouveauNombre)
{
    static int nombre = 0;

    if (nouveauNombre != 0)
        nombre = nouveauNombre;
    return nombre;
}

float overshoot(float pos, float min, float max)
{
    if (pos < min)
        return pos - min;
    if (pos > max)
        return pos - max;
    return 0;
}

void deplace_map(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    float dx = overshoot(rpg->player->player_pos.x + 80, edd.x - 120,
    edd.x + 120);
    float dy = overshoot(rpg->player->player_pos.y + 100, edd.y - 120,
    edd.y + 120);

    if (dx == 0 && dy == 0)
        return;
    sfView_move(rpg->windo->view, (sfVector2f){dx, dy});
    sfRenderWindow_setView(rpg->windo->window, rpg->windo->view);
}
