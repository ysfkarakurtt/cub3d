NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  ./src/main.c ./src/map/utils_and_free2.c ./src/map/map_control.c \
		./src/map/map_control_utils.c ./src/map/map_control_utils2.c \
		./src/map/map_directions_parser.c ./src/map/map_directions_parser2.c ./src/map/real_map.c \
		./src/map/utils_and_free.c ./src/raycast/raycast.c ./src/raycast/raycast2.c ./src/raycast/raycast3.c \
		./src/raycast/raycast4.c ./src/libft/ft_isdigit.c ./src/libft/ft_strlen.c \
		./src/libft/get_next_line.c ./src/libft/ft_printf.c ./src/libft/ft_split.c ./src/map/map_control_utils3.c \
		./src/libft/ft_strchr.c ./src/libft/ft_strdup.c ./src/libft/ft_strjoin.c ./src/libft/ft_strlcpy.c \
		./src/libft/ft_strncmp.c ./src/libft/ft_substr.c ./src/libft/ft_atoi.c \
		./src/raycast/raycast5.c ./src/map/split.c \
		./src/map/split2.c
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
