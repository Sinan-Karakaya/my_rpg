##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make things
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all:
	gcc -c $(SRC)
	ar rc libmy.a $(OBJ)
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ)

$(VERBOSE).SILENT:
