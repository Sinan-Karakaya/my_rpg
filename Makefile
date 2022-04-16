##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make things
##

SRC = src/core.c \
	  src/const.c \
	  src/args/handle_args.c \
	  src/utils/debug.c \
	  src/shaders/shader.c \
	  src/utils/get_time.c \
	  src/utils/free.c \
	  src/utils/init.c \
	  src/utils/get_rand.c \
	  src/utils/do_aabb.c \
	  src/combat/init_combat.c \
	  src/combat/combat_loop.c \
	  src/combat/hud/guide.c \
	  src/combat/hud/gauge.c \
	  src/combat/hud/slash.c \
	  src/combat/animation/olberic/olberic_cmb_anim.c \
	  src/combat/animation/boss/boss.c \
	  src/map/calcul/calcul.c \
	  src/map/calcul/perlin.c \
	  src/map/create/create.c \
	  src/map/create/csv_reader.c \
	  src/map/draw/draw.c \
	  src/map/init/init.c \
	  src/object/draw/draw.c \
	  src/sounds/musics.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./include/

CFLAGS = -Wall -Wextra -W $(INCLUDE)

LDFLAGS = -Llib/my -lcsfml-window -lcsfml-system -lcsfml-graphics \
		  -lcsfml-audio -lmy

NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/my
	@make clean -C lib/my
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: fclean re

.PHONY: all clean fclean re debug
