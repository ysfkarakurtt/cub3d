/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_free2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustyilm <mustyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:21:18 by egermen           #+#    #+#             */
/*   Updated: 2024/12/16 13:16:30 by mustyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../cub3d.h"
#include <stdio.h>

void	free_array2d(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str && str[i] == NULL)
		free(str);
	str = NULL;
}

void	flag_free(t_map *map)
{
	if (map->flags)
	{
		free(map->flags);
		map->flags = NULL;
	}
}

int	all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

void	err_print_exit(char *str)
{
	printf("%s%s%s\n%sError%s\n", YELLOW, str, RESET, RED, RESET);
	exit(1);
}

int	ft_skip_spaces(char *str, int i)
{
	if (!str)
		return (0);
	while (str[i] != '\n'
		&& ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
	{
		i++;
	}
	return (i);
}
