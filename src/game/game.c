/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** game page rpg
*/

#include "rpg.h"

void draw_villain_sprite(rpg_t *rpg)
{
    if (rpg->vilain->status1 != 0) {
        sfRenderWindow_drawSprite(rpg->windo->window,
        rpg->vilain->vilain1, NULL);
    }
    if (rpg->vilain->status2 != 0) {
        sfRenderWindow_drawSprite(rpg->windo->window,
        rpg->vilain->vilain2, NULL);
    }
    if (rpg->vilain->status3 != 0) {
        sfRenderWindow_drawSprite(rpg->windo->window,
        rpg->vilain->vilain3, NULL);
    }
    if (rpg->vilain->status4 != 0) {
        sfRenderWindow_drawSprite(rpg->windo->window,
        rpg->vilain->vilain4, NULL);
    }
    if (rpg->vilain->status5 != 0) {
        sfRenderWindow_drawSprite(rpg->windo->window,
        rpg->vilain->vilain5, NULL);
    }
}

void lose_page(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);

    sfRenderWindow_clear(rpg->windo->window, sfColor_fromRGB(41, 45, 54));
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->font_floue, NULL);
    sfText_setString(rpg->player->text, " YOU LOSE\nPress echap");
    sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 300, edd.y -
    200});
    sfText_setCharacterSize(rpg->player->text, 100);
    sfRenderWindow_drawText(rpg->windo->window, rpg->player->text, NULL);
    sfRenderWindow_display(rpg->windo->window);
}

void game_second(rpg_t *rpg, int len)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue);
        rpg->page = 4;
    }
    display_life(rpg);
    box_dialog(rpg, len);
    if (rpg->player->vie == 0)
        rpg->page = 5;
    sfRenderWindow_display(rpg->windo->window);
    set_view(rpg, rpg->player->player_pos, 0);
    sfSound_setVolume(rpg->sound->sound_game, rpg->sound->volume);
}

void game(rpg_t *rpg)
{
    int len = my_strlen(rpg->message);
    rpg->continue_game = 1;

    sfRenderWindow_clear(rpg->windo->window, sfColor_fromRGB(41, 45, 54));
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->font, NULL);
    first_chest(rpg);
    pnj_game(rpg);
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->player->player, NULL);
    if (rpg->boss->status != 0)
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->boss->boss, NULL);
    draw_villain_sprite(rpg);
    door_for_boss(rpg);
    game_second(rpg, len);
}
