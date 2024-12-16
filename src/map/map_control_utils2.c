/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustyilm <mustyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:22:01 by egermen           #+#    #+#             */
/*   Updated: 2024/12/09 14:59:25 by mustyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

char	*texture_path_handler(char *str)
{
	int		i;
	char	*ret_path;

	i = skip_first_spaces(str);
	ret_path = malloc((ft_strlen(&str[i]) * sizeof(char)) + 1);
	if (!ret_path)
		return (NULL);
	if (str[i] == '\0')
	{
		free(ret_path);
		return (NULL);
	}
	copy_string(ret_path, &str[i]);
	if (!is_valid_file(ret_path))
	{
		free(ret_path);
		return (NULL);
	}
	return (ret_path);
}

char	*color_path_handler(char *str)
{
	int		i;
	int		j;
	char	*ret_path;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	j = 0;
	ret_path = malloc((ft_strlen(&str[i]) * sizeof(char)) + 1);
	if (!ret_path)
		return (NULL);
	if (str[i] == '\0')
	{
		free(ret_path);
		return (NULL);
	}
	while (str[i] != '\0')
	{
		ret_path[j] = str[i++];
		j++;
	}
	ret_path[j] = '\0';
	return (ret_path);
}

void	is_digit_color(char *tmp, char **str, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] == ' ')
			j++;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				while (str[i][j] && str[i][j] == ' ')
					j++;
				if (str[i][j] == '\0')
					break ;
				free(tmp);
				free_array2d(str);
				ft_err_mapcontrol("colors must be positive numbers!\n", map, 1);
			}
			j++;
		}
		i++;
	}
}

static int	tmp_control_color(char **tmp)
{
	if (!tmp[1] || !tmp[2])
		return (0);
	return (!(ft_atoi(tmp[0]) > 255
			|| ft_atoi(tmp[1]) > 255
			|| ft_atoi(tmp[2]) > 255));
}

int	take_rgb_color(char *str, t_map *map)
{
	char	**tmp;
	int		colorvalue;

	tmp = NULL;
	if (!str)
		ft_err_mapcontrol("color musn't be empty\n", map, 1);
	if (count_comma(str) != 2)
		return (free(str),
			ft_err_mapcontrol("colors miss or much! \n", map, 1));
	tmp = ft_split(str, ',');
	if (!tmp)
	{
		free(str);
		ft_err_mapcontrol("Memory allocation failed in ft_split\n", map, 1);
	}
	is_digit_color(str, tmp, map);
	if (!tmp_control_color(tmp))
		return (free_array2d(tmp), free(str),
			ft_err_mapcontrol("colors not enough! \n", map, 1));
	colorvalue = (ft_atoi(tmp[0]) << 16) + (ft_atoi(tmp[1]) << 8)
		+ ft_atoi(tmp[2]);
	free_array2d(tmp);
	return (colorvalue);
}
