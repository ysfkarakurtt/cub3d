/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:51:31 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/31 13:51:33 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>

static void controller_mapler_all(t_map *map, int x)
{
	south_controller_mapler(map, x);
	north_controller_mapler(map, x);
	west_controller_mapler(map, x);
	east_controller_mapler(map, x);
	f_controller_mapler(map, x);
	c_controller_mapler(map, x);
}

void read_map(t_map *map)
{
	char *str;
	char *line;

	map->map_file_fd = open(map->map_file_path, O_RDONLY);
	if (map->map_file_fd == -1)
	{
		flag_free(map);
		error_exit_printing("Failed to open map file");
	}
	map->one_line_map = NULL;
	while (1)
	{
		line = get_next_line(map->map_file_fd);
		if (!line)
			break;
		str = map->one_line_map;
		map->one_line_map = ft_strjoin(str, line);
		free(str);
		free(line);
	}
	if (!map->one_line_map)
		ft_err_mapcontrol("Map read error", map, 1);
	close(map->map_file_fd);
}

void map_dimension(t_map *map)
{
	int j;
	int case_split;

	case_split = -1;
	map->map_file_height = 0;
	map->map_file = split_adv(map->one_line_map, '\n', &case_split);
	if (!map->map_file)
		ft_err_mapcontrol("Map line split error", map, 1);
	j = 0;
	while (map->one_line_map[j])
	{
		if (map->one_line_map[j] == '\n')
			map->map_file_height++;
		j++;
	}
}

int controller_map_sixth(t_map *map)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (map->map_file_height > a && map->map_file[a])
	{
		controller_mapler_all(map, a);
		if (map->flags->flag_count == 6 && map->flags->if_flag == 0)
		{
			map->flags->if_flag = 1;
			b = a;
			break;
		}
		a++;
	}
	if (map->flags->flag_count != 6)
		ft_err_mapcontrol("map have not 6 direction", map, 1);
	if (is_incorrect_name(map, b) == 0)
		ft_err_mapcontrol("direction partition error", map, 1);
	return (b);
}

void space_jump(t_map *map, int end)
{
	int count;

	end++;
	count = 0;
	if (map->map_file[end] != NULL)
	{
		while (map->map_file[end])
		{
			count = ft_space_jump(map->map_file[end], count);
			if (map->map_file[end][count] == '\0')
				end++;
			else
			{
				map->map_start = end;
				break;
			}
		}
		if (!map->map_file[end])
			map->map_start = end;
	}
	else
		ft_err_mapcontrol("map not have anything at lastline", map, 1);
}
