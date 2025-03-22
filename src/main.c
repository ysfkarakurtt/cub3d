/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:03 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/31 13:37:05 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "./libft/libft.h"
#include "cub3d.h"
#include <stdlib.h>

static void arg_checking(int ac, char *av, t_game *game)
{
	int a;

	if (ac != 2)
		exiting("Wrong number of arguments", game, 1);
	a = ft_strlen(av);
	if (a < 10)
		exiting("Wrong file name", game, 1);
	if (av[a - 1] != 'b' || av[a - 2] != 'u' || av[a - 3] != 'c' || av[a - 4] != '.')
		exiting("Wrong file extension", game, 1);
}

int ft_mlx_exit(t_game *game)
{
	return (exiting("exit successful", game, 0));
}

void column_rend(t_game *game, int x, int y)
{
	while (++y < HEIGHT)
	{
		game->ray->texy = (int)game->ray->texpos;
		if (y < game->ray->drawstart)
			game->image->addr[y * WIDTH + x] = game->map->c_color;
		else if (y > game->ray->drawend)
			game->image->addr[y * WIDTH + x] = game->map->f_color;
		else
		{
			if (game->ray->side == 1 && game->ray->raydiry < 0)
				game->image->addr[y * WIDTH + x] = game->no->addr[TEXHEIGHT * game->ray->texy + game->ray->texx];
			else if (game->ray->side == 1 && game->ray->raydiry >= 0)
				game->image->addr[y * WIDTH + x] = game->so->addr[TEXHEIGHT * game->ray->texy + game->ray->texx];
			if (game->ray->side == 0 && game->ray->raydirx < 0)
				game->image->addr[y * WIDTH + x] = game->we->addr[TEXHEIGHT * game->ray->texy + game->ray->texx];
			else if (game->ray->side == 0 && game->ray->raydirx >= 0)
				game->image->addr[y * WIDTH + x] = game->ea->addr[TEXHEIGHT * game->ray->texy + game->ray->texx];
			game->ray->texpos += game->step;
		}
	}
}

static void flag_init(t_map *map)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		ft_err_mapcontrol("Flags malloc error", map, 1);
	map->flags = flags;
}

int main(int ac, char **av)
{
	t_game game;
	t_map map;
	t_player player;
	t_ray ray;

	arg_checking(ac, av[1], NULL);
	game.map = &map;
	flag_init(&map);
	game.p = &player;
	game.ray = &ray;
	map.map_file_path = av[1];
	controller_map(&map);
	init_raycast(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exiting("Failed to initialize MLX", &game, 1);
	game.mlxwin = mlx_new_window(game.mlx, WIDTH, HEIGHT, "cub3D");
	ft_mlx(&game, 0, 0);
	mlx_hook(game.mlxwin, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlxwin, 3, 1L << 1, action_drop, &game);
	mlx_hook(game.mlxwin, 17, 1L << 17, ft_mlx_exit, &game);
	mlx_loop_hook(game.mlx, &gamefunc, &game);
	mlx_loop(game.mlx);
	return (0);
}
