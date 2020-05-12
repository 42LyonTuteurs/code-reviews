/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:14:11 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:17:19 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double			projection_plane(t_cub_data *cub)
{
	double		proj_plane_dist;
	double		angle;

	angle = degrees_to_radian((double)FOV_DEG * 0.5);
	proj_plane_dist = (cub->carte.resolution_w * 0.5) * (tan(angle));
	return (proj_plane_dist);
}

int				calc_xy(t_cub_data *cub, int i, double *distx, double *disty)
{
	double		orientation;
	int			xy;

	orientation = new_angle(cub->perso.angle + ((i - cub->carte.resolution_w *\
	0.5) * (double)FOV_DEG / cub->carte.resolution_w));
	if (orientation == 180 || orientation == 0 || orientation == 360)
		*disty = *distx + 1;
	else if (orientation == 90 || orientation == 270)
		*distx = *disty + 1;
	xy = *distx < *disty ? 0 : 1;
	return (xy);
}
