/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** all destroy of rpg
*/

#include "rpg.h"

void destroy_classic(rpg_t *rpg)
{
    sfSprite_destroy(rpg->font);
    sfSprite_destroy(rpg->font_floue);
    sfSprite_destroy(rpg->dialog);
    sfText_destroy(rpg->text_dialog);
    sfImage_destroy(rpg->image_font);
}

void free_struct(rpg_t *rpg)
{
    free(rpg->boss);
    free(rpg->player);
    free(rpg->effect);
    free(rpg->sound);
    free(rpg->windo);
    free(rpg);
}

void all_destroy(rpg_t *rpg)
{
    destroy_sound(rpg);
    destroy_window(rpg);
    destroy_effect(rpg);
    destroy_boss(rpg);
    destroy_player(rpg);
    destroy_classic(rpg);
    free_struct(rpg);
}
