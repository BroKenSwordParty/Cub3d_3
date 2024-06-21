NAME = cub3D

SRC = src/main.c\
		src/arg_check.c\
		src/map_error.c\
		src/map_check.c\
		src/mlx_things.c\
		src/file_check.c\
		src/mlx_things.c\
		src/utils.c\
		src/file_utils.c\
		src/raycasting.c\
		src/game_manager.c\
		src/draw_map.c\
		src/draw_textures.c\
		src/draw_terminal.c\
		src/cam_movements.c\
		src/get_movements.c\
		src/player.c\

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a #-Llibft -lft
LIBX = mlx/libmlx.a #-Lmlx -lmlx
CC = cc -g3 -fsanitize=address
FLAGS = -Wall -Wextra -Werror

RM = rm -rf
MLX = -L/mlx -lmlx -lXext -lX11 -lm
SAN = -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@ -Imlx

$(NAME): $(OBJS)
	@make -C mlx/
	@make -C libft/
	@$(CC) $(FLAGS) $^ -o $@ $(LIBFT) $(MLX)
	@echo "Done. "

clean:
	$(RM) $(OBJS)
	@make clean -C mlx/
	@make clean -C libft/

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re