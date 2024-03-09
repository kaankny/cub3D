NAME = cub3D
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

SRC = source/main.c memory/memory.c memory/memory_utils.c memory/ft_calloc.c \
		source/init/file_check.c \
		source/init/game_init.c source/init/map_init.c \
		source/utils/utils.c  source/utils/utils_two.c source/utils/utils_three.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		source/checker/map_check.c source/checker/map_check_utils.c \
		source/pathfinder/pathfinder.c source/game/game.c source/game/player_movement.c source/game/player_rotation.c \
		source/init/map_init2.c source/init/utils.c source/init/utils2.c \
		source/math/math.c source/math/draw.c source/math/math2.c \
		source/game/key_hook.c

OBJ = $(SRC:.c=.o)

MINILIBX_PATH = ./minilibx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
MINILIBX_FLAGS = -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MINILIBX) $(MINILIBX_FLAGS)
	@echo "\033[0;32mCub3D compiled\033[0m [✓]"

$(MINILIBX):
	@make -C $(MINILIBX_PATH)

clean:
	@make clean -C $(MINILIBX_PATH)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

kaan: all clean

.PHONY: all clean fclean re

# $(MINILIBX) $(MINILIBX_FLAGS)
# make -C $(MINILIBX_PATH)
# 
# all: $(NAME)
# 
# $(NAME): $(OBJ) $(MINILIBX)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MINILIBX) $(MINILIBX_FLAGS)
# 
# $(MINILIBX):
# 	make -C $(MINILIBX_PATH)
# 
# clean:
# 	$(RM) $(OBJ)
# 
# fclean: clean
# 	$(RM) $(NAME)
# 
# kaan: all clean
# 
# re: fclean all
# 
# .PHONY: all clean fclean re kaan