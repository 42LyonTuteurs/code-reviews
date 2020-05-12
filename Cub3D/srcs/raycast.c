/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:32:49 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:19:31 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				cast_ray(t_cub_data *cub, int i)
{
	t_cast		ray;

	ray.alpha = calc_alpha(cub->perso.angle + ((i - cub->carte.resolution_w *\
	0.5) * (double)FOV_DEG / cub->carte.resolution_w));
	ray.orientation = new_angle(cub->perso.angle + ((i - cub->carte.resolution_w
	* 0.5) * (double)FOV_DEG / cub->carte.resolution_w));
	ray.h = calc_h(cub, ray.alpha, ray.orientation);
	ray.v = calc_v(cub, ray.alpha, ray.orientation);
	ray.horizontal = pos_wall_x(cub, &ray);
	ray.vertical = pos_wall_y(cub, &ray);
	cub->perso.distance[i] = calc_wall_dist(cub, i, &ray);
	ray.math = line_math(cub, ray);
	calc_sprite(cub, i, &ray);
	return (1);
}

t_2d_line		line_math(t_cub_data *cub, t_cast ray)
{
	t_2d_line	math;
	double		temp;
	t_vect		dir;

	dir = calc_vect(ray.orientation);
	temp = (dir.y) / (dir.x);
	math.a = fabs(temp) == INFINITY ? 1 : temp;
	math.c = fabs(temp) == INFINITY ? -(cub->perso.pos.x) :\
	cub->perso.pos.y - (cub->perso.pos.x * math.a);
	math.b = fabs(temp) == INFINITY ? 0 : -1;
	return (math);
}

void			sprite_vect_math(t_cub_data *cub)
{
	t_vect		plus;
	t_vect		minus;

	plus = calc_vect(cub->perso.angle - 90);
	minus = calc_vect(cub->perso.angle + 90);
	cub->perso.start_s.x = (((double)TILE_SIZE * 0.5) * minus.x);
	cub->perso.start_s.y = (((double)TILE_SIZE * 0.5) * minus.y);
	cub->perso.stop_v.x = (((double)TILE_SIZE * 0.5) * plus.x);
	cub->perso.stop_v.y = (((double)TILE_SIZE * 0.5) * plus.y);
}

void			sprite_abc(t_cub_data *cub, int id)
{
	t_vect		dir;
	double		temp;

	dir = calc_vect(cub->perso.angle + 90);
	temp = (dir.y) / (dir.x);
	cub->carte.sprite[id].math.a = temp;
	cub->carte.sprite[id].math.b = -1;
	cub->carte.sprite[id].math.c = cub->carte.sprite[id].middle.y -\
	(cub->carte.sprite[id].middle.x * cub->carte.sprite[id].math.a);
}

int				inter_2d_line_line(t_2d_line l1, t_2d_line l2, t_vect *result)
{
	double		tmp;

	if (!(tmp = l1.a * l2.b - l2.a * l1.b))
		return (0);
	tmp = 1 / tmp;
	result->x = (l1.b * l2.c - l2.b * l1.c) * tmp;
	result->y = (l1.c * l2.a - l2.c * l1.a) * tmp;
	return (1);
}
