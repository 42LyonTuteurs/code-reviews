/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:16:08 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:29:30 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

t_vect		calc_vect(double angle)
{
	t_vect	new_vect;
	double	rad_angle;

	rad_angle = degrees_to_radian(angle);
	new_vect.x = -sin(rad_angle);
	new_vect.y = cos(rad_angle);
	return (new_vect);
}

void		calc_grosse_matrice(t_vect *vecteur, double angle)
{
	t_vect	oldvect;
	double	rad_angle;

	rad_angle = degrees_to_radian(angle);
	oldvect = *vecteur;
	vecteur->x = oldvect.x * cos(rad_angle) - oldvect.y * sin(rad_angle);
	vecteur->y = oldvect.x * sin(rad_angle) + oldvect.y * cos(rad_angle);
}

t_vect		*tab_vect_init(t_cub_data *cub)
{
	t_vect	*tab_vect;
	int		i;

	i = 0;
	if (!(tab_vect = malloc(cub->carte.resolution_w * sizeof(t_vect))))
		return (0);
	tab_vect[i] = calc_vect((-((double)FOV_DEG * 0.5)));
	i++;
	while (i < cub->carte.resolution_w)
	{
		tab_vect[i] = calc_vect((i - cub->carte.resolution_w * 0.5) *\
		(double)FOV_DEG / cub->carte.resolution_w);
		i++;
	}
	return (tab_vect);
}
