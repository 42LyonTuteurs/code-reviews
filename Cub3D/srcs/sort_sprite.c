/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:21:34 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 11:42:16 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		sort_sprites(t_cub_data *cub)
{
	int				i;
	int				j;

	j = 0;
	while (j < cub->carte.id_sprite)
	{
		i = 0;
		cub->carte.sprite[j].order = 0;
		while (i < cub->carte.id_sprite)
		{
			while (i < cub->carte.id_sprite && (i == j ||\
			cub->carte.sprite[i].exist == 0))
				i++;
			if (i < cub->carte.id_sprite && cub->carte.sprite[j].dist <\
			cub->carte.sprite[i].dist && i < cub->carte.id_sprite)
				cub->carte.sprite[j].order++;
			i++;
		}
		j++;
	}
}

int			mur_derriere(t_cub_data *cub, int id, int i, t_cast *cast)
{
	t_pos			ray;
	t_pos			sprite;
	t_pos			mur;
	double			dist;

	mur = cub->perso.side[i] > 1 ? cast->mury : cast->murx;
	dist = cast->dist;
	if (dist < cub->perso.distance[i])
		return (1);
	sprite.x = cub->carte.sprite[id].pos % cub->carte.map_w;
	sprite.y = cub->carte.sprite[id].pos / cub->carte.map_w;
	ray = def_ray(cast);
	if ((ray.x == 1 && ray.y == 0 && mur.x >= sprite.x && mur.y <= sprite.y) ||\
	(ray.x == 0 && ray.y == 0 && mur.x <= sprite.x && mur.y <= sprite.y) ||\
	(ray.x == 0 && ray.y == 1 && mur.x <= sprite.x && mur.y >= sprite.y) ||\
	(ray.x == 1 && ray.y == 1 && mur.x >= sprite.x && mur.y >= sprite.y) ||\
	(ray.x == 3 && ray.y == 0 && mur.y <= sprite.y) || (ray.x == 3 && ray.y == 1
	&& mur.y >= sprite.y) || (ray.x == 1 && ray.y == 3 && mur.x >= sprite.x) ||\
	(ray.x == 0 && ray.y == 3 && mur.x <= sprite.x))
		return (0);
	else
		return (1);
}
