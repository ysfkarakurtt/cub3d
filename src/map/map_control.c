/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustyilm <mustyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:22:25 by egermen           #+#    #+#             */
/*   Updated: 2024/12/09 16:13:12 by mustyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
#include "../libft/libft.h"

void	init_struct2(t_map *map)
{
	map->pos_x = 0;
	map->pos_y = 0;
	map->player_count = 0;
	map->c_color = 0;
	map->f_color = 0;
	map->map_height = 0;
	map->ea_tex_path = NULL;
	map->we_tex_path = NULL;
	map->no_tex_path = NULL;
	map->so_tex_path = NULL;
	map->map = NULL;
	map->tmp_map = NULL;
	map->map_buff = NULL;
	map->map_file = NULL;
}

void	init_struct(t_map *map)
{
	map->flags->c_flag = 0;
	map->buff_flags->c_flag = 0;
	map->flags->f_flag = 0;
	map->buff_flags->f_flag = 0;
	map->flags->ea_flag = 0;
	map->buff_flags->ea_flag = 0;
	map->flags->flag_count = 0;
	map->buff_flags->flag_count = 0;
	map->flags->we_flag = 0;
	map->buff_flags->we_flag = 0;
	map->flags->no_flag = 0;
	map->buff_flags->no_flag = 0;
	map->flags->so_flag = 0;
	map->buff_flags->so_flag = 0;
	map->flags->if_flag = 0;
	map->map_start = 0;
	init_struct2(map);
}

void travel_map(t_map *map, int y, int x)
{
    if (x < 0 || y < 0 || y >= map->map_height || x >= (int)ft_strlen(map->tmp_map[y]) 
        || map->tmp_map[y][x] == ' ' || map->tmp_map[y][x] == '\0')
        ft_err_mapcontrol("Wrong map", map, 1);
    else if (map->tmp_map[y][x] == '1')
    	return;
    map->tmp_map[y][x] = '1';
    travel_map(map, y, x - 1);
    travel_map(map, y - 1, x);
    travel_map(map, y, x + 1);
    travel_map(map, y + 1, x);
}

void	map_control(t_map *map)
{
	int	directions_end;

	directions_end = 0;
	init_struct(map);
	mapread(map);
	map_size(map);
	directions_end = map_sixthcontrol(map);
	skip_spaces(map, directions_end);
	func(map);
	func2(map);
	read_real_map(map);
	check_real_map(map);
	check_real_map_counts(map);
	find_height_real_map(map);
	create_tmp_map(map);
	travel_map(map, map->pos_y, map->pos_x);
}
