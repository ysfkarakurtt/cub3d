/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algo_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:36:20 by ykarakur          #+#    #+#             */
/*   Updated: 2025/01/31 14:06:52 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

void	rotate_2(t_game *g, double dir, double plane)
{
	if (g->p->left)
	{
		dir = g->p->dirx;
		g->p->dirx = g->p->dirx * cos(g->p->rot_speed)
			+ g->p->diry * sin(g->p->rot_speed);
		g->p->diry = -dir * sin(g->p->rot_speed)
			+ g->p->diry * cos(g->p->rot_speed);
		plane = g->planex;
		g->planex = g->planex * cos(g->p->rot_speed)
			+ g->planey * sin(g->p->rot_speed);
		g->planey = -plane * sin(g->p->rot_speed)
			+ g->planey * cos(g->p->rot_speed);
	}
}
