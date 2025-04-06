/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** bouton_two
*/

#include "rpg.h"

void all_bouton(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->windo->window);

    if (rpg->continue_game == 1) {
        bouton_continue(rpg, edd, mouse);
        sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 500, edd.y -
        400});
    } else
        sfText_setPosition(rpg->player->text, (sfVector2f){edd.x - 300, edd.y -
        400});
    bouton_start(rpg, mouse);
    bouton_option(rpg, edd, mouse);
    bouton_credit(rpg, edd, mouse);
    bouton_quit(rpg, edd, mouse);
}

void all_reset(rpg_t *rpg)
{
    rpg->dialog_sound = 0;
    rpg->player->chest = 0;
    rpg->dialog_pass = 0;
    rpg->defil = 0;
    rpg->player->weapon = 0;
    rpg->player->chest = 0;
    rpg->player->player = create_sprite("assets/perso/Perso1.png");
    sfSprite_setPosition(rpg->player->player, (sfVector2f){2550, 7100});
    sfSprite_setScale(rpg->player->player, (sfVector2f){3.5, 3.5});
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
    rpg->player->direction = 0;
    rpg->player->attack = 1;
    rpg->player->life_rect.top = 0;
    rpg->player->vie = 375;
    rpg->player->player_pos = (sfVector2f) {2550, 7100};
    set_view(rpg, (sfVector2f){5520 / 2, 7680 -
    rpg->windo->video_mode.height / 2}, 1);
    rpg->page = 1;
}
