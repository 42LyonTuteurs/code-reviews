/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:41:16 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 11:41:37 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		print_sprite(t_cub_data *cub, int id)
{
	double			col;
	t_ray_sprite	*boom;
	int				t;

	t = sprite_t(cub, id);
	while (cub->carte.sprite[id].ray != NULL)
	{
		col = (((double)TILE_SIZE * 0.5) + cub->carte.sprite[id].ray->point) *\
		(double)cub->carte.text[t].width / (double)TILE_SIZE;
		if (fabs(cub->carte.sprite[id].ray->point) <= (double)TILE_SIZE * 0.5 &&
		cub->carte.sprite[id].ray->dist == 1)
			paint_sprite_col(cub, id, cub->carte.sprite[id].ray->i, col);
		boom = cub->carte.sprite[id].ray->next;
		free(cub->carte.sprite[id].ray);
		cub->carte.sprite[id].ray = NULL;
		cub->carte.sprite[id].ray = boom;
	}
}

int			sprite_t(t_cub_data *c, int id)
{
	t_pos			pos;
	int				num;

	pos.x = c->carte.sprite[id].pos % c->carte.map_w;
	pos.y = c->carte.sprite[id].pos / c->carte.map_w;
	if (c->carte.map[pos.y][pos.x] == 'x')
		return (5);
	num = c->carte.map[pos.y][pos.x] - '0' + 2;
	return (num);
}

void		paint_sprite_col(t_cub_data *cub, int id, int i, double offset)
{
	t_pos			j;
	t_vect			ratio;
	double			pixel;
	unsigned int	color;
	int				t;

	j = paint_sprite_col2(cub, id);
	t = sprite_t(cub, id);
	ratio.y = (double)cub->carte.text[t].height / cub->carte.sprite[id].hauteur;
	ratio.x = (double)cub->carte.text[t].width / (double)TILE_SIZE;
	pixel = cub->carte.sprite[id].hauteur > cub->carte.resolution_h ?\
	(cub->carte.sprite[id].hauteur - cub->carte.resolution_h) * 0.5 *\
	ratio.y : 0;
	while (cub->carte.sprite[id].hauteur > cub->carte.resolution_h ? j.x\
	< cub->carte.resolution_h : j.x < cub->carte.sprite[id].hauteur)
	{
		color = cub->carte.text[t].data[(int)pixel * cub->carte.text[t].width +\
		(int)(offset)];
		if (color != 0xff000000)
			cub->mlx.img.data[(j.y + j.x) * cub->carte.resolution_w + i] =\
			color;
		pixel += ratio.y;
		j.x++;
	}
}

t_pos		paint_sprite_col2(t_cub_data *cub, int id)
{
	t_pos			j;

	j.x = 0;
	j.y = cub->carte.sprite[id].hauteur > cub->carte.resolution_h ? 0 :\
	(cub->carte.resolution_h - cub->carte.sprite[id].hauteur) * 0.5;
	return (j);
}

void		print_sorted_sprite(t_cub_data *cub)
{
	int				i;
	int				j;

	j = 0;
	i = 0;
	while (1)
	{
		i = 0;
		while (i < cub->carte.id_sprite)
		{
			if (cub->carte.sprite[i].exist != 0 &&\
			cub->carte.sprite[i].order == j)
			{
				print_sprite(cub, i);
				break ;
			}
			i++;
		}
		if (i == cub->carte.id_sprite)
			return ;
		j++;
	}
}
