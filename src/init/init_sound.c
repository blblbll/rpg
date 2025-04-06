/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init sound
*/

#include "rpg.h"

int init_sound_two(rpg_t *rpg)
{
    rpg->sound->sound_game = sfSound_create();
    rpg->sound->sound_buffer_game = sfSoundBuffer_createFromFile
    ("assets/sound/background_sounds.ogg");
    rpg->sound->sound_sword = sfSound_create();
    rpg->sound->sound_buffer_sword = sfSoundBuffer_createFromFile
    ("assets/sound/sword_attack.wav");

    if (!rpg->sound->sound_buffer_game || !rpg->sound->sound_buffer_sword)
        return 1;
    sfSound_setBuffer(rpg->sound->sound_game, rpg->sound->sound_buffer_game);
    sfSound_setLoop(rpg->sound->sound_game, sfTrue);
    sfSound_setBuffer(rpg->sound->sound_sword, rpg->sound->sound_buffer_sword);
    sfSound_setLoop(rpg->sound->sound_sword, sfFalse);
    return 0;
}

int init_sound(rpg_t *rpg)
{
    rpg->sound->sound_accueil = sfSound_create();
    rpg->sound->volume = 50;
    rpg->sound->sound_buffer = sfSoundBuffer_createFromFile
    ("assets/sound/musique_acceuil.ogg");
    if (!rpg->sound->sound_buffer)
        return 1;
    sfSound_setBuffer(rpg->sound->sound_accueil, rpg->sound->sound_buffer);
    sfSound_setLoop(rpg->sound->sound_accueil, sfTrue);
    if (init_sound_two(rpg) == 1)
        return 1;
    rpg->sound->pos_vol = 50;
    rpg->sound->pos_vol_two = 0;
    rpg->sound->pass_font = "assets/font/Cardinal.ttf";
    return 0;
}
