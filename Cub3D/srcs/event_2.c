/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:02:30 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 18:34:37 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int		turn_left(t_cub_data *param)
{
	t_vect	sight;

	incr_angl(&param->perso.angle, 0, RAD_ANG);
	sight = calc_vect(param->perso.angle);
	param->perso.direction.x = param->perso.pos.x + sight.x * TILE_SIZE;
	param->perso.direction.y = param->perso.pos.y + sight.y * TILE_SIZE;
	return (1);
}

int		turn_right(t_cub_data *param)
{
	t_vect	sight;

	incr_angl(&param->perso.angle, 1, RAD_ANG);
	sight = calc_vect(param->perso.angle);
	param->perso.direction.x = param->perso.pos.x + sight.x * TILE_SIZE;
	param->perso.direction.y = param->perso.pos.y + sight.y * TILE_SIZE;
	return (1);
}

int		turn_mouse(t_cub_data *param, double angle)
{
	t_vect	sight;

	incr_angl(&param->perso.angle, angle < 0 ? 0 : 1, fabs(angle));
	sight = calc_vect(param->perso.angle);
	param->perso.direction.x = param->perso.pos.x + sight.x * TILE_SIZE;
	param->perso.direction.y = param->perso.pos.y + sight.y * TILE_SIZE;
	return (1);
}

int		exit_propre(t_cub_data *param)
{
	int		i;

	i = -1;
	(void)param->mlx;
	clear_map_struct(&param->carte);
	clean_cub_perso(param);
	if (param->perso.tab_vect_init)
		free(param->perso.tab_vect_init);
	param->perso.tab_vect_init = NULL;
	mlx_destroy_image(param->mlx.mlx_ptr, param->mlx.img.img_ptr);
	mlx_destroy_image(param->mlx.mlx_ptr, param->minimap.img_ptr);
	while (++i < 5)
		mlx_destroy_image(param->mlx.mlx_ptr, param->carte.text[i].img_ptr);
	if (param->bon != NULL)
		clean_bonus(param);
	if (param->carte.text)
		free(param->carte.text);
	param->carte.text = NULL;
	mlx_clear_window(param->mlx.mlx_ptr, param->mlx.win);
	if (param->mlx.win)
		mlx_destroy_window(param->mlx.mlx_ptr, param->mlx.win);
	free(param);
	param = NULL;
	exit(0);
}

int		event_loop(t_cub_data *cub)
{
	mlx_hook(cub->mlx.win, 2, 1L, &key_press, cub);
	mlx_hook(cub->mlx.win, 3, 2L, &key_release, cub);
	mlx_hook(cub->mlx.win, 6, 1L << 6, &mouse_move, cub);
	mlx_hook(cub->mlx.win, 33, 1L << 17, &exit_propre, cub);
	mlx_do_sync(cub->mlx.mlx_ptr);
	mlx_loop_hook(cub->mlx.mlx_ptr, &ft_keyhook, cub);
	sprite_vect_math(cub);
	new_img(cub, 0);
	mini_map_print(cub);
	mlx_loop(cub->mlx.mlx_ptr);
	return (1);
}
