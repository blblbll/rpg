/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** box_dialog
*/

#include "rpg.h"

void display_text(rpg_t *rpg, int len)
{
    char str[len + 1];

    if (rpg->defil < len) {
        my_strncpy(str, rpg->message, rpg->defil + 1);
        sfText_setString(rpg->text_dialog, str);
        sfRenderWindow_drawText(rpg->windo->window, rpg->text_dialog, NULL);
        rpg->defil++;
    }
    sfRenderWindow_drawSprite(rpg->windo->window, rpg->dialog, NULL);
    sfRenderWindow_drawText(rpg->windo->window, rpg->text_dialog, NULL);
}

void message_two(rpg_t *rpg, int len)
{
    if (rpg->dialog_pass == 2) {
        rpg->message = "Pour interagir avec les pnj, les coffres\n"
    "ou les items: utilise la touche E.\nTu peux voir ton inventaire avec la "
    "touche I.";
        len = my_strlen(rpg->message);
        display_text(rpg, len);
    }
    if (rpg->dialog_pass == 3) {
        rpg->message = "Pour finir, tu peux attaquer les monstres avec\
        ESPACE\nSi tu veux voir un peu plus autour de toi\n\
tu dezoomer avec A et zoomer avec Z";
        len = my_strlen(rpg->message);
        display_text(rpg, len);
    }
    if (rpg->dialog_pass >= 4) {
        rpg->dialog_pass = 4;
    }
}

void message(rpg_t *rpg, int len)
{
    if (rpg->dialog_pass == 0) {
        rpg->message = "Hello, bienvenue dans le royaume\n\
Voici comment jouer au jeu:\nPresse P pour passer";
        len = my_strlen(rpg->message);
        display_text(rpg, len);
    }
    if (rpg->dialog_pass == 1) {
        rpg->message = "Tout d'abord pour te deplacer utilise les\n\
fleches directionnelles.";
        len = my_strlen(rpg->message);
        display_text(rpg, len);
    }
    message_two(rpg, len);
}

void win(rpg_t *rpg)
{
    static int i = 0;
    if (rpg->boss->status == 0 && i == 0) {
        sfText_setString(rpg->text_dialog,
        "you win !\nThe boss is dead, you finish the game");
        sfRenderWindow_drawSprite(rpg->windo->window, rpg->dialog, NULL);
        sfRenderWindow_drawText(rpg->windo->window, rpg->text_dialog, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue) {
            i = 1;
        }
    }
}

void box_dialog(rpg_t *rpg, int len)
{
    sfVector2f edd = sfView_getCenter(rpg->windo->view);

    sfSprite_setPosition(rpg->dialog, (sfVector2f){1900, edd.y - 400});
    sfText_setPosition(rpg->text_dialog, (sfVector2f){2200, edd.y + 250});
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue && rpg->dialog_pass < 4) {
        while (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue);
        if (rpg->defil == len) {
            rpg->dialog_pass += 1;
            rpg->defil = 0;
        } else
            rpg->defil = len - 1;
    }
    message(rpg, len);
    win(rpg);
}
