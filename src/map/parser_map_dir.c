/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:39:38 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:39:39 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <fcntl.h>

int path_trying(char *data)
{
	int fd;

	fd = open(data, 777);
	if (fd == -1)
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

int north_controller_mapler(t_map *map, int i)
{
	int space_counter;

	space_counter = 0;
	space_counter = ft_space_jump(map->map_file[i], space_counter);
	if ((ft_strncmp(&map->map_file[i][space_counter], "NO ", 3) == 0) && (map->flags->north_flag != 1))
	{
		map->north_structure_path = path_structure_handler(&map->map_file[i]
																		 [space_counter]);
		if (!map->north_structure_path)
			ft_err_mapcontrol("north_structure_path not must empty!", map, 1);
		map->flags->north_flag = 1;
		map->flags->flag_count++;
		return (1);
	}
	else if ((ft_strncmp(&map->map_file[i][space_counter], "NO", 2) == 0) && (map->flags->north_flag == 1))
		ft_err_mapcontrol("NO is more than one in map", map, 1);
	return (0);
}

int south_controller_mapler(t_map *map, int a)
{
	int space_counter;

	space_counter = 0;
	space_counter = ft_space_jump(map->map_file[a], space_counter);
	if ((ft_strncmp(&map->map_file[a][space_counter], "SO ", 3) == 0) && (map->flags->south_flag != 1))
	{
		map->south_structure_path = path_structure_handler(
			&map->map_file[a][space_counter]);
		if (!map->south_structure_path)
			ft_err_mapcontrol("south_structure_path musnt be empty", map, 1);
		map->flags->south_flag = 1;
		map->flags->flag_count++;
		return (1);
	}
	else if ((ft_strncmp(&map->map_file[a][space_counter], "SO", 2) == 0) && (map->flags->south_flag == 1))
		ft_err_mapcontrol("SO more than one in map", map, 1);
	return (0);
}

int west_controller_mapler(t_map *map, int i)
{
	int space_counter;

	space_counter = 0;
	space_counter = ft_space_jump(map->map_file[i], space_counter);
	if ((ft_strncmp(&map->map_file[i][space_counter], "WE ", 3) == 0) && (map->flags->west_flag != 1))
	{
		map->west_structure_path = path_structure_handler(&map->map_file[i]
																		[space_counter]);
		if (!map->west_structure_path)
			ft_err_mapcontrol("west_structure_path not should be empty!", map, 1);
		map->flags->west_flag = 1;
		map->flags->flag_count++;
		return (1);
	}
	else if ((ft_strncmp(&map->map_file[i]
									   [space_counter],
						 "WE", 2) == 0) &&
			 (map->flags->west_flag == 1))
		ft_err_mapcontrol("WE more than one in map", map, 1);
	return (0);
}

int east_controller_mapler(t_map *map, int i)
{
	int space_counter;

	space_counter = 0;
	space_counter = ft_space_jump(map->map_file[i], 0);
	if ((ft_strncmp(&map->map_file[i][space_counter], "EA ", 3) == 0) && (map->flags->east_flag != 1))
	{
		map->east_structure_path = path_structure_handler(&map
															   ->map_file[i][space_counter]);
		if (!map->east_structure_path)
			ft_err_mapcontrol("ea texture path not should be empty", map, 1);
		map->flags->east_flag = 1;
		map->flags->flag_count++;
		return (1);
	}
	else if ((ft_strncmp(&map->map_file[i]
									   [space_counter],
						 "EA", 2) == 0) &&
			 (map->flags->east_flag == 1))
		ft_err_mapcontrol("EA more than one in map", map, 1);
	return (0);
}