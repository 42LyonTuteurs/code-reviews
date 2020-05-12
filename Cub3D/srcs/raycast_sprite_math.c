/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite_math.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:45:20 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 12:28:53 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_sprite_angle(t_cub_data *cub, int id)
{
	double dx;
	double dy;
	double rad;

	dx = cub->carte.sprite[id].middle.x - cub->perso.pos.x;
	dy = cub->carte.sprite[id].middle.y - cub->perso.pos.y;
	rad = atan(dy / dx);
	rad = (rad * 180) / M_PI;
	if (cub->perso.angle >= 90 || cub->perso.angle < 180)
		rad += 90;
	else if (cub->perso.angle >= 180 || cub->perso.angle < 270)
		rad += 180;
	else if (cub->perso.angle >= 270 || cub->perso.angle < 360)
		rad += 270;
	cub->carte.sprite[id].mid_rad = new_angle(rad + 90);
}

void	calc_sprite_dist(t_cub_data *cub, int id)
{
	double rad;

	rad = degrees_to_radian((double)FOV_DEG * 0.5);
	cub->carte.sprite[id].dist = sqrt((fabs(cub->carte.sprite[id].middle.x -\
	cub->perso.pos.x) * fabs(cub->carte.sprite[id].middle.x -\
	cub->perso.pos.x)) + (fabs(cub->carte.sprite[id].middle.y -\
	cub->perso.pos.y) * fabs(cub->carte.sprite[id].middle.y -\
	cub->perso.pos.y)));
	cub->carte.sprite[id].hauteur = ((double)TILE_SIZE * \
	(cub->carte.resolution_w * .5 / tan(rad))) / cub->carte.sprite[id].dist;
}

void	calc_sprite_segm(t_cub_data *cub, int id)
{
	cub->carte.sprite[id].p_start.x = cub->perso.start_s.x +\
	cub->carte.sprite[id].middle.x;
	cub->carte.sprite[id].p_start.y = cub->perso.start_s.y +\
	cub->carte.sprite[id].middle.y;
	cub->carte.sprite[id].p_end.x = cub->perso.stop_v.x +\
	cub->carte.sprite[id].middle.x;
	cub->carte.sprite[id].p_end.y = cub->perso.stop_v.y +\
	cub->carte.sprite[id].middle.y;
}

int		calc_sprite(t_cub_data *cub, int i, t_cast *cast)
{
	int j;

	j = 0;
	cast->horizontal = cast->h.primdist;
	cast->vertical = cast->v.primdist;
	while (j < cub->carte.id_sprite)
	{
		vect_xy(cast, cub, i, j);
		j++;
	}
	return (1);
}
