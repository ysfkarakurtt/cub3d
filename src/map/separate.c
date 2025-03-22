/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:41:22 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:41:23 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

static unsigned int word_count(const char *a, char controller)
{
	unsigned int word;

	word = 0;
	while (*a)
	{
		if (*a == controller)
		{
			if (*(a + 1) == controller)
				word++;
			a++;
		}
		else
		{
			while (*a != controller && *a)
				a++;
			word++;
		}
	}
	return (word);
}

static char *space_token_alloc(void)
{
	char *token;

	token = (char *)malloc(2 * sizeof(char));
	if (token)
	{
		token[0] = ' ';
		token[1] = '\0';
	}
	return (token);
}

static char *allocate_word_token(const char *str, char c)
{
	int i;
	char *token;
	int length;

	length = 0;
	i = 0;
	length = (int)char_length(str, c);
	token = (char *)malloc((length + 1) * sizeof(char));
	if (token)
	{
		while (*str && *str != c)
			token[i++] = *str++;
		token[i] = '\0';
	}
	return (token);
}

static int token_handler(char **array, const char **str, char c, int *a)
{
	if (**str == c && *(*str + 1) == c)
	{
		array[++(*a)] = space_token_alloc();
		if (!array[*a])
			return (0);
		(*str)++;
	}
	else if (**str != c)
	{
		array[++(*a)] = allocate_word_token(*str, c);
		if (!array[*a])
			return (0);
		while (**str && **str != c)
			(*str)++;
	}
	else
		(*str)++;
	return (1);
}

char **split_adv(char const *str, char c, int *a)
{
	char **array;

	array = (char **)malloc((word_count(str, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*str)
	{
		if (!token_handler(array, &str, c, a))
		{
			free_array2d(array);
			return (NULL);
		}
	}
	array[++*a] = NULL;
	return (array);
}
