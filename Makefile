NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC = ./mandatory/game.c \
	  ./mandatory/get_next_line.c \
	  ./mandatory/get_next_line_utils.c \
	  ./mandatory/map_build.c \
	  ./mandatory/parssing/parssing.c \
	  ./mandatory/move/up.c \
	  ./mandatory/move/down.c \
	  ./mandatory/move/left.c \
	  ./mandatory/move/right.c \
	  ./mandatory/move/check_exit.c \
	  ./mandatory/move/close_game.c \
	  ./mandatory/move/esc.c \
	  ./mandatory/parssing/flood_fill.c \
	  ./mandatory/player_movement.c
SRC_BONUS = ./bonus/game_bonus.c \
			./bonus/get_next_line_bonus.c \
			./bonus/get_next_line_utils_bonus.c \
			./bonus/map_build_bonus.c \
			./bonus/parssing/parssing_bonus.c \
			./bonus/move/up_bonus.c \
			./bonus/move/down_bonus.c \
			./bonus/move/left_bonus.c \
			./bonus/move/right_bonus.c \
			./bonus/move/check_exit_bonus.c \
			./bonus/move/close_game_bonus.c \
			./bonus/move/esc_bonus.c \
			./bonus/parssing/flood_fill_bonus.c \
			./bonus/player_movement_bonus.c \
			./bonus/money_flip.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./mandatory/so_long.h
	@$(CC) $(CFLAGS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJ_BONUS) ./bonus/so_long_bonus.h
	@$(CC) $(CFLAGS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ_BONUS)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all