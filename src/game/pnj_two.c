/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pnj_two
*/

#include "rpg.h"

void box_dialogg(rpg_t *rpg)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);
    sfSprite_setPosition(rpg->dialog, (sfVector2f){edd.x - 900, edd.y - 400});
    sfText_setPosition(rpg->text_dialog, (sfVector2f){edd.x - 600, edd.y +
    250});
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue);
        rpg->pnj_a->pnj__dialog++;
    }
    if (rpg->pnj_a->pnj__dialog == 0)
        text_un(rpg);
    if (rpg->pnj_a->pnj__dialog == 1)
        text_two(rpg);
    if (rpg->pnj_a->pnj__dialog == 2)
        text_three(rpg);
    if (rpg->pnj_a->pnj__dialog == 3) {
        rpg->pnj_a->mouv_un = 0;
        rpg->pnj_a->mouv_deux = 0;
        rpg->pnj_a->interact = 0;
        rpg->pnj_a->pnj__dialog = 0;
    }
}

void move_rect_pnj(int offset, int max_value, rpg_t *rpg, int d)
{
    rpg->pnj_a->pnj_rect.left = rpg->pnj_a->pnj_rect.left + offset;
    if (rpg->pnj_a->pnj_rect.left >= max_value) {
        rpg->pnj_a->pnj_rect.left = 61;
        rpg->pnj_a->pnj_pos.x += d;
    }
}

void stop_pnj(rpg_t *rpg, int speed)
{
    if (rpg->pnj_a->pnj_pos.x >= 2060) {
        rpg->pnj_a->pnj_pos.x -= speed * 2;
        rpg->pnj_a->mouv_deux = 0;
        rpg->pnj_a->mouv_un = 40;
        rpg->pnj_a->pnj_rect.left = 0;
        rpg->pnj_a->pnj_rect.top = 636;
    }
    if (rpg->pnj_a->pnj_pos.x <= 1650) {
        rpg->pnj_a->pnj_pos.x += speed * 2;
        rpg->pnj_a->mouv_deux = 1;
        rpg->pnj_a->mouv_un = 40;
        rpg->pnj_a->pnj_rect.left = 0;
        rpg->pnj_a->pnj_rect.top = 636;
    }
}

void chrono_pnj_two(rpg_t *rpg, int speed, int max)
{
    if (rpg->pnj_a->mouv_deux == 0) {
        rpg->pnj_a->pnj_rect.top = 574;
        rpg->pnj_a->pnj_pos.x -= speed;
        move_rect_pnj(65, 440, rpg, -6);
    }
    if (rpg->pnj_a->mouv_deux == 1) {
        rpg->pnj_a->pnj_rect.top = 699;
        rpg->pnj_a->pnj_pos.x += speed;
        move_rect_pnj(63, max, rpg, 15);
    }
    stop_pnj(rpg, speed);
}

void chrono_pnj(rpg_t *rpg, sfClock *clock, float secc, int max)
{
    max = max;
    sfTime time;
    float sec;
    int speed = 4;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / secc;
    if (sec > 0.55) {
        if (rpg->pnj_a->mouv_un == 0)
            chrono_pnj_two(rpg, speed, max);
        if (rpg->pnj_a->mouv_un != 0)
            rpg->pnj_a->mouv_un--;
        sfClock_restart(clock);
    }
}
