CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = cub3d

all:
	@make -C libft
	@mv libft/libft.a .
	@$(CC) $(CFLAGS) main.c libft.a -o $(NAME)

clean:
	@make fclean -C libft
	@rm -rf libft.a $(NAME)

re: clean all