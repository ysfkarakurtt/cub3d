/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_directions_parser_buff2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egermen <egermen@student.42kocaeli.com.tr>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-07 11:21:44 by egermen           #+#    #+#             */
/*   Updated: 2024-12-07 11:21:44 by egermen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	map_c_control_buff(t_map *map, int i)
{
	if ((ft_strncmp(map->map_buff[i], "C ", 2) == 0)
		&& (map->flags->c_flag != 1))
	{
		map->buff_flags->c_flag = 1;
		map->buff_flags->flag_count++;
		return (1);
	}
	else
		return (0);
}
