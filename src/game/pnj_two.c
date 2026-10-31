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
    if (key_just_pressed(sfKeyP)) {
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

void move_rect_pnj(rpg_t *rpg)
{
    rpg->pnj_a->pnj_rect.left += PNJ_STEP;
    if (rpg->pnj_a->pnj_rect.left >= PNJ_LEFT + 3 * PNJ_STEP)
        rpg->pnj_a->pnj_rect.left = PNJ_LEFT;
}

void stop_pnj(rpg_t *rpg, int speed)
{
    if (rpg->pnj_a->pnj_pos.x >= 2060) {
        rpg->pnj_a->pnj_pos.x -= speed * 2;
        rpg->pnj_a->mouv_deux = 0;
        rpg->pnj_a->mouv_un = 40;
        rpg->pnj_a->pnj_rect.left = PNJ_LEFT;
        rpg->pnj_a->pnj_rect.top = PNJ_ROW_FRONT;
    }
    if (rpg->pnj_a->pnj_pos.x <= 1650) {
        rpg->pnj_a->pnj_pos.x += speed * 2;
        rpg->pnj_a->mouv_deux = 1;
        rpg->pnj_a->mouv_un = 40;
        rpg->pnj_a->pnj_rect.left = PNJ_LEFT;
        rpg->pnj_a->pnj_rect.top = PNJ_ROW_FRONT;
    }
}

void chrono_pnj_two(rpg_t *rpg, int speed)
{
    if (rpg->pnj_a->mouv_deux == 0) {
        rpg->pnj_a->pnj_rect.top = PNJ_ROW_LEFT;
        rpg->pnj_a->pnj_pos.x -= speed;
        move_rect_pnj(rpg);
    }
    if (rpg->pnj_a->mouv_deux == 1) {
        rpg->pnj_a->pnj_rect.top = PNJ_ROW_RIGHT;
        rpg->pnj_a->pnj_pos.x += speed;
        move_rect_pnj(rpg);
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
            chrono_pnj_two(rpg, speed);
        if (rpg->pnj_a->mouv_un != 0)
            rpg->pnj_a->mouv_un--;
        sfClock_restart(clock);
    }
}
