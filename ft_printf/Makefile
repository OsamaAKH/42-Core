NAME	= libftprintf.a

SRCS	= ./srcs/ft_printf.c \
		./srcs/hexa.c \
		./srcs/int.c \
		./srcs/ptr.c \
		./srcs/str.c \
		./srcs/unsigned.c \

OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
