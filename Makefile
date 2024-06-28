NAME		= game

INC			= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/
RAYLIB_LIB	= -lraylib
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++11 -I$(INC)

RM			= rm -f

SRC			=	$(SRC_DIR)main.cpp \
				$(SRC_DIR)game.cpp \
				$(SRC_DIR)map.cpp \
				$(SRC_DIR)display.cpp \

OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(RAYLIB_LIB) $(CFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
