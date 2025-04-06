##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile for project
##

NAME = my_rpg

OBJ = $(SRC:.c=.o)

SRC =  	src/main.c \
		src/gestion_window.c \
		src/load_page.c \
		src/fonction/fonction_for_sprite.c \
		src/fonction/fonction_for_csfml.c \
		src/fonction/my_strlen.c \
		src/fonction/my_strncpy.c \
		src/fonction/my_itoa.c \
		src/main_page/credit_window.c \
		src/main_page/bouton.c \
		src/main_page/bouton_two.c \
		src/main_page/main_page.c \
		src/main_page/option_window.c \
		src/main_page/resolution.c \
		src/main_page/character_window.c \
		src/main_page/character_window_inv.c \
		src/init/all_init.c \
		src/init/init_effect_for_boss.c \
		src/init/init_windows.c \
		src/init/init_sprite.c \
		src/init/init_sound.c \
		src/init/init_players.c \
		src/init/init_boss.c \
		src/init/init_vilain.c \
		src/init/init_inv.c \
		src/game/door_boss.c \
		src/game/game.c \
		src/game/pnj.c \
		src/game/pnj_two.c \
		src/game/player_life.c \
		src/game/pause_window.c \
		src/game/new_bouton.c \
		src/game/box_dialog.c \
		src/game/chest/first_chest.c \
		src/game/chest/second_chest.c \
		src/game/chest/third_chest.c \
		src/game/chest/four_chest.c \
		src/game/chest/fith_chest.c \
		src/game/chest/six_chest.c \
		src/game/all_bouton_modif.c \
		src/event/mouvement.c \
		src/event/mouvement_two.c \
		src/event/mouvement_third.c \
		src/event/event.c \
		src/event/move_map.c \
		src/event/attack/attack.c \
		src/event/attack/attack_no_weapon.c \
		src/event/attack/attack_no_weapon_two.c \
		src/event/attack/attack_weapon_two.c \
		src/event/attack/attack_weapon.c \
		src/boss/boss_mouvement.c \
		src/boss/boss_attack.c \
		src/boss/boss_life.c \
		src/boss/vilain_mouvement.c \
		src/boss/vilain_attack.c \
		src/boss/vilain_life.c \
		src/boss/game_vilain.c \
		src/destroy/all_destroy.c \
		src/destroy/destroy_sup.c

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

CFLAGS = -I./include/ -Wall -Wextra -g -lm

cc = gcc

all: $(NAME)

.SILENT: $(OBJ)

$(NAME): $(OBJ)
	@echo "\033[32;01m[--------make-------------]\033[;0m"
	@echo "gcc $(OBJ) -o $(NAME) $(CFLAGS)"
	@$(cc) $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

clean :
	@echo "\033[31;01m--------make clean-------------\033[;0m"
	rm -f $(OBJ)

fclean : clean
	@echo "\033[31;01m--------make fclean-------------\033[;0m"
	rm -f $(NAME)

re : fclean all
