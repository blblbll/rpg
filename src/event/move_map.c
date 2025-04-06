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

void smooth_move(rpg_t *rpg, int x, int y, int nb)
{
    int i = 0;

    for (; i < 50; i++) {
        sfView_move(rpg->windo->view, (sfVector2f){x, y});
        sfRenderWindow_setView(rpg->windo->window, rpg->windo->view);
    }
}

void deplace_map_two(rpg_t *rpg, sfVector2f edd)
{
    if (rpg->player->player_pos.y < (edd.y - rpg->windo->video_mode.height / 2)
    + 200) {
        rpg->player->player_pos.y = (edd.y - rpg->windo->video_mode.height / 2)
        + 200;
        y_static(y_static(0) + rpg->player->vitesse);
        smooth_move(rpg, 0, -1, 7);
        sfRenderWindow_setView(rpg->windo->window, rpg->windo->view);
    }
    if (rpg->player->player_pos.y > (edd.y + rpg->windo->video_mode.height / 2)
    - 450) {
        rpg->player->player_pos.y = (edd.y + rpg->windo->video_mode.height / 2)
        - 450;
        y_static(y_static(0) - rpg->player->vitesse);
        smooth_move(rpg, 0, 1, 7);
        sfRenderWindow_setView(rpg->windo->window, rpg->windo->view);
    }
}

void deplace_map(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);

    if (rpg->player->player_pos.x < (edd.x - rpg->windo->video_mode.width / 2)
    + 200) {
        rpg->player->player_pos.x = (edd.x - rpg->windo->video_mode.width / 2)
        + 200;
        x_static(x_static(0) + rpg->player->vitesse);
        smooth_move(rpg, -1, 0, 7);
        sfRenderWindow_setView(rpg->windo->window, rpg->windo->view);
    }
    if (rpg->player->player_pos.x > (edd.x + rpg->windo->video_mode.width / 2)
    - 350) {
        rpg->player->player_pos.x = (edd.x + rpg->windo->video_mode.width / 2)
        - 350;
        x_static(x_static(0) - rpg->player->vitesse);
        smooth_move(rpg, 1, 0, 7);
        sfRenderWindow_setView(rpg->windo->window, rpg->windo->view);
    }
    deplace_map_two(rpg, edd);
}
