/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_sup
*/

#include "rpg.h"

void destroy_sound(rpg_t *rpg)
{
    sfSound_destroy(rpg->sound->sound_game);
    sfSound_destroy(rpg->sound->sound_accueil);
    sfSound_destroy(rpg->sound->sound_sword);
    sfSoundBuffer_destroy(rpg->sound->sound_buffer);
    sfSoundBuffer_destroy(rpg->sound->sound_buffer_game);
    sfSoundBuffer_destroy(rpg->sound->sound_buffer_sword);
}

void destroy_window(rpg_t *rpg)
{
    sfClock_destroy(rpg->windo->clock);
    sfView_destroy(rpg->windo->view);
    sfRenderWindow_destroy(rpg->windo->window);
}

void destroy_effect(rpg_t *rpg)
{
    sfSprite_destroy(rpg->effect->door);
    sfSprite_destroy(rpg->effect->first_door);
    sfSprite_destroy(rpg->effect->second_door);
    sfSprite_destroy(rpg->effect->third_door);
    sfCircleShape_destroy(rpg->effect->circle);
    sfRectangleShape_destroy(rpg->effect->rect);
}

void destroy_boss(rpg_t *rpg)
{
    sfSprite_destroy(rpg->boss->boss);
    sfSprite_destroy(rpg->vilain->vilain1);
    sfSprite_destroy(rpg->vilain->vilain2);
    sfSprite_destroy(rpg->vilain->vilain3);
    sfSprite_destroy(rpg->vilain->vilain4);
    sfSprite_destroy(rpg->vilain->vilain5);
}

void destroy_player(rpg_t *rpg)
{
    sfSprite_destroy(rpg->player->life);
    sfSprite_destroy(rpg->player->sword);
    sfSprite_destroy(rpg->player->coffre);
    sfSprite_destroy(rpg->player->player);
    sfSprite_destroy(rpg->player->interact);
    sfText_destroy(rpg->player->text);
    sfFont_destroy(rpg->player->font);
}
