/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_directions_parser_buff.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egermen <egermen@student.42kocaeli.com.tr>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-07 11:21:29 by egermen           #+#    #+#             */
/*   Updated: 2024-12-07 11:21:29 by egermen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	map_so_control_buff(t_map *map, int i)
{
	if ((ft_strncmp(map->map_buff[i], "SO ", 3) == 0)
		&& (map->buff_flags->so_flag != 1))
	{
		map->buff_flags->so_flag = 1;
		map->buff_flags->flag_count++;
		return (1);
	}
	else
		return (0);
}

int	map_no_control_buff(t_map *map, int i)
{
	if ((ft_strncmp(map->map_buff[i], "NO ", 3) == 0)
		&& (map->buff_flags->no_flag != 1))
	{
		map->buff_flags->no_flag = 1;
		map->buff_flags->flag_count++;
		return (1);
	}
	else
		return (0);
}

int	map_ea_control_buff(t_map *map, int i)
{
	if ((ft_strncmp(map->map_buff[i], "EA ", 3) == 0)
		&& (map->flags->ea_flag != 1))
	{
		map->buff_flags->ea_flag = 1;
		map->buff_flags->flag_count++;
		return (1);
	}
	else
		return (0);
}

int	map_we_control_buff(t_map *map, int i)
{
	if ((ft_strncmp(map->map_buff[i], "WE ", 3) == 0)
		&& (map->buff_flags->we_flag != 1))
	{
		map->buff_flags->we_flag = 1;
		map->buff_flags->flag_count++;
		return (1);
	}
	else
		return (0);
}

int	map_f_control_buff(t_map *map, int i)
{
	if ((ft_strncmp(map->map_buff[i], "F ", 2) == 0)
		&& (map->flags->f_flag != 1))
	{
		map->buff_flags->f_flag = 1;
		map->buff_flags->flag_count++;
		return (1);
	}
	else
		return (0);
}
