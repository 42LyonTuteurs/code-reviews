/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:42:24 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 13:36:21 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_ray		calc_h(t_cub_data *cub, double alpha, double orientation)
{
	t_ray	h;

	h.primdist.y = orientation >= 90.0 && orientation < 270.0 ?\
	((int)cub->perso.pos.y / TILE_SIZE) * (TILE_SIZE) :\
	((int)cub->perso.pos.y / TILE_SIZE) * (TILE_SIZE) + TILE_SIZE;
	h.primdist.x = (orientation >= 90.0 && orientation < 180.0) || (orientation\
	> 270.0 && orientation < 360.0) ? cub->perso.pos.x - ((cub->perso.pos.y -\
	h.primdist.y) / tan(degrees_to_radian(alpha))) : cub->perso.pos.x +\
	((cub->perso.pos.y - h.primdist.y) / tan(degrees_to_radian(alpha)));
	h.primdist.x = h.primdist.x < 0 ? 0 : h.primdist.x;
	h.primdist.y = h.primdist.y < 0 ? 0 : h.primdist.y;
	h.primdist.y = h.primdist.y > TILE_SIZE * (cub->carte.map_h) - 0.01 ?\
	TILE_SIZE * (cub->carte.map_h) - 0.01 : h.primdist.y;
	h.primdist.x = h.primdist.x > TILE_SIZE * (cub->carte.map_w) - 0.01 ?\
	TILE_SIZE * (cub->carte.map_w) - 0.01 : h.primdist.x;
	h.a.x = TILE_SIZE / tan(degrees_to_radian(alpha));
	h.a.x = orientation < 180 ? -h.a.x : h.a.x;
	h.a.y = orientation > 90 && orientation < 270 ? -TILE_SIZE : TILE_SIZE;
	if (fabs(orientation - 180) < .0001 || fabs(orientation - 0) < .0001 ||\
	fabs(orientation - 360) < .0001)
	{
		h.primdist.x = cub->perso.pos.x;
		h.a.x = 0;
	}
	return (h);
}

t_ray		calc_v(t_cub_data *cub, double alpha, double orientation)
{
	t_ray	v;

	v.primdist.x = orientation < 180.0 ? (((int)cub->perso.pos.x / TILE_SIZE))\
	* TILE_SIZE : ((int)cub->perso.pos.x / TILE_SIZE) * (TILE_SIZE) + TILE_SIZE;
	v.primdist.y = (orientation > 90.0 && orientation < 180.0) || (orientation\
	> 270.0 && orientation < 360.0) ? cub->perso.pos.y - (cub->perso.pos.x -\
	v.primdist.x) * tan(degrees_to_radian(alpha)) : cub->perso.pos.y +\
	(cub->perso.pos.x - v.primdist.x) * tan(degrees_to_radian(alpha));
	v.primdist.x = v.primdist.x < 0 ? 0 : v.primdist.x;
	v.primdist.y = v.primdist.y < 0 ? 0 : v.primdist.y;
	v.primdist.y = v.primdist.y > TILE_SIZE * (cub->carte.map_h) - 0.01 ?\
	TILE_SIZE * (cub->carte.map_h) - 0.01 : v.primdist.y;
	v.primdist.x = v.primdist.x > TILE_SIZE * (cub->carte.map_w) - 0.01 ?\
	TILE_SIZE * (cub->carte.map_w) - 0.01 : v.primdist.x;
	v.a.y = TILE_SIZE * tan(degrees_to_radian(alpha));
	v.a.y = orientation < 270 && orientation > 90 ? -v.a.y : v.a.y;
	v.a.x = orientation < 180.0 ? -TILE_SIZE : TILE_SIZE;
	if (fabs(orientation - 90) < .0001 || fabs(orientation - 270) < .0001)
	{
		v.primdist.y = cub->perso.pos.y;
		v.a.y = 0;
	}
	return (v);
}

double		calc_wall_dist(t_cub_data *cub, int i, t_cast *cast)
{
	double	dy;
	double	dx;
	int		xy;

	dx = cub->perso.pos.x != cast->horizontal.x ? fabs(cub->perso.pos.x -\
	cast->horizontal.x) / cos(degrees_to_radian(cast->alpha)) :\
	fabs(cub->perso.pos.y - cast->horizontal.y);
	dy = cub->perso.pos.y != cast->vertical.y ? fabs(cub->perso.pos.y -\
	cast->vertical.y) / sin(degrees_to_radian(cast->alpha)) :\
	fabs(cub->perso.pos.x - cast->vertical.x);
	xy = calc_xy(cub, i, &dx, &dy);
	xy == 0 ? calc_wall_orientation(xy, cast->horizontal, cub, i) :\
	calc_wall_orientation(xy, cast->vertical, cub, i);
	return (correct_distance(i, dx > dy ? dy : dx, cub));
}

t_vect		pos_wall_x(t_cub_data *cub, t_cast *ray)
{
	int		hit;
	t_vect	delta;

	delta = ray->h.primdist;
	hit = 0;
	while (hit == 0)
	{
		if (cub->carte.map[ray->h.a.y < 0 ? ((int)delta.y / TILE_SIZE) - 1 :\
		((int)delta.y / TILE_SIZE)][(int)(delta.x / TILE_SIZE)] == '1')
			break ;
		delta.y = delta.y + ray->h.a.y < 0 ? 0 : delta.y + ray->h.a.y;
		delta.x = delta.x + ray->h.a.x < 0 ? 0 : delta.x + ray->h.a.x;
		delta.y = delta.y > TILE_SIZE * (cub->carte.map_h) - 0.01 ?\
		TILE_SIZE * (cub->carte.map_h) - 0.01 : delta.y;
		delta.x = delta.x > TILE_SIZE * (cub->carte.map_w) - 0.01 ?\
		TILE_SIZE * (cub->carte.map_w) - 0.01 : delta.x;
		if (cub->carte.map[ray->h.a.y < 0 ? ((int)delta.y / TILE_SIZE) - 1 :\
		((int)delta.y / TILE_SIZE)][(int)(delta.x / TILE_SIZE)] == '1')
			hit = 1;
	}
	ray->murx.y = ray->h.a.y < 0 ? ((int)delta.y / TILE_SIZE) - 1 :\
	((int)delta.y / TILE_SIZE);
	ray->murx.x = (int)(delta.x / TILE_SIZE);
	return (delta);
}

t_vect		pos_wall_y(t_cub_data *cub, t_cast *ray)
{
	int		hit;
	t_vect	delta;

	delta = ray->v.primdist;
	hit = 0;
	while (hit == 0)
	{
		if (cub->carte.map[((int)delta.y / TILE_SIZE)][ray->v.a.x < 0 ?\
		((int)delta.x / TILE_SIZE) - 1 :\
		((int)delta.x / TILE_SIZE)] == '1')
			break ;
		delta.y = delta.y + ray->v.a.y < 0 ? 0 : delta.y + ray->v.a.y;
		delta.x = delta.x + ray->v.a.x < 0 ? 0 : delta.x + ray->v.a.x;
		delta.y = delta.y > TILE_SIZE * (cub->carte.map_h) - 0.01 ?\
		TILE_SIZE * (cub->carte.map_h) - 0.01 : delta.y;
		delta.x = delta.x > TILE_SIZE * (cub->carte.map_w) - 0.01 ?\
		TILE_SIZE * (cub->carte.map_w) - 0.01 : delta.x;
		if (cub->carte.map[((int)delta.y / TILE_SIZE)][ray->v.a.x < 0 ?\
		((int)delta.x / TILE_SIZE) - 1 : ((int)delta.x / TILE_SIZE)] == '1')
			hit = 1;
	}
	ray->mury.x = ray->v.a.x < 0 ?\
	((int)delta.x / TILE_SIZE) - 1 : ((int)delta.x / TILE_SIZE);
	ray->mury.y = ((int)delta.y / TILE_SIZE);
	return (delta);
}
