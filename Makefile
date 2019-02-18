##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## For minishell1
##

SRC_DIR=	$(realpath ./src)

LIB_DIR=	$(realpath ./lib/my)

INC_DIR=	$(realpath ./include)

SRC=		$(SRC_DIR)/main.c\
			$(SRC_DIR)/array_utilities.c\
			$(SRC_DIR)/env_utilities.c\
			$(SRC_DIR)/interpreter.c\
			$(SRC_DIR)/get_entry.c\
			$(SRC_DIR)/cd.c\
			$(SRC_DIR)/env_search.c\
			$(SRC_DIR)/alpha_checker.c\

LIB=		my

OBJ=		$(SRC:.c=.o)

NAME=		mysh

#Arguments gcc
GCC_ARG=	-L$(LIB_DIR) -l$(LIB) -I$(INC_DIR)
GCC_ARG_DEBUG= -L$(LIB_DIR) -l$(LIB) -I$(INC_DIR) -g

#Règles
all:		$(NAME)

$(NAME):
		make -C ./lib/my
		make clean -C ./lib/my
		gcc -o $(NAME) $(SRC) $(GCC_ARG)

debug:
		gcc -o $(NAME) $(SRC) $(GCC_ARG_DEBUG)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: fclean all
