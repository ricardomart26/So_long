
CC = gcc -Wall -Werror -Wextra 

LIBX = -lmlx -framework OpenGL -framework AppKit
# MLXARQUIVE = minilibx_opengl_20191021/libmlx.a

SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)

NAME = so_long

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LIBX) $(OBJS) -o $(NAME)

clean: 
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re