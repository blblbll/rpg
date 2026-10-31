/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>

#ifndef RPG_H_
    #define RPG_H_

// Sprite sheet of the pnj (assets/perso/PNJ.png): size of a frame, x of the
// first frame of the chosen character, distance between two frames and y of
// each row (front, left, right).
#define PNJ_LEFT 232
#define PNJ_STEP 78
#define PNJ_W 56
#define PNJ_H 91
#define PNJ_ROW_FRONT 0
#define PNJ_ROW_LEFT 108
#define PNJ_ROW_RIGHT 216

typedef struct item_s {
    int empty;
    char *name;
    char *description;
    sfSprite *sprite;
    char *input;
    sfRectangleShape *square;
} item_t;

typedef struct inventaire_s {
    struct item_s **list_item;
    int hand;
} inventaire_t;

typedef struct load_s {
    sfSprite *load;
    sfSprite *font;
    sfIntRect rect;
    sfSprite *load2;
} load_t;

typedef struct window_s {
    sfView *view;
    sfEvent event;
    sfClock *clock;
    sfRenderWindow *window;
    sfVideoMode video_mode;
} window_t;

typedef struct effect_s {
    int door_open;

    sfSprite *door;
    sfSprite *first_door;
    sfSprite *third_door;
    sfSprite *second_door;
    sfRectangleShape *rect;
    sfCircleShape *circle;
} effect_t;

typedef struct boss_s {
    int attack;
    int vie;
    int status;
    sfSprite *boss;
    sfIntRect boss_rect;
    sfVector2f boss_pos;
} boss_t;

typedef struct vilain_s {
    int attack1;
    int vie1;
    int status1;
    int attack2;
    int vie2;
    int status2;
    int attack3;
    int vie3;
    int status3;
    int attack4;
    int vie4;
    int status4;
    int attack5;
    int vie5;
    int status5;
    sfSprite *vilain1;
    sfSprite *vilain2;
    sfSprite *vilain3;
    sfSprite *vilain4;
    sfSprite *vilain5;
    sfIntRect vilain_rect1;
    sfIntRect vilain_rect2;
    sfIntRect vilain_rect3;
    sfIntRect vilain_rect4;
    sfIntRect vilain_rect5;
    sfVector2f vilain1_pos;
    sfVector2f vilain2_pos;
    sfVector2f vilain3_pos;
    sfVector2f vilain4_pos;
    sfVector2f vilain5_pos;
} vilain_t;

typedef struct sound_s {
    int volume;
    int pos_vol;
    char *pass_font;
    int pos_vol_two;

    sfSound *sound_game;
    sfSound *sound_sword;
    sfSound *sound_accueil;
    sfSoundBuffer *sound_buffer;
    sfSoundBuffer *sound_buffer_game;
    sfSoundBuffer *sound_buffer_sword;
    sfVector2f pos_circle;
} sound_t;

typedef struct player_s {
    int sword1;
    int sword2;
    int chest;
    int attack;
    int vie;
    int potion_have;
    int weapon;
    int vitesse;
    int attack_id;
    int direction;
    int have_key;
    sfText *text;
    sfFont *font;
    sfSprite *life;
    sfSprite *sword;
    sfSprite *coffre;
    sfSprite *player;
    sfSprite *interact;
    sfSprite *key;
    sfSprite *xp;
    sfSprite *life_potion;
    sfSprite *power_potion;
    sfSprite *apple;
    sfSprite *gem;
    sfIntRect life_rect;
    sfIntRect player_rect;
    sfIntRect xp_rect;
    sfIntRect rect_chest;
    sfVector2f player_pos;
    sfVector2f xp_pos;
    sfVector2f potion;
    inventaire_t *inv;
} player_t;

typedef struct pnj_a_s {
    int pnj__dialog;
    int mouv_un;
    int mouv_deux;
    int interact;

    sfSprite *pnj;
    sfClock *clock_pnj;
    sfIntRect pnj_rect;
    sfVector2f pnj_pos;
} pnj_a_t;

typedef struct rpg_s {
    int page;
    int defil;
    int option;
    int resume;
    int dialog_pass;
    int dialog_sound;
    float zoom;
    char *message;
    int continue_game;
    sfSprite *font;
    sfSprite *font_floue;
    sfSprite *dialog;
    sfText *text_dialog;
    sfImage *image_font;
    window_t *windo;
    boss_t *boss;
    load_t *load;
    sound_t *sound;
    player_t *player;
    vilain_t *vilain;
    effect_t *effect;
    pnj_a_t *pnj_a;
} rpg_t;

// Fonction
char *my_itoa(int number);
int my_strlen(char const *str);
int t_static(int v, rpg_t *rpg);
int t2_static(int v, rpg_t *rpg);
sfSprite *create_sprite(char *path);
void set_view(rpg_t *rpg, sfVector2f pos, int i);
char *my_strncpy(char *dest, char const *src, int n);
sfIntRect create_rect(int top, int left, int width, int height);
sfText *generate_text(char *text_str, sfVector2f pos, int size, sfColor co);
void character_window(rpg_t *rpg);
void all_bouton_modi(rpg_t *rpg);
void bouton_menu(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
void bouton_character(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
void bouton_optiontwo(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
void bouton_resume(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
inventaire_t *init_inv(void);
void select_slot(rpg_t *rpg, int indice);
void use_item(rpg_t *rpg);
void display_slot(rpg_t *rpg, sfVector2f edd);
void set_status_vilain(rpg_t *rpg);
void flash_red(sfSprite *sprite);
void clear_flash(rpg_t *rpg);

// Main page
void main_page(rpg_t *rpg);
int load_screen(rpg_t *rpg);
void credit_window(rpg_t *rpg);
int gestion_window(rpg_t *rpg, int o, int *o2);
void lose_page(rpg_t *rpg);
void box_dialogg(rpg_t *rpg);

// Bouton
void all_bouton(rpg_t *rpg);
void all_reset(rpg_t *rpg);
void bouton_continue(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
void bouton_quit(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
void bouton_credit(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
void bouton_option(rpg_t *rpg, sfVector2f edd, sfVector2i mouse);
void bouton_start(rpg_t *rpg, sfVector2i mouse);

// Event
void event(rpg_t *rpg);
int attack_val(int nb);
void deplace_map(rpg_t *rpg);
void player_attack(rpg_t *rpg);
int in_dialog(rpg_t *rpg);

// Game
void game(rpg_t *rpg);
void first_chest(rpg_t *rpg);
void second_chest(rpg_t *rpg);
void third_chest(rpg_t *rpg);
void four_chest(rpg_t *rpg);
void fith_chest(rpg_t *rpg);
void six_chest(rpg_t *rpg);
void display_life(rpg_t *rpg);
void pause_window(rpg_t *rpg);
void door_for_boss(rpg_t *rpg);
void all_bouton_modi(rpg_t *rpg);
void boss_detection(rpg_t *rpg);
void pnj_game(rpg_t *rpg);
void chrono_pnj(rpg_t *rpg, sfClock *clock, float secc, int max);
int boss_attack(rpg_t *rpg);
int player_attack_boss(rpg_t *rpg);
void game_boss(rpg_t *rpg);
void box_dialog(rpg_t *rpg, int len);
void vilain_detection(rpg_t *rpg);
int vilain_attack(rpg_t *rpg, sfSprite *vilain, int status);
int player_attack_vilain(rpg_t *rpg);
int hit_sprite(rpg_t *rpg, sfSprite *sprite);
void hit_vilains(rpg_t *rpg, int mode);
void which_mob2(rpg_t *rpg);
void set_color_no_weapon(rpg_t *rpg);
void set_color_weapon(rpg_t *rpg);
void game_vilain(rpg_t *rpg);
void text_un(rpg_t *rpg);
void text_two(rpg_t *rpg);
void text_three(rpg_t *rpg);

// Option
void resolution(rpg_t *rpg);
void option_window(rpg_t *rpg);

// Init
int init_boss(rpg_t *rpg);
int init_vilain(rpg_t *rpg);
int init_sword(rpg_t *rpg);
int init_sound(rpg_t *rpg);
int font_floue(rpg_t *rpg);
int init_player(rpg_t *rpg);
int init_window(rpg_t *rpg);
int init_dialog(rpg_t *rpg);
int init_sprite(rpg_t *rpg);
int init_effect(rpg_t *rpg);
int all_init(rpg_t *rpg, int i);
int init_collision_image(rpg_t *rpg);

// Mouvement
void all_mouv(rpg_t *rpg);
void movement_up(rpg_t *rpg);
void movement_left(rpg_t *rpg);
void movement_down(rpg_t *rpg);
void movement_right(rpg_t *rpg);
void move_rect(sfIntRect *rect, int offset, int max_value);
void chrono_player(rpg_t *rpg, sfClock *clock, float secc, int max);
int touch_bordure(rpg_t *rpg);
int blocked_move(rpg_t *rpg, int dx, int dy);
void update_keys(rpg_t *rpg);
int key_just_pressed(sfKeyCode key);
int touch_player(rpg_t *rpg, sfSprite *sprite, float margin);
void key_consume(sfKeyCode key);
int player_damage(rpg_t *rpg, int mode);
int damage_for(int attack, int mode);
#define INV_SIZE 6
#define MENU_CONTINUE 1
#define MENU_START 2
#define MENU_OPTION 3
#define MENU_CREDIT 4
#define MENU_QUIT 5
#define MENU_RESUME 11
#define MENU_OPTION2 12
#define MENU_CHARACTER 13
#define MENU_MENU 14
#define MENU_SOUND 21
#define MENU_RES1 22
#define MENU_RES2 23
void menu_begin(rpg_t *rpg, const int *ids, int n);
int menu_item(rpg_t *rpg, sfVector2i mouse, int id);
int menu_edge(sfKeyCode key);
int menu_selected(int id);
int menu_moved(void);
void menu_select(int id);
void level_up(rpg_t *rpg);
void reset_level(void);
void reset_second_chest(void);
void reset_third_chest(void);
void reset_four_chest(void);
void reset_fith_chest(void);
void reset_six_chest(void);
void set_stat(rpg_t *rpg);
void reset_world(rpg_t *rpg);
int attack_val(int nb);
void fit_sprite(sfSprite *sprite, sfVector2f center, float size);
int has_free_slot(rpg_t *rpg);
void give_item(rpg_t *rpg, char *name, char *desc, sfSprite *sprite);
void draw_level_up(rpg_t *rpg);

// Attack
void attack_id_no_w(rpg_t *rpg);
void attack_no_weapon(rpg_t *rpg, int fire);
void attack_id(rpg_t *rpg);
void attack_with_weapon(rpg_t *rpg, int fire);
int attack_step_ready(int reset);

// Destroy
void all_destroy(rpg_t *rpg);
void destroy_boss(rpg_t *rpg);
void destroy_window(rpg_t *rpg);
void destroy_sound(rpg_t *rpg);
void destroy_effect(rpg_t *rpg);
void destroy_player(rpg_t *rpg);
void destroy_pnj(rpg_t *rpg);

#endif /* !RPG_H_ */
