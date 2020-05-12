/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:34:23 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/09 18:37:28 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				calc_wall_orientation(int xy, t_vect vect, t_cub_data *cub,\
int i)
{
	double		orientation;

	orientation = new_angle(cub->perso.angle + ((i - cub->carte.resolution_w *\
	0.5) * FOV_DEG / cub->carte.resolution_w));
	if (xy == 0)
	{
		cub->perso.side[i] = (cub->perso.pos.y - vect.y > 0 ? 0 : 1);
		if (orientation == 360 || orientation == 0)
			cub->perso.side[i] = 1;
		cub->perso.offset[i] = (int)vect.x % TILE_SIZE;
	}
	if (xy == 1)
	{
		cub->perso.side[i] = (cub->perso.pos.x - vect.x > 0 ? 2 : 3);
		if (orientation == 270)
			cub->perso.side[i] = 3;
		cub->perso.offset[i] = (int)vect.y % TILE_SIZE;
	}
	return (0);
}

double			correct_distance(int i, double dist, t_cub_data *cub)
{
	double		angle;

	angle = degrees_to_radian(((i - cub->carte.resolution_w * 0.5) * FOV_DEG /\
	cub->carte.resolution_w));
	return (dist * cos(angle));
}

int				clean_cub_perso(t_cub_data *cub)
{
	if (cub->perso.side != 0)
	{
		free(cub->perso.side);
		cub->perso.side = 0;
	}
	if (cub->perso.distance != 0)
	{
		free(cub->perso.distance);
		cub->perso.distance = 0;
	}
	if (cub->perso.offset != 0)
	{
		free(cub->perso.offset);
		cub->perso.offset = 0;
	}
	return (1);
}

int				malloc_cub_perso(t_cub_data *cub)
{
	if (!(cub->perso.side = malloc(cub->carte.resolution_w * sizeof(int))))
		return (ft_error_g(cub, "malloc", 3));
	if (!(cub->perso.distance = malloc(cub->carte.resolution_w *\
	sizeof(double))))
		return (ft_error_g(cub, "malloc", 3));
	if (!(cub->perso.offset = malloc(cub->carte.resolution_w * sizeof(int))))
		return (ft_error_g(cub, "malloc", 3));
	return (1);
}
