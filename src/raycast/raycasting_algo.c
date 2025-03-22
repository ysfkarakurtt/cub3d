/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:43:49 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/30 21:43:50 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx/mlx.h"
#include "../cub3d.h"
#include <math.h>

static void raycast(t_game *g)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		raycast_calculating(g, x);
		step_calculating(g);
		shot_space_calculating(g);
		wall_height_calculating(g);
		column_rend(g, x, -1);
	}
	mlx_put_image_to_window(g->mlx, g->mlxwin, g->image->image, 0, 0);
}

void rotate(t_game *g, double dir, double plane)
{
	if (g->p->right)
	{
		dir = g->p->dirx;
		g->p->dirx = g->p->dirx * cos(g->p->rot_speed) - g->p->diry * sin(g->p->rot_speed);
		g->p->diry = dir * sin(g->p->rot_speed) + g->p->diry * cos(g->p->rot_speed);
		plane = g->planex;
		g->planex = g->planex * cos(g->p->rot_speed) - g->planey * sin(g->p->rot_speed);
		g->planey = plane * sin(g->p->rot_speed) + g->planey * cos(g->p->rot_speed);
	}
	rotate_2(g, dir, plane);
}

void action_2(t_game *game)
{
	if (game->p->a)
	{
		if (game->map->map[(int)(game->p->posy)][(int)(game->p->posx - game->planex * game->p->player_speed)] != '1')
			game->p->posx -= game->planex * game->p->player_speed;
		if (game->map->map[(int)(game->p->posy - game->planey * game->p->player_speed)][(int)(game->p->posx)] != '1')
			game->p->posy -= game->planey * game->p->player_speed;
	}
	if (game->p->d)
	{
		if (game->map->map[(int)(game->p->posy)][(int)(game->p->posx + game->planex * game->p->player_speed)] != '1')
			game->p->posx += game->planex * game->p->player_speed;
		if (game->map->map[(int)(game->p->posy + game->planey * game->p->player_speed)][(int)(game->p->posx)] != '1')
			game->p->posy += game->planey * game->p->player_speed;
	}
}

void action(t_game *game)
{
	if (game->p->w)
	{
		if (game->map->map[(int)(game->p->posy)][(int)(game->p->posx + game->p->dirx * game->p->player_speed)] != '1')
			game->p->posx += game->p->dirx * game->p->player_speed;
		if (game->map->map[(int)(game->p->posy + game->p->diry * game->p->player_speed)][(int)(game->p->posx)] != '1')
			game->p->posy += game->p->diry * game->p->player_speed;
	}
	if (game->p->s)
	{
		if (game->map->map[(int)(game->p->posy)][(int)(game->p->posx - game->p->dirx * game->p->player_speed)] != '1')
			game->p->posx -= game->p->dirx * game->p->player_speed;
		if (game->map->map[(int)(game->p->posy - game->p->diry * game->p->player_speed)][(int)(game->p->posx)] != '1')
			game->p->posy -= game->p->diry * game->p->player_speed;
	}
	action_2(game);
}

int gamefunc(t_game *game)
{
	action(game);
	rotate(game, 0, 0);
	raycast(game);
	return (0);
}
