/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load page for rpg
*/

#include "rpg.h"

void set_sprite(rpg_t *rpg)
{
    sfSprite_setScale(rpg->load->load2, (sfVector2f){1.0, 1.0});
    sfSprite_setPosition(rpg->load->load2, (sfVector2f){400, 350});
    sfSprite_setScale(rpg->load->load, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(rpg->load->load, (sfVector2f){1060, 440});
    rpg->load->rect = (sfIntRect) {0, 0, 125, 125};
}

void destroy_load(rpg_t *rpg)
{
    sfSprite_destroy(rpg->load->font);
    sfSprite_destroy(rpg->load->load2);
    sfSprite_destroy(rpg->load->load);
    free(rpg->load);
}

void display_loading(rpg_t *rpg, int i, int j)
{
    rpg->load->rect.left = j * 125;
    rpg->load->rect.top = i * 125;
    sfSprite_setTextureRect(rpg->load->load, rpg->load->rect);
    while (sfRenderWindow_pollEvent(rpg->windo->window, &rpg->windo->event))
        if (rpg->windo->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->windo->window);
    sfRenderWindow_clear(rpg->windo->window, sfColor_fromRGB(142, 143, 143));
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->load->font, NULL);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->load->load, NULL);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->load->load2, NULL);
    sfRenderWindow_display(rpg->windo->window);
    sfSleep((sfTime){50000});
}

int load_two(rpg_t *rpg, int p)
{
    for (int i = 0; i < 4; i++, p++) {
        for (int j = 0; j < 4; j++)
            display_loading(rpg, i, j);
        if (all_init(rpg, p) == 1)
            return 0;
    }
    return p;
}

int load_screen(rpg_t *rpg)
{
    int p = 1;
    rpg->load->load = create_sprite("assets/sprite/load.png");
    rpg->load->load2 = create_sprite("assets/sprite/loading.png");
    rpg->load->font = create_sprite("assets/font.jpg");

    if (all_init(rpg, 0) == 1 || !rpg->load->load || !rpg->load->load2 ||
    !rpg->load->font)
        return 1;
    set_sprite(rpg);
    for (int o = 0; o != 2; o++) {
        p = load_two(rpg, p);
        if (p == 0)
            return 1;
    }
    destroy_load(rpg);
    set_view(rpg, (sfVector2f){5520 / 2,
    7680 - rpg->windo->video_mode.height / 2}, 1);
    return 0;
}
