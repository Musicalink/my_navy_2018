##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## For infinadd
##

SRC=		my_putstr.c\
		my_strcpy.c\
		my_getnbr.c\
		my_show_word_array.c\
		my_strlen.c\
		my_putchar.c\
		my_strcmp.c\
		my_str_to_word_array.c\
		my_strdup.c\
		my_revstr.c\
		my_intlen.c\
		my_itoa.c\
		my_tablen.c\
		free_tab.c\
		remove_i_char.c\
		remove_i_line.c\
		my_atoi.c\
		my_put_nbr.c\
		my_strcat.c\

OBJ =	$(SRC:.c=.o)

NAME = libmy.a

#Règles
all:			$(NAME)

$(NAME):		$(OBJ)
			ar cru libmy.a $(OBJ)
			cp my.h ../../include

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re: fclean all
