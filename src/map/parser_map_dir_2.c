/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_dir_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:39:48 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:39:49 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int controller_space(t_map *map, int a)
{
	int b;

	b = 0;
	while ((map->map_file[a][b]) != '\0')
	{
		if (!(map->map_file[a][b] == ' ' || map->map_file[a][b] == '\n'))
		{
			printf(" Space Error Message ! ");
			return (0);
		}
		b++;
	}
	return (1);
}

int line_dir_checking(char *map)
{
	char c;
	int a;
	int space_counter;

	a = 0;
	space_counter = 0;
	space_counter = ft_space_jump(map, space_counter);
	while (map[a + space_counter])
	{
		c = map[a + space_counter];
		if ((ft_strncmp(map + space_counter, "SO ", 3) == 0) || (ft_strncmp(map + space_counter, "NO ", 3) == 0) || (ft_strncmp(map + space_counter, "EA ", 3) == 0) || (ft_strncmp(map + space_counter, "WE ", 3) == 0) || (ft_strncmp(map + space_counter, "F ", 2) == 0) || (ft_strncmp(map + space_counter, "C ", 2) == 0) || c == '\0')
			return (1);
		else if (c == '\n')
			a++;
		else
			return (0);
	}
	return (1);
}

int is_incorrect_name(t_map *map, int a)

{
	int b;

	b = 0;
	while (b < a)
	{
		if (line_dir_checking(map->map_file[b]) == 0)
			return (0);
		b++;
	}
	return (1);
}

int c_controller_mapler(t_map *map, int i)
{
	char *str;
	int space_counter;

	space_counter = 0;
	str = NULL;
	space_counter = ft_space_jump(map->map_file[i], space_counter);
	if ((ft_strncmp(&map->map_file[i][space_counter], "C ", 2) == 0) && (map->flags->c_flag != 1))
	{
		str = colour_path_handler(&map->map_file[i][space_counter]);
		map->c_color = get_colour_rgb(str, map);
		map->flags->c_flag = 1;
		map->flags->flag_count++;
		free(str);
		return (1);
	}
	else if ((ft_strncmp(&map->map_file[i][space_counter], "C", 1) == 0) && (map->flags->c_flag == 1))
	{
		free(str);
		ft_err_mapcontrol("C is more than one in map", map, 1);
	}
	return (0);
}

int f_controller_mapler(t_map *map, int i)
{
	char *str;
	int space_counter;

	space_counter = 0;
	str = NULL;
	space_counter = ft_space_jump(map->map_file[i], space_counter);
	if ((ft_strncmp(&map->map_file[i][space_counter], "F ", 2) == 0) && (map->flags->f_flag != 1))
	{
		str = colour_path_handler(&map->map_file[i][space_counter]);
		map->f_color = get_colour_rgb(str, map);
		map->flags->f_flag = 1;
		map->flags->flag_count++;
		free(str);
		return (1);
	}
	else if ((ft_strncmp(&map->map_file[i][space_counter], "F", 1) == 0) && (map->flags->f_flag == 1))
	{
		free(str);
		ft_err_mapcontrol("F is more than one in map", map, 1);
	}
	return (0);
}
