/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event for rpg
*/

#include "rpg.h"

void dev_fonction_event(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue && rpg->zoom < 1.35 &&
    rpg->page == 1)
        rpg->zoom += 0.01;
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && rpg->zoom > 1 &&
    rpg->page == 1)
        rpg->zoom -= 0.01;
    if (rpg->page != 1)
        rpg->zoom = 1;
}

void resize(rpg_t *rpg)
{
    if (sfEvtResized == rpg->windo->event.type) {
        rpg->windo->video_mode.width = rpg->windo->event.size.width;
        rpg->windo->video_mode.height = rpg->windo->event.size.height;
    }
}

void echap_key(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        if (rpg->page == 5) {
            rpg->resume = 0;
            rpg->continue_game = 0;
            set_view(rpg, (sfVector2f){5520 / 2, 7680 -
            rpg->windo->video_mode.height / 2}, 1);
        }
        rpg->page = 0;
    }
}

void event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->windo->window, &rpg->windo->event)) {
        if (rpg->windo->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->windo->window);
        resize(rpg);
        if (rpg->page == 1 && attack_val(0) <= 0)
            all_mouv(rpg);
        echap_key(rpg);
        deplace_map(rpg);
    }
    player_attack(rpg);
    dev_fonction_event(rpg);
    game_boss(rpg);
    boss_detection(rpg);
    vilain_detection(rpg);
    game_vilain(rpg);
}
