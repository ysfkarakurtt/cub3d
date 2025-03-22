/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_real.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:40:31 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:40:32 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

void real_map_reading(t_map *map)
{
	int a;
	int b;

	a = map->map_start;
	b = 0;
	map->map = malloc(((map->map_file_height - a) + 2) * sizeof(char *));
	if (!map->map)
		ft_err_mapcontrol("Map malloc error", map, 1);
	while ((map && map->map_file) && map->map_file[a])
	{
		map->map[b] = ft_strdup(map->map_file[a]);
		if (!map->map[b])
			ft_err_mapcontrol("Map strdup error", map, 1);
		a++;
		b++;
	}
	map->map[b] = NULL;
}

void real_map_checking_counter(t_map *map)
{
	int a;
	int b;

	a = 0;
	map->player_count = 0;
	while ((map && map->map) && map->map[a])
	{
		b = 0;
		while (map->map[a][b])
		{
			if (ft_strchr("NSEW", map->map[a][b]))
			{
				map->player_count++;
				map->pos_x = b;
				map->pos_y = a;
				map->direction = map->map[a][b];
			}
			b++;
		}
		a++;
	}
	if (map->player_count != 1)
		ft_err_mapcontrol("Player count mismatch", map, 1);
}

void real_map_checking(t_map *map)
{
	int a;
	int b;

	if (!map || !map->map)
		ft_err_mapcontrol("Map is not initialized or empty", map, 1);
	a = 0;
	while ((map && map->map) && map->map[a])
	{
		b = 0;
		while (map->map[a][b])
		{
			if (!ft_strchr("WESN01 ", map->map[a][b]))
				ft_err_mapcontrol("Incorrect character in map", map, 1);
			b++;
		}
		a++;
	}
	if (a == 0)
		ft_err_mapcontrol("Map is empty", map, 1);
}

void temp_map_creating(t_map *map)
{
	int b;

	b = 0;
	map->temp_map = malloc((map->map_height + 1) * sizeof(char *));
	if (!map->temp_map)
		ft_err_mapcontrol("Tmp map malloc error", map, 1);
	while (map->map[b])
	{
		map->temp_map[b] = ft_strdup(map->map[b]);
		if (!map->temp_map[b])
			ft_err_mapcontrol("Tmp map strdup error", map, 1);
		b++;
	}
	map->temp_map[b] = NULL;
}

void real_map_finding_height(t_map *map)
{
	int a;

	a = 0;
	while ((map && map->map) && map->map[a])
		a++;
	map->map_height = a;
}