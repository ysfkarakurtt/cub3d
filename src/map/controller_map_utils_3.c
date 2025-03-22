/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_map_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:35:07 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:35:08 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int comma_counter(char *data)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (data[i])
	{
		if (data[i] == ',')
		{
			count++;
			if (data[i + 1] == ',')
				return (-1);
		}
		i++;
	}
	return (count);
}

int is_available_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

int space_jump_first(char *data)
{
	int i;

	i = 0;
	while (data[i] && data[i] != ' ')
		i++;
	while (data[i] && data[i] == ' ')
		i++;
	return (i);
}

void str_copy(char *path, const char *data)
{
	int a;

	a = 0;
	while (data[a] != '\0')
	{
		path[a] = data[a];
		a++;
	}
	path[a] = '\0';
}
