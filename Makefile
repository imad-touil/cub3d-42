NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = ./sources/main.c\
      ./get_next_line/get_next_line.c\
      ./get_next_line/get_next_line_utils.c\
	  ./parsing/parser.c\
	  ./parsing/utils.c\
	  ./parsing/parse_texture.c\
	  ./parsing/parse_ceiling.c\
	  ./parsing/parse_floor.c\
	  ./parsing/parse_map.c\

OBJ = $(SRC:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean