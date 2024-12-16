/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustyilm <mustyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:22:41 by egermen           #+#    #+#             */
/*   Updated: 2024/12/16 12:57:43 by mustyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	read_real_map(t_map *map)
{
	int	i;
	int	j;

	i = map->map_start;
	j = 0;
	map->map = malloc(((map->map_file_height - i) + 2) * sizeof(char *));
	if (!map->map)
		ft_err_mapcontrol("Map malloc error", map, 1);
	while ((map && map->map_file) && map->map_file[i])
	{
		map->map[j] = ft_strdup(map->map_file[i]);
		if (!map->map[j])
			ft_err_mapcontrol("Map strdup error", map, 1);
		i++;
		j++;
	}
	map->map[j] = NULL;
}

void	check_real_map(t_map *map)
{
	int		i;
	int		j;

	if (!map || !map->map)
		ft_err_mapcontrol("Map is not initialized or empty", map, 1);
	i = 0;
	while ((map && map->map) && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr("WESN01 ", map->map[i][j]))
				ft_err_mapcontrol("Wrong character in map", map, 1);
			j++;
		}
		i++;
	}
	if (i == 0)
		ft_err_mapcontrol("Map is empty", map, 1);
}

void	check_real_map_counts(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->player_count = 0;
	while ((map && map->map) && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strchr("NSEW", map->map[i][j]))
			{
				map->player_count++;
				map->pos_x = j;
				map->pos_y = i;
				map->direction = map->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (map->player_count != 1)
		ft_err_mapcontrol("Player count mismatch", map, 1);
}

void	find_height_real_map(t_map *map)
{
	int	i;

	i = 0;
	while ((map && map->map) && map->map[i])
		i++;
	map->map_height = i;
}

void	create_tmp_map(t_map *map)
{
	int	j;

	j = 0;
	map->tmp_map = malloc((map->map_height + 1) * sizeof(char *));
	if (!map->tmp_map)
		ft_err_mapcontrol("Tmp map malloc error", map, 1);
	while (map->map[j])
	{
		map->tmp_map[j] = ft_strdup(map->map[j]);
		if (!map->tmp_map[j])
			ft_err_mapcontrol("Tmp map strdup error", map, 1);
		j++;
	}
	map->tmp_map[j] = NULL;
}
