/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algo_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:45:25 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:45:26 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool east_west(t_game *game)
{
	if (game->map->direction == 'W')
	{
		game->p->dirx = -1.0;
		game->p->diry = 0.0;
		game->planex = 0.0;
		game->planey = -0.66;
		return (true);
	}
	else if (game->map->direction == 'E')
	{
		game->p->dirx = 1.0;
		game->p->diry = 0.0;
		game->planex = 0.0;
		game->planey = 0.66;
		return (true);
	}
	return (false);
}

static bool south_north(t_game *game)
{
	if (game->map->direction == 'S')
	{
		game->p->dirx = 0;
		game->p->diry = 1;
		game->planex = -0.66;
		game->planey = 0;
		return (true);
	}
	else if (game->map->direction == 'N')
	{
		game->p->dirx = 0;
		game->p->diry = -1.00;
		game->planex = 0.66;
		game->planey = 0;
		return (true);
	}
	return (false);
}

bool player_checking(t_game *game)
{
	if (east_west(game))
		return (true);
	if (south_north(game))
		return (true);
	return (false);
}

void init_raycast(t_game *game)
{
	if (!player_checking(game))
		return ((void)(exiting("Error in check player \n", game, 1)));
	game->p->posx = game->map->pos_x + 0.5;
	game->p->posy = game->map->pos_y + 0.5;
	game->p->player_speed = 0.05;
	if (game->p->player_speed > 0.09)
		game->p->player_speed = 0.05;
	game->p->rot_speed = 0.04;
	game->p->w = false;
	game->p->a = false;
	game->p->s = false;
	game->p->d = false;
	game->p->left = false;
	game->p->right = false;
}

int key_press(int keyCode, t_game *game)
{
	if (keyCode == KEY_EXIT)
		exiting("exit successful\n", game, 0);
	if (keyCode == KEY_W)
		game->p->w = true;
	if (keyCode == KEY_S)
		game->p->s = true;
	if (keyCode == KEY_A)
		game->p->a = true;
	if (keyCode == KEY_D)
		game->p->d = true;
	if (keyCode == KEY_RIGHT)
		game->p->right = true;
	if (keyCode == KEY_LEFT)
		game->p->left = true;
	return (0);
}
