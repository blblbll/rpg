/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main
*/

#include "rpg.h"

void set_view(rpg_t *rpg, sfVector2f pos, int i)
{
    sfView_setSize(rpg->windo->view, (sfVector2f){rpg->windo->video_mode.width,
    rpg->windo->video_mode.height});
    sfView_zoom(rpg->windo->view, rpg->zoom);
    if (i == 1)
        sfView_setCenter(rpg->windo->view, pos);
    sfRenderWindow_setView(rpg->windo->window, rpg->windo->view);
}

int error_load(rpg_t *rpg)
{
    write(2, "Error: Can't load the game, sprites are missing !\n", 51);
    all_destroy(rpg);
    return (84);
}

rpg_t *struct_alloc(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    rpg->load = malloc(sizeof(load_t));
    rpg->windo = malloc(sizeof(window_t));
    rpg->effect = malloc(sizeof(effect_t));
    rpg->boss = malloc(sizeof(boss_t));
    rpg->sound = malloc(sizeof(sound_t));
    rpg->player = malloc(sizeof(player_t));
    rpg->pnj_a = malloc(sizeof(pnj_a_t));
    rpg->vilain = malloc(sizeof(vilain_t));

    if (rpg == NULL || rpg->sound == NULL || rpg->player == NULL ||
    rpg->boss == NULL || rpg->load == NULL || rpg->effect == NULL ||
    rpg->windo == NULL || rpg->pnj_a == NULL ||
    rpg->vilain == NULL)
        return (NULL);
    return (rpg);
}

int main (void)
{
    int o = 0;
    int o2 = 0;
    rpg_t *rpg = struct_alloc();

    if (rpg == NULL)
        return (84);
    if (load_screen(rpg) == 1)
        return (error_load(rpg));
    while (sfRenderWindow_isOpen(rpg->windo->window)) {
        o = gestion_window(rpg, o, &o2);
    }
    all_destroy(rpg);
    return (0);
}
