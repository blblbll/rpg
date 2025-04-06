/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init windows
*/

#include "rpg.h"

int init_window(rpg_t *rpg)
{
    rpg->windo->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "My_RPG", sfResize | sfClose, NULL);
    rpg->player->text = sfText_create();
    rpg->player->font = sfFont_createFromFile("assets/font/Seagramtfb.ttf");

    if (!rpg->windo->window || !rpg->player->font || !rpg->player->text)
        return 1;
    sfText_setFont(rpg->player->text, rpg->player->font);
    rpg->windo->video_mode.height = 1080;
    rpg->windo->video_mode.width = 1920;
    sfRenderWindow_setFramerateLimit(rpg->windo->window, 60);
    rpg->windo->view = sfView_create();
    rpg->windo->clock = sfClock_create();
    rpg->page = 0;
    rpg->zoom = 1;
    rpg->resume = 0;
    rpg->continue_game = 0;
    return 0;
}
