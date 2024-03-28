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
	  ./mandatory/player_movement.c \
	  ./mandatory/ft_printf.c \
	  ./mandatory/ft_putnbr.c \
	  ./mandatory/ft_printf_char.c \
	  ./mandatory/parssing/check_file_map.c \
	  ./mandatory/read_map.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./mandatory/so_long.h
	$(CC) $(CFLAGS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all