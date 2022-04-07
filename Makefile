##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make things
##

SRC = src/core.c \
	  src/const.c \
	  src/utils/get_time.c \
	  src/utils/free.c \
	  src/utils/init.c \
	  src/utils/do_aabb.c \
	  src/combat/init_combat.c \
	  src/combat/combat_loop.c \
	  src/combat/hud/guide.c \
	  src/combat/animation/olberic/olberic_cmb_anim.c
	  src/map/calcul/calcul.c \
	  src/map/create/create.c \
	  src/map/draw/draw.c


OBJ = $(SRC:.c=.o)

INCLUDE = -I ./include/

CFLAGS = -Wall -Wextra -W $(INCLUDE)

LDFLAGS = -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: fclean re

.PHONY: all clean fclean re debug
