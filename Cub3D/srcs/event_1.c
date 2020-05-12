/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:00:44 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 13:56:50 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int			go_forth(t_cub_data *param)
{
	t_vect	sight;

	sight = calc_vect(param->perso.angle);
	if (param->carte.map[(int)(param->perso.pos.y + STEP_SIZE * sight.y) /\
	TILE_SIZE][(int)(param->perso.pos.x + STEP_SIZE * sight.x) / TILE_SIZE]\
	!= '1')
	{
		param->perso.pos.y += STEP_SIZE * sight.y;
		param->perso.direction.y += STEP_SIZE * sight.y;
		param->perso.pos.x += STEP_SIZE * sight.x;
		param->perso.direction.x += STEP_SIZE * sight.x;
	}
	return (1);
}

int			go_backward(t_cub_data *param)
{
	t_vect	sight;

	sight = calc_vect(param->perso.angle);
	if (param->carte.map[(int)(param->perso.pos.y - STEP_SIZE * sight.y) /\
	TILE_SIZE][(int)(param->perso.pos.x - STEP_SIZE * sight.x) / TILE_SIZE]\
	!= '1')
	{
		param->perso.pos.y -= STEP_SIZE * sight.y;
		param->perso.direction.y -= STEP_SIZE * sight.y;
		param->perso.pos.x -= STEP_SIZE * sight.x;
		param->perso.direction.x -= STEP_SIZE * sight.x;
	}
	return (1);
}

int			go_left(t_cub_data *param)
{
	t_vect	sight;
	double	angl;

	angl = param->perso.angle + 90;
	sight = calc_vect(angl > 359 ? angl - 360 : angl);
	if (param->carte.map[(int)(param->perso.pos.y - STEP_SIZE * sight.y) /\
	TILE_SIZE][(int)(param->perso.pos.x - STEP_SIZE * sight.x) / TILE_SIZE]\
	!= '1')
	{
		param->perso.pos.y -= STEP_SIZE * sight.y;
		param->perso.direction.y -= STEP_SIZE * sight.y;
		param->perso.pos.x -= STEP_SIZE * sight.x;
		param->perso.direction.x -= STEP_SIZE * sight.x;
	}
	return (1);
}

int			go_right(t_cub_data *param)
{
	t_vect	sight;
	double	angr;

	angr = param->perso.angle + 90;
	sight = calc_vect(angr > 359 ? angr - 360 : angr);
	if (param->carte.map[(int)(param->perso.pos.y + STEP_SIZE * sight.y) /\
	TILE_SIZE][(int)(param->perso.pos.x + STEP_SIZE * sight.x) / TILE_SIZE]\
	!= '1')
	{
		param->perso.pos.y += STEP_SIZE * sight.y;
		param->perso.direction.y += STEP_SIZE * sight.y;
		param->perso.pos.x += STEP_SIZE * sight.x;
		param->perso.direction.x += STEP_SIZE * sight.x;
	}
	return (1);
}

int			attack(t_cub_data *c)
{
	if (c->bon->i != 0)
		return (1);
	c->bon->i = 1;
	if (c->carte.map[(int)(c->perso.direction.y / TILE_SIZE)]\
	[(int)(c->perso.direction.x / TILE_SIZE)] == '3')
	{
		c->carte.map[(int)(c->perso.direction.y / TILE_SIZE)]\
		[(int)(c->perso.direction.x / TILE_SIZE)] = 'x';
		c->bon->life = c->bon->life < 6 ? c->bon->life + 1 : 6;
	}
	return (1);
}
