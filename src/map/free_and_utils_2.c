/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:37:43 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:37:45 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../cub3d.h"
#include <stdio.h>

void free_array2d(char **str)
{
	int i;

	if (!str)
		return;
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

void flag_free(t_map *map)
{
	if (map->flags)
	{
		free(map->flags);
		map->flags = NULL;
	}
}

int all_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

void error_exit_printing(char *str)
{
	printf("%sError\n%s%s%s%s\n", RED, RESET, BLUE, str, RESET);
	exit(1);
}

int ft_space_jump(char *str, int i)
{
	if (!str)
		return (0);
	while (str[i] != '\n' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
	{
		i++;
	}
	return (i);
}
