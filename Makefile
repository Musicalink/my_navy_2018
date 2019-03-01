##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## For navy
##

SRC_DIR=	$(realpath ./src)

LIB_DIR=	$(realpath ./lib/my)

INC_DIR=	$(realpath ./include)

SRC=		$(SRC_DIR)/main.c\
			$(SRC_DIR)/static.c\
			$(SRC_DIR)/connection_func.c\
			$(SRC_DIR)/packet_handler.c\
			$(SRC_DIR)/parsing.c\
			$(SRC_DIR)/def_pos_map.c\
			$(SRC_DIR)/declare_map.c\
			$(SRC_DIR)/try_open_file.c\
			$(SRC_DIR)/get_next_line.c\
			$(SRC_DIR)/shot_gestionary.c\

LIB=		my

OBJ=		$(SRC:.c=.o)

NAME=		navy

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
