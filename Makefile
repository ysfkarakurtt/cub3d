NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  ./src/main.c ./src/map/free_and_utils_2.c ./src/map/controller_map.c \
		./src/map/controller_map_utils.c ./src/map/controller_map_utils_2.c \
		./src/map/parser_map_dir.c ./src/map/parser_map_dir_2.c ./src/map/map_real.c \
		./src/map/free_and_utils.c ./src/raycast/raycasting_algo.c ./src/raycast/raycasting_algo_2.c ./src/raycast/raycasting_algo_3.c \
		./src/raycast/raycasting_algo_4.c ./src/libft/ft_isdigit.c ./src/libft/ft_strlen.c \
		./src/libft/get_next_line.c ./src/libft/ft_printf.c ./src/libft/ft_split.c ./src/map/controller_map_utils_3.c \
		./src/libft/ft_strchr.c ./src/libft/ft_strdup.c ./src/libft/ft_strjoin.c ./src/libft/ft_strlcpy.c \
		./src/libft/ft_strncmp.c ./src/libft/ft_substr.c ./src/libft/ft_atoi.c \
		./src/raycast/raycasting_algo_5.c ./src/map/separate.c \
		./src/map/separate_2.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

MLX = ./minilibx/libmlx_libmlx.a
LIBS = -L./minilibx -lmlx -lGL -lX11 -lXext  -lm

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C minilibx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(MLX):
	@$(MAKE) -C minilibx

clean:
	@$(MAKE) -C minilibx clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
