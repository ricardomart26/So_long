
CC = gcc -Wall -Werror -Wextra 

LIBX = -lmlx -framework OpenGL -framework AppKit

SRC = $(wildcard src/*.c)

LIBFT_EXEC = libft/libft.a
LIBFT_DIR = libft

INCLUDE = includes/so_long.h

SRC = ${wildcard src/*.c}

OBJS = $(SRC:.c=.o)

NAME = so_long

all : $(NAME)

$(NAME): $(LIBFT_EXEC) $(OBJS)
	$(CC) $(LIBX) $(LIBFT_EXEC) $(OBJS) -o $(NAME)

$(LIBFT_EXEC):
	$(MAKE) -C $(LIBFT_DIR)

clean: 
	$(MAKE) -C $(LIBFT_DIR) clean
	rm $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
