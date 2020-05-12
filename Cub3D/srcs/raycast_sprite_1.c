/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:17:52 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 18:38:37 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		vect_xy(t_cast *cast, t_cub_data *cub, int i, int id)
{
	if (cub->carte.sprite[id].exist == 0)
	{
		if (!(cub->carte.sprite[id].exist = check_exist(cast, cub, i, id)))
			return ;
		cub->carte.sprite[id].istart = i;
		cub->carte.sprite[id].dist = sqrt((fabs(cub->carte.sprite[id].middle.x -
		cub->perso.pos.x) * fabs(cub->carte.sprite[id].middle.x -\
		cub->perso.pos.x)) + (fabs(cub->carte.sprite[id].middle.y -\
		cub->perso.pos.y) * fabs(cub->carte.sprite[id].middle.y -\
		cub->perso.pos.y)));
	}
	else if (cub->carte.sprite[id].exist == 1)
		if (check_exist(cast, cub, i, id) == 1)
			cub->carte.sprite[id].iend = i;
}

int			check_exist(t_cast *cast, t_cub_data *cub, int i, int id)
{
	t_vect	point;
	t_pos	ok;
	t_pos	ray;

	if (inter_2d_line_line(cub->carte.sprite[id].math, cast->math, &point) ==\
	0 || cub->carte.sprite[id].dist < TILE_SIZE * 0.2)
		return (0);
	ok = def_ok(cub, point, id);
	ray = def_ray(cast);
	if ((ray.x == 0 && point.x >= cub->perso.pos.x) || (ray.x == 1 &&\
	point.x <= cub->perso.pos.x) || ray.x == 3)
	{
		if (((ray.y == 0 && point.y >= cub->perso.pos.y) || (ray.y == 1 &&\
		point.y <= cub->perso.pos.y) || ray.y == 3) &&\
		check_ok_spri(cub, ok, point, id) == 1)
		{
			cast->dist = sqrt((fabs(point.x - cub->perso.pos.x) *\
			fabs(point.x - cub->perso.pos.x)) + (fabs(point.y -\
			cub->perso.pos.y) * fabs(point.y - cub->perso.pos.y)));
			ray_sprite_list(cast, cub, i, id);
			return (1);
		}
	}
	return (0);
}

int			check_ok_spri(t_cub_data *cub, t_pos ok, t_vect point, int id)
{
	if (((ok.x == 0 && point.x >= cub->carte.sprite[id].p_start.x &&\
point.x <= cub->carte.sprite[id].p_end.x) || (ok.x == 1 && point.x <=\
cub->carte.sprite[id].p_start.x && point.x >= cub->carte.sprite[id].p_end.x) ||\
(ok.x == 3)) && ((ok.y == 0 && point.y >= cub->carte.sprite[id].p_start.y &&\
point.y <= cub->carte.sprite[id].p_end.y) || (ok.y == 1 && point.y <=\
cub->carte.sprite[id].p_start.y && point.y >= cub->carte.sprite[id].p_end.y) ||\
(ok.y == 3)))
		return (1);
	else
		return (0);
}
