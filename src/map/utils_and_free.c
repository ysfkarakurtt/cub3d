/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustyilm <mustyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:22:55 by egermen           #+#    #+#             */
/*   Updated: 2024/12/16 13:12:55 by mustyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx/mlx.h"
#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_exit(char *str, t_game *game, int status)
{
	if (!game)
		err_print_exit(str);
	ft_err2(game);
	if (game->mlxwin != NULL)
	{
		mlx_clear_window(game->mlx, game->mlxwin);
		mlx_destroy_window(game->mlx, game->mlxwin);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (ft_err_mapcontrol(str, game->map, status), 0);
}

void	destroy_image(t_game *game, void *image)
{
	if (image != NULL)
	{
		mlx_destroy_image(game->mlx, image);
		image = NULL;
	}
}

void	free_gamex(t_game *game)
{
	if (game->so)
	{
		free(game->so);
		game->so = NULL;
	}
	if (game->no)
	{
		free(game->no);
		game->no = NULL;
	}
	if (game->we)
	{
		free(game->we);
		game->we = NULL;
	}
	if (game->ea)
	{
		free(game->ea);
		game->ea = NULL;
	}
	if (game->image)
	{
		free(game->image);
		game->image = NULL;
	}
}

void	ft_err2(t_game *game)
{
	if (game->no && game->no->image != NULL)
		destroy_image(game, game->no->image);
	if (game->so && game->so->image != NULL)
		destroy_image(game, game->so->image);
	if (game->we && game->we->image != NULL)
		destroy_image(game, game->we->image);
	if (game->ea && game->ea->image != NULL)
		destroy_image(game, game->ea->image);
	if (game->image && game->image->image != NULL)
		destroy_image(game, game->image->image);
	free_gamex(game);
}

int	ft_err_mapcontrol(char *str, t_map *map, int status)
{
	if (!map)
		err_print_exit(str);
	if (map->one_line_map)
		free(map->one_line_map);
	if (map->tmp_map != NULL)
		free_array2d(map->tmp_map);
	if (map->map)
		free_array2d(map->map);
	if (map->map_file)
		free_array2d(map->map_file);
	if (map->ea_tex_path)
		free(map->ea_tex_path);
	if (map->no_tex_path)
		free(map->no_tex_path);
	if (map->so_tex_path)
		free(map->so_tex_path);
	if (map->we_tex_path)
		free(map->we_tex_path);
	flag_free(map);
	if (status == 1)
		printf("%sError%s\n", RED, RESET);
	printf("%s%s%s\n", YELLOW, str, RESET);
	exit(status);
}
