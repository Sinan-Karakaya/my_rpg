##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make things
##

SRC = src/core.c	\
	  src/loop.c	\
	  src/const.c	\
	  src/event.c	\
	  src/loading/load.c	\
	  src/args/handle_args.c \
	  src/utils/debug.c \
	  src/shaders/shader.c \
	  src/utils/get_time.c \
	  src/utils/free.c \
	  src/utils/init.c \
	  src/utils/get_rand.c \
	  src/utils/do_aabb.c \
	  src/utils/get_ob_pos.c \
	  src/quest/quest.c \
	  src/combat/init_combat.c \
	  src/combat/combat_loop.c \
	  src/combat/hud/guide.c \
	  src/combat/hud/gauge.c \
	  src/combat/hud/slash.c \
	  src/combat/animation/olberic/olberic_cmb_anim.c \
	  src/combat/animation/boss/boss.c \
	  src/map/calcul/calcul.c \
	  src/map/calcul/perlin.c \
	  src/map/update/check_npc.c \
	  src/map/create/create.c \
	  src/map/create/csv_reader.c \
	  src/map/fill/map_filler.c \
	  src/map/draw/draw.c \
	  src/map/draw/draw_all.c \
	  src/map/draw/draw_bis.c \
	  src/map/draw/draw_npc.c \
	  src/map/draw/light.c \
	  src/map/init/init.c \
	  src/map/init/init_bis.c \
	  src/menu/init/init_bis.c \
	  src/menu/init/init.c \
	  src/menu/draw/draw.c \
	  src/sounds/musics.c	\
	  src/menu/main_menu/main_menu.c \
	  src/menu/main_menu/button_controls.c \
	  src/menu/buttons/click_button.c \
	  src/menu/buttons/init_button.c \
	  src/menu/buttons/init_button_bis.c \
	  src/menu/buttons/create_buttons.c \
	  src/menu/options/display_keybind.c \
	  src/menu/options/keybindings.c \
	  src/menu/main_menu/display_buttons.c \
	  src/menu/options/option_ig.c \
	  src/menu/options/display_options_ig.c \
	  src/menu/inventory/print_inventory.c	\
	  src/menu/inventory/init_slots_inventory.c	\
	  src/menu/inventory/manage_inv.c	\
	  src/menu/inventory/slots_controls.c	\
	  src/menu/inventory/utils.c	\
	  src/menu/inventory/utils_bis.c	\
	  src/menu/inventory/init_text.c	\
	  src/menu/inventory/init_stats.c	\
	  src/overworld/oveworld_loop.c \
	  src/overworld/player_overworld.c \
	  src/overworld/collision.c \
	  src/save/read_save.c \
	  src/save/make_save.c \
	  src/utils/y_sorter.c \
	  src/combat/combat_transition.c \
	  src/menu/game_over/game_over.c \
	  src/errors_manager/errors_manager.c \
	  src/menu/class_menu/class_menu.c \
	  src/combat/init_bis_bis.c \
	  src/combat/animation/ennemies/ennemies.c \
	  src/combat/spawn_ennemy.c \
	  src/combat/utils_inventory.c \
	  src/utils/cam_bounds.c \
	  src/combat/check_stats.c \
	  src/cinematic/cinematic.c \
	  src/cinematic/init_cine.c \
	  src/errors_messages.c	\
	  src/combat/heal.c \
	  src/combat/init_combat_bis.c \
	  src/menu/main_menu/key_bindings_menu.c \
	  src/end_game.c \
	  src/menu/destroy.c \
	  src/combat/destroy.c \
	  src/menu/options/keybindings_bis.c \
	  src/save/read_save_bis.c \
	  src/init_sfml.c \
	  src/map/destroy_world.c \

OBJ = $(SRC:.c=.o)
TMP = $(SRC:.c=.c.tmp)

INCLUDE = -I ./include/

CFLAGS = -Wall -Wextra -W $(INCLUDE)

LDFLAGS = -Llib/my -lcsfml-window -lcsfml-system -lcsfml-graphics \
		  -lcsfml-audio -lmy -lm

NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C lib/my
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(TMP)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
