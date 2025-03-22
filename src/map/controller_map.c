/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:35:13 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:35:14 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void trip_map(t_map *map, int y, int x)
{
	if (x < 0 || y < 0 || y >= map->map_height || x >= (int)ft_strlen(map->temp_map[y]) || map->temp_map[y][x] == ' ' || map->temp_map[y][x] == '\0')
	{
		ft_err_mapcontrol("Wrong map", map, 1);
	}
	else if (map->temp_map[y][x] == '1')
		return;
	map->temp_map[y][x] = '1';
	trip_map(map, y, x - 1);
	trip_map(map, y - 1, x);
	trip_map(map, y, x + 1);
	trip_map(map, y + 1, x);
}

void struct_init_2(t_map *map)
{
	map->pos_y = 0;
	map->pos_x = 0;
	map->player_count = 0;
	map->f_color = 0;
	map->c_color = 0;
	map->map_height = 0;
	map->north_structure_path = NULL;
	map->east_structure_path = NULL;
	map->south_structure_path = NULL;
	map->west_structure_path = NULL;
	map->map = NULL;
	map->temp_map = NULL;
	map->map_file = NULL;
}

void struct_init_1(t_map *map)
{
	map->flags->f_flag = 0;
	map->flags->c_flag = 0;
	map->flags->flag_count = 0;
	map->flags->north_flag = 0;
	map->flags->south_flag = 0;
	map->flags->west_flag = 0;
	map->flags->east_flag = 0;
	map->flags->if_flag = 0;
	map->map_start = 0;
	struct_init_2(map);
}

void controller_map(t_map *map)
{
	int end_of_direction;

	end_of_direction = 0;
	struct_init_1(map);
	read_map(map);
	map_dimension(map);
	end_of_direction = controller_map_sixth(map);
	space_jump(map, end_of_direction);
	real_map_reading(map);
	real_map_checking(map);
	real_map_checking_counter(map);
	real_map_finding_height(map);
	temp_map_creating(map);
	trip_map(map, map->pos_y, map->pos_x);
}
