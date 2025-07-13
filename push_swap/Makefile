NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
LIBFT_DIR = libft

SRC = ./src/push_swap.c ./src/joinargs.c ./src/validation.c ./src/op.c \
      ./src/op1.c ./src/op2.c ./src/op3.c ./src/stack.c ./src/index.c \
	  ./src/stack1.c ./src/index1.c ./src/sort_stack.c ./src/position.c \
	  ./src/stack2.c 
	  

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
