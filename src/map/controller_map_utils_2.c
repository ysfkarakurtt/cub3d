/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_map_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:34:58 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:35:00 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

char *path_structure_handler(char *data)
{
	int a;
	char *ret_path;

	a = space_jump_first(data);
	ret_path = malloc((ft_strlen(&data[a]) * sizeof(char)) + 1);
	if (!ret_path)
		return (NULL);
	if (data[a] == '\0')
	{
		free(ret_path);
		return (NULL);
	}
	str_copy(ret_path, &data[a]);
	if (!is_available_file(ret_path))
	{
		free(ret_path);
		return (NULL);
	}
	return (ret_path);
}

static int colour_temp_controller(char **tmp)
{
	if (!tmp[1] || !tmp[2])
		return (0);
	return (!(ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[1]) > 255 || ft_atoi(tmp[2]) > 255));
}

void colour_is_digit(char *tmp, char **data, t_map *map)
{
	int a;
	int b;

	a = 0;
	while (data[a])
	{
		b = 0;
		while (data[a][b] && data[a][b] == ' ')
			b++;
		while (data[a][b])
		{
			if (!ft_isdigit(data[a][b]))
			{
				while (data[a][b] && data[a][b] == ' ')
					b++;
				if (data[a][b] == '\0')
					break;
				free(tmp);
				free_array2d(data);
				ft_err_mapcontrol("colors must be positive numbers!\n", map, 1);
			}
			b++;
		}
		a++;
	}
}

int get_colour_rgb(char *data, t_map *map)
{
	int colour;
	char **temp;

	temp = NULL;
	if (!data)
		ft_err_mapcontrol("colour musn't be empty\n", map, 1);
	if (comma_counter(data) != 2)
		return (free(data),
				ft_err_mapcontrol("colours miss or much! \n", map, 1));
	temp = ft_split(data, ',');
	if (!temp)
	{
		free(data);
		ft_err_mapcontrol("Memory allocation failed in ft_split\n", map, 1);
	}
	colour_is_digit(data, temp, map);
	if (!colour_temp_controller(temp))
		return (free_array2d(temp), free(data),
				ft_err_mapcontrol("colours not enough! \n", map, 1));
	colour = (ft_atoi(temp[0]) << 16) + (ft_atoi(temp[1]) << 8) + ft_atoi(temp[2]);
	free_array2d(temp);
	return (colour);
}

char *colour_path_handler(char *data)
{
	char *path;
	int a;
	int b;

	a = 0;
	while (data[a] && data[a] != ' ')
		a++;
	while (data[a] && data[a] == ' ')
		a++;
	b = 0;
	path = malloc((ft_strlen(&data[a]) * sizeof(char)) + 1);
	if (!path)
		return (NULL);
	if (data[a] == '\0')
	{
		free(path);
		return (NULL);
	}
	while (data[a] != '\0')
	{
		path[b] = data[a++];
		b++;
	}
	path[b] = '\0';
	return (path);
}