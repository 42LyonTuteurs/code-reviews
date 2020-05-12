/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:20:13 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 12:52:48 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				ray_sprite_list(t_cast *cast, t_cub_data *cub, int i,\
int id)
{
	t_ray_sprite	*new_ray;
	double			angle;
	double			diff;

	if (!(new_ray = malloc(sizeof(t_ray_sprite))))
		ft_error_g(cub, "Malloc", 3);
	new_ray->i = i;
	angle = new_angle(cast->orientation + 90);
	diff = cub->carte.sprite[id].mid_rad - angle;
	diff = degrees_to_radian(diff);
	new_ray->point = tan(fabs(diff)) * cub->carte.sprite[id].dist;
	new_ray->point = diff < 0 ? -(new_ray->point) : new_ray->point;
	new_ray->dist = mur_derriere(cub, id, i, cast);
	new_ray->next = cub->carte.sprite[id].ray ? cub->carte.sprite[id].ray :\
	NULL;
	cub->carte.sprite[id].ray = new_ray;
}

t_pos				def_ok(t_cub_data *cub, t_vect point, int id)
{
	t_pos			ok;

	ok.x = cub->carte.sprite[id].p_start.x > cub->carte.sprite[id].p_end.x ?\
	1 : 0;
	ok.y = cub->carte.sprite[id].p_start.y > cub->carte.sprite[id].p_end.y ?\
	1 : 0;
	ok.x = fabs(cub->carte.sprite[id].p_start.x -\
	cub->carte.sprite[id].p_end.x) < 0.000001 &&\
	fabs(cub->carte.sprite[id].p_start.x - point.x) < 0.00001 ? 3 : ok.x;
	ok.y = fabs(cub->carte.sprite[id].p_start.y -\
	cub->carte.sprite[id].p_end.y) < 0.000001 &&\
	fabs(cub->carte.sprite[id].p_start.y - point.y) < 0.00001 ? 3 : ok.y;
	return (ok);
}

t_pos				def_ray(t_cast *cast)
{
	t_pos			ray;

	ray.x = cast->orientation > 180 ? 0 : 1;
	ray.x = fabs(cast->orientation - 180) < 0.00001 ||\
	fabs(cast->orientation - 0) < 0.000001 || fabs(cast->orientation - 360)\
	< 0.000001 ? 3 : ray.x;
	ray.y = cast->orientation > 90 && cast->orientation < 270 ? 1 : 0;
	ray.y = fabs(cast->orientation - 90) < 0.000001 ||\
	fabs(cast->orientation - 270) < 0.000001 ? 3 : ray.y;
	return (ray);
}

int					sprite_struct_clean(t_cub_data *cub)
{
	int				i;

	i = 0;
	while (i < cub->carte.id_sprite)
	{
		cub->carte.sprite[i].exist = 0;
		cub->carte.sprite[i].istart = -1;
		cub->carte.sprite[i].iend = -1;
		calc_sprite_dist(cub, i);
		calc_sprite_segm(cub, i);
		calc_sprite_angle(cub, i);
		cub->carte.sprite[i].cutend = -1;
		cub->carte.sprite[i].cutstart = -1;
		cub->carte.sprite[i].ray = NULL;
		sprite_abc(cub, i);
		i++;
	}
	return (1);
}
