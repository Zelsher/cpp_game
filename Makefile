NAME		= game

INC			= inc/

SRC_DIR		= src/
GAME_DIR	= src/game/
DISPLAY_DIR	= src/display/
PLAYER_DIR	= src/player/
ITEM_DIR	= src/item/
MAP_DIR		= src/map/
EVENT_DIR	= src/event/
MOB_DIR		= src/mob/
BOSS_DIR	= src/boss/


#CFLAGS = -I/path/to/raylib/include
#LDFLAGS = -L/path/to/raylib/lib -lraylib -framework CoreFoundation -framework IOKit

OBJ_DIR		= obj/
RAYLIB_LIB	= -lraylib
#RAYLIB_LIB	= inc/raylib/src/libraylib-mac.a -framework CoreFoundation -framework IOKit -framework AppKit -framework OpenGL

CC			= c++
CFLAGS		= -g -Wall -Wextra -Werror -std=c++11 -I$(INC)

RM			= rm -f

SRC			=	$(GAME_DIR)main.cpp \
				$(GAME_DIR)game.cpp \
				$(GAME_DIR)input.cpp \
				$(DISPLAY_DIR)display.cpp \
				$(DISPLAY_DIR)frame.cpp \
				$(PLAYER_DIR)player.cpp \
				$(PLAYER_DIR)inventory.cpp \
				$(PLAYER_DIR)player_utils.cpp \
				$(ITEM_DIR)item.cpp \
				$(ITEM_DIR)item_use.cpp \
				$(ITEM_DIR)ressource.cpp \
				$(MAP_DIR)map.cpp \
				$(MAP_DIR)cell.cpp \
				$(MAP_DIR)utils.cpp \
				$(EVENT_DIR)event.cpp \
				$(EVENT_DIR)happening.cpp \
				$(MOB_DIR)mob.cpp \
				$(BOSS_DIR)boss.cpp \
				$(MOB_DIR)action.cpp \

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
