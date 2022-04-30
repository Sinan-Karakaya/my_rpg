##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make things
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ)

$(VERBOSE).SILENT:
