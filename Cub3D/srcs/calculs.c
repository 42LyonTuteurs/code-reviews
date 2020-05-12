/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:36:51 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/09 18:36:17 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

double		degrees_to_radian(double angle_in_degrees)
{
	return (angle_in_degrees * (M_PI / 180));
}

void		incr_angl(double *angle, int sign, double increment)
{
	double	new;

	new = sign == 1 ? *angle + increment : *angle - increment;
	if (sign == 1 && new > 360)
		while (new > 360)
			new -= 360;
	else if (sign == 0 && new < 0)
		while (new < 0)
			new += 360;
	*angle = new;
}

double		calc_alpha(double angle)
{
	double	new;

	angle = new_angle(angle);
	new = 0;
	if (angle < 90.0)
		return (90 - angle);
	else if (angle < 180.0)
		new = (180.0 - angle);
	else if (angle < 270.0)
		return (270.0 - angle);
	else if (angle < 360.0)
		new = (360.0 - angle);
	new = 90.0 - new;
	return (new);
}

double		new_angle(double calcul)
{
	double	new;

	new = calcul;
	if (calcul > 360)
		new = calcul - 360;
	else if (calcul < 0)
		new = calcul + 360;
	return (new);
}
