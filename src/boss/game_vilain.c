/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouv
*/

#include "rpg.h"
#include <stdio.h>

static struct {
    int level;
    int old_atk;
    int active;
    sfClock *clock;
} g_up = {1, 1, 0, NULL};

void reset_level(void)
{
    g_up.level = 1;
    g_up.old_atk = 1;
    g_up.active = 0;
}

void level_up(rpg_t *rpg)
{
    g_up.level += 1;
    g_up.old_atk = rpg->player->attack;
    rpg->player->attack += 1;
    g_up.active = 1;
    if (!g_up.clock)
        g_up.clock = sfClock_create();
    sfClock_restart(g_up.clock);
}

static void draw_popup_text(rpg_t *rpg, sfVector2f pos)
{
    static sfText *text = NULL;
    char buf[200];
    int o = g_up.old_atk;
    int n = rpg->player->attack;

    if (!text) {
        text = sfText_create();
        sfText_setFont(text, sfText_getFont(rpg->player->text));
        sfText_setCharacterSize(text, 30);
    }
    snprintf(buf, sizeof(buf), "NIVEAU %d !\nAttaque : %d -> %d\n"
    "Degats main : %d -> %d", g_up.level, o, n, damage_for(o, 1),
    damage_for(n, 1));
    if (rpg->player->weapon == 1)
        snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf),
        "\nDegats epee : %d -> %d", damage_for(o, 2),
        damage_for(n, 2));
    sfText_setString(text, buf);
    sfText_setColor(text, sfColor_fromRGB(255, 220, 90));
    sfText_setPosition(text, (sfVector2f){pos.x + 25, pos.y + 15});
    sfRenderWindow_drawText(rpg->windo->window, text, NULL);
}

void draw_level_up(rpg_t *rpg)
{
    static sfRectangleShape *box = NULL;
    sfVector2f c = sfView_getCenter(rpg->windo->view);
    sfVector2f s = sfView_getSize(rpg->windo->view);
    sfVector2f pos = {c.x - 230, c.y - s.y / 2 + 40};

    if (!g_up.active)
        return;
    if (sfTime_asSeconds(sfClock_getElapsedTime(g_up.clock)) > 4.0) {
        g_up.active = 0;
        return;
    }
    if (!box) {
        box = sfRectangleShape_create();
        sfRectangleShape_setSize(box, (sfVector2f){460, 170});
        sfRectangleShape_setFillColor(box, sfColor_fromRGBA(0, 0, 0, 200));
        sfRectangleShape_setOutlineColor(box, sfColor_fromRGB(255, 220, 90));
        sfRectangleShape_setOutlineThickness(box, 4);
    }
    sfRectangleShape_setPosition(box, pos);
    sfRenderWindow_drawRectangleShape(rpg->windo->window, box, NULL);
    draw_popup_text(rpg, pos);
}

void set_color_no_weapon2(rpg_t *rpg)
{
    if (rpg->vilain->attack4 == 1) {
        rpg->vilain->vie4 -= player_damage(rpg, 1);
        flash_red(rpg->vilain->vilain4);
        rpg->vilain->attack4 = 0;
    }
    if (rpg->vilain->attack5 == 1) {
        rpg->vilain->vie5 -= player_damage(rpg, 1);
        flash_red(rpg->vilain->vilain5);
        rpg->vilain->attack5 = 0;
    }
}

void set_color_no_weapon(rpg_t *rpg)
{
    if (rpg->vilain->attack1 == 1) {
        rpg->vilain->vie1 -= player_damage(rpg, 1);
        flash_red(rpg->vilain->vilain1);
        rpg->vilain->attack1 = 0;
    }
    if (rpg->vilain->attack2 == 1) {
        rpg->vilain->vie2 -= player_damage(rpg, 1);
        flash_red(rpg->vilain->vilain2);
        rpg->vilain->attack2 = 0;
    }
    if (rpg->vilain->attack3 == 1) {
        rpg->vilain->vie3 -= player_damage(rpg, 1);
        flash_red(rpg->vilain->vilain3);
        rpg->vilain->attack3 = 0;
    }
    set_color_no_weapon2(rpg);
}

void set_color_weapon2(rpg_t *rpg)
{
    if (rpg->vilain->attack4 == 2) {
        rpg->vilain->vie4 -= player_damage(rpg, 2);
        flash_red(rpg->vilain->vilain4);
        rpg->vilain->attack4 = 0;
    }
    if (rpg->vilain->attack5 == 2) {
        rpg->vilain->vie5 -= player_damage(rpg, 2);
        flash_red(rpg->vilain->vilain5);
        rpg->vilain->attack5 = 0;
    }
}

void set_color_weapon(rpg_t *rpg)
{
    if (rpg->vilain->attack1 == 2) {
        rpg->vilain->vie1 -= player_damage(rpg, 2);
        flash_red(rpg->vilain->vilain1);
        rpg->vilain->attack1 = 0;
    }
    if (rpg->vilain->attack2 == 2) {
        rpg->vilain->vie2 -= player_damage(rpg, 2);
        flash_red(rpg->vilain->vilain2);
        rpg->vilain->attack2 = 0;
    }
    if (rpg->vilain->attack3 == 2) {
        rpg->vilain->vie3 -= player_damage(rpg, 2);
        flash_red(rpg->vilain->vilain3);
        rpg->vilain->attack3 = 0;
    }
    set_color_weapon2(rpg);
}

void set_status_vilain(rpg_t *rpg)
{
    if (rpg->vilain->vie4 <= 0 && rpg->vilain->status4 != 0) {
        level_up(rpg);
        rpg->vilain->status4 = 0;
        rpg->vilain->vie4 = 1;
    }
    if (rpg->vilain->vie5 <= 0 && rpg->vilain->status5 != 0) {
        level_up(rpg);
        rpg->vilain->status5 = 0;
        rpg->vilain->vie5 = 1;
    }
}
