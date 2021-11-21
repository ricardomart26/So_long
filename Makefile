
CC = gcc -Wall -Werror -Wextra -fpie

LIBX = -lmlx -framework OpenGL -framework AppKit

SRC = $(wildcard src/*.c)

LIBFT_EXEC = libft/libft.a
LIBFT_DIR = libft
MINILIBX_DIR = minilibx_mms_20200219


INCLUDE = includes/so_long.h

SRC = ${wildcard src/*.c}

OBJS = $(SRC:.c=.o)

NAME = so_long
HDRS = includes

all : $(NAME)

compile_libs:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)
	@mv $(MINILIBX_DIR)/libmlx.dylib .
	@mv $(LIBFT_DIR)/libft.a .

$(NAME): compile_libs $(OBJS)
	@$(CC) $(LIBX) -L. -lft -I $(HDRS) $(OBJS) -o $(NAME)

clean: 
	@rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -fr libft.a
	rm -f $(NAME)
	rm -f libmlx.dylib

re: fclean $(NAME)

.PHONY: all clean fclean re
