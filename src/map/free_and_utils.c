/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:37:49 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:37:50 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx/mlx.h"
#include "../cub3d.h"
#include <stdlib.h>
#include <stdio.h>

int exiting(char *str, t_game *game, int status)
{
	if (!game)
		error_exit_printing(str);
	error_2(game);
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

void destroy_image(t_game *game, void *image)
{
	if (image != NULL)
	{
		mlx_destroy_image(game->mlx, image);
		image = NULL;
	}
}

void free_gamex(t_game *game)
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

int ft_err_mapcontrol(char *str, t_map *map, int status)
{
	if (!map)
		error_exit_printing(str);
	if (map->one_line_map)
		free(map->one_line_map);
	if (map->temp_map != NULL)
		free_array2d(map->temp_map);
	if (map->map)
		free_array2d(map->map);
	if (map->map_file)
		free_array2d(map->map_file);
	if (map->east_structure_path)
		free(map->east_structure_path);
	if (map->north_structure_path)
		free(map->north_structure_path);
	if (map->south_structure_path)
		free(map->south_structure_path);
	if (map->west_structure_path)
		free(map->west_structure_path);
	flag_free(map);
	if (status == 1)
		printf("%sError%s\n", RED, RESET);
	printf("%s%s%s\n", BLUE, str, RESET);
	exit(status);
}

void error_2(t_game *game)
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
