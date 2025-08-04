NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
LIBFT_DIR = libft
MLX_DIR = mlx_linux

SRC = ./src/main.c ./src/map.c ./src/get_next_line_utils.c ./src/get_next_line.c \
    ./src/flood_fill.c ./src/utils.c ./src/init.c ./src/movement.c ./src/render.c \
    ./src/read.c  

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx_Linux -lX11 -lXext $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re