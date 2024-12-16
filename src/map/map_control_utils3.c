/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustyilm <mustyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:22:07 by egermen           #+#    #+#             */
/*   Updated: 2024/12/08 20:45:48 by mustyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

int	count_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			count++;
			if (str[i + 1] == ',')
				return (-1);
		}
		i++;
	}
	return (count);
}

int	is_valid_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

int	skip_first_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

void	copy_string(char *ret_path, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ret_path[i] = str[i];
		i++;
	}
	ret_path[i] = '\0';
}
