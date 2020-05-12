/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:12:46 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 18:37:59 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int				game_win(t_cub_data *cub, t_mlx *mlx, int bmp)
{
	t_pos	ss;

	mlx_get_screen_size(mlx->mlx_ptr, &ss.x, &ss.y);
	cub->carte.resolution_w = cub->carte.resolution_w > ss.x ? ss.x :\
	cub->carte.resolution_w;
	cub->carte.resolution_h = cub->carte.resolution_h > ss.y ? ss.y :\
	cub->carte.resolution_h;
	if (bmp != 1)
		mlx->win = mlx_new_window(mlx->mlx_ptr, cub->carte.resolution_w,\
	cub->carte.resolution_h, "GAME");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr,\
	cub->carte.resolution_w, cub->carte.resolution_h);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,\
	&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	return (1);
}

int				ceil_floor(t_cub_data *cub)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (cub->carte.resolution_h * 0.5))
	{
		j = -1;
		while (++j < cub->carte.resolution_w)
			cub->mlx.img.data[i * cub->carte.resolution_w + j] =\
			cub->carte.couleur_plafond;
	}
	while (++i < cub->carte.resolution_h)
	{
		j = -1;
		while (++j < cub->carte.resolution_w)
			cub->mlx.img.data[i * cub->carte.resolution_w + j] =\
			cub->carte.couleur_sol;
	}
	return (1);
}

int				new_img(t_cub_data *cub, int screen)
{
	sprite_struct_clean(cub);
	ceil_floor(cub);
	aff_wall(cub);
	sort_sprites(cub);
	print_sorted_sprite(cub);
	if (screen == 0 && cub->bon == NULL)
		mlx_put_image_to_window(cub->mlx.mlx_ptr, cub->mlx.win,\
		cub->mlx.img.img_ptr, 0, 0);
	else if (screen == 0 && cub->bon != NULL)
	{
		cub->bon->frame = cub->bon->frame < 21 ? cub->bon->frame + 1 : 0;
		check_rousta(cub);
		print_hub(cub);
	}
	return (1);
}

int				aff_wall(t_cub_data *cub)
{
	double		proj_plane_dist;
	int			i;
	double		wall;
	double		fov_rad_angle;

	i = 0;
	fov_rad_angle = degrees_to_radian((double)FOV_DEG * 0.5);
	proj_plane_dist = cub->carte.resolution_w * 0.5 / tan(fov_rad_angle);
	if (cub->perso.side == 0)
		malloc_cub_perso(cub);
	while (i < cub->carte.resolution_w)
	{
		cast_ray(cub, i);
		wall = ((double)TILE_SIZE * proj_plane_dist) / cub->perso.distance[i];
		if (cub->perso.side[i] == 0)
			paint_wall(cub, i, 1, wall);
		else if (cub->perso.side[i] == 1)
			paint_wall(cub, i, 0, wall);
		else if (cub->perso.side[i] == 2)
			paint_wall(cub, i, 2, wall);
		else if (cub->perso.side[i] == 3)
			paint_wall(cub, i, 3, wall);
		i++;
	}
	return (1);
}

int				paint_wall(t_cub_data *cub, int i, int t, double hauteur)
{
	int			j;
	int			start;
	t_vect		ratio;
	double		pixel;
	int			color;

	j = 0;
	ratio.y = (double)cub->carte.text[t].height / hauteur;
	ratio.x = (double)cub->carte.text[t].width / TILE_SIZE;
	start = hauteur > cub->carte.resolution_h ? 0 : (cub->carte.resolution_h -\
	hauteur) * 0.5;
	pixel = hauteur > cub->carte.resolution_h ? (hauteur -\
	cub->carte.resolution_h) * 0.5 * ratio.y : 0;
	while (hauteur > cub->carte.resolution_h ? j < cub->carte.resolution_h :\
	j < hauteur)
	{
		color = cub->carte.text[t].data[(int)pixel * cub->carte.text[t].width +\
		(int)(cub->perso.offset[i] * ratio.x)];
		cub->mlx.img.data[(start + j) * cub->carte.resolution_w + i] = color;
		pixel += ratio.y;
		j++;
	}
	return (1);
}
