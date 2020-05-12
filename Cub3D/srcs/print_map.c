/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 11:59:18 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/09 14:55:35 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int			mini_map_print(t_cub_data *cub)
{
	t_pos	i;
	t_vect	pospix;
	t_vect	start;

	pospix.x = (cub->perso.pos.x * MINIMAP_PIX) / TILE_SIZE;
	pospix.y = (cub->perso.pos.y * MINIMAP_PIX) / TILE_SIZE;
	start.x = pospix.x - (cub->carte.minimap_res.x * 0.5);
	start.y = pospix.y - (cub->carte.minimap_res.y * 0.5);
	i.x = 0;
	print_map(cub, &i, &start, &pospix);
	print_pos(cub);
	mlx_put_image_to_window(cub->mlx.mlx_ptr, cub->mlx.win,\
	cub->minimap.img_ptr, 0, 0);
	return (1);
}

void		print_pos(t_cub_data *cub)
{
	t_pos	i;

	i.x = cub->carte.minimap_res.x * 0.5;
	i.y = cub->carte.minimap_res.y * 0.5 + 1;
	while (i.x < (cub->carte.minimap_res.x * 0.5) + 2)
	{
		cub->minimap.data[i.y * cub->carte.minimap_res.x + i.x] = 0x33FF3333;
		i.x++;
	}
	i.y--;
	i.x = cub->carte.minimap_res.x * 0.5 - 1;
	while (i.x < cub->carte.minimap_res.x * 0.5 + 3)
	{
		cub->minimap.data[i.y * cub->carte.minimap_res.x + i.x] = 0x33FF3333;
		i.x++;
	}
	print_pos_two(cub);
}

void		print_pos_two(t_cub_data *cub)
{
	t_pos	i;

	i.x = cub->carte.minimap_res.x * 0.5 - 1;
	i.y = cub->carte.minimap_res.y * 0.5 - 1;
	while (i.x < (cub->carte.minimap_res.x * 0.5) + 3)
	{
		cub->minimap.data[i.y * cub->carte.minimap_res.x + i.x] = 0x33FF3333;
		i.x++;
	}
	i.y--;
	i.x = cub->carte.minimap_res.x * 0.5;
	while (i.x < (cub->carte.minimap_res.x * 0.5) + 2)
	{
		cub->minimap.data[i.y * cub->carte.minimap_res.x + i.x] = 0x33FF3333;
		i.x++;
	}
}

void		print_map(t_cub_data *cub, t_pos *i, t_vect *start, t_vect *pospix)
{
	while (i->x < cub->carte.minimap_res.x)
	{
		start->y = pospix->y - (cub->carte.minimap_res.y * 0.5);
		i->y = 0;
		while (i->y < cub->carte.minimap_res.y)
		{
			color_of_the_pix(cub, i, start, 0);
			while (i->y < cub->carte.minimap_res.y && ((start->y < 0 ||\
			(start->y / MINIMAP_PIX) >= cub->carte.map_h) || (start->x < 0 ||\
			(start->x / MINIMAP_PIX) > cub->carte.map_w)))
			{
				color_of_the_pix(cub, i, start, 0);
				i->y++;
				start->y++;
			}
			if (i->y != cub->carte.minimap_res.y)
			{
				color_of_the_pix(cub, i, start, 1);
				start->y++;
				i->y++;
			}
		}
		start->x++;
		i->x++;
	}
}

void		color_of_the_pix(t_cub_data *cub, t_pos *i, t_vect *start, int num)
{
	if (num == 0)
	{
		cub->minimap.data[i->y * cub->carte.minimap_res.x + i->x] =\
		0xff000000;
	}
	else
	{
		cub->minimap.data[i->y * cub->carte.minimap_res.x + i->x] =\
		cub->carte.map[(int)(start->y / MINIMAP_PIX)][(int)(start->x /\
		MINIMAP_PIX)] == '1' ? 0x338e95a9 : 0x33a5a89f;
	}
}
