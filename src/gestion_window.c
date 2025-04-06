/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** gestion of all part window
*/

#include "rpg.h"

int main_page_and_resume(rpg_t *rpg, int *o2, int o)
{
    if (rpg->resume == 1)
        pause_window(rpg);
    else
        main_page(rpg);
    o == 2 ? 0 : o++;
    sfSound_stop(rpg->sound->sound_game);
    *o2 = 0;
    return (o);
}

int gestion_window(rpg_t *rpg, int o, int *o2)
{
    event(rpg);
    o == 1 ? sfSound_play(rpg->sound->sound_accueil) : 0;
    *o2 == 1 ? sfSound_play(rpg->sound->sound_game) : 0;
    if (rpg->page == 0) {
        o = main_page_and_resume(rpg, o2, o);
    }
    if (rpg->page == 1) {
        rpg->resume = 1;
        game(rpg);
        sfSound_stop(rpg->sound->sound_accueil);
        o = 0;
        *o2 != 2 ?
        *o2 += 1 : 0;
    }
    rpg->page == 2 ? credit_window(rpg) : 0;
    rpg->page == 3 ? option_window(rpg) : 0;
    rpg->page == 4 ? character_window(rpg) : 0;
    rpg->page == 5 ? lose_page(rpg) : 0;
    sfSound_setVolume(rpg->sound->sound_accueil, rpg->sound->volume);
    return (o);
}
