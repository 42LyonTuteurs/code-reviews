/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:54:06 by lolopez           #+#    #+#             */
/*   Updated: 2020/05/05 15:44:49 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		mouse_move(int x, int y, t_cub_data *cub)
{
	static int		milieu;
	int				i;

	if (!(milieu))
		milieu = cub->carte.resolution_w / 2;
	if (x < milieu)
		turn_mouse(cub, (x - milieu) * (0.5));
	if (x > milieu)
		turn_mouse(cub, (x - milieu) * (0.5));
	milieu = x;
	i = y;
	if (i != 0)
		i = 0;
	return (1);
} 


// fonction mouse_move originelle qui met le pointeur au milieu de l'écran

/*int		mouse_move(int x, int y, t_cub_data *cub)
{
	int		milieu;
	int		i;

	milieu = cub->carte.resolution_w / 2;
	if (x < milieu)
		turn_mouse(cub, (x - milieu) * (.1 * RAD_ANG));
	if (x > milieu)
		turn_mouse(cub, (x - milieu) * (.1 * RAD_ANG));
	i = y;
	mlx_mouse_move(cub->mlx.mlx_ptr, cub->mlx.win, \
	cub->carte.resolution_w / 2, cub->carte.resolution_h / 2);
	mlx_mouse_hide(cub->mlx.mlx_ptr, cub->mlx.win);
	return (1);
} */

int		key_press(int keycode, t_cub_data *param)
{
	if (keycode == UP)
		param->key[0] = 1;
	else if (keycode == BACK)
		param->key[1] = 1;
	else if (keycode == RIGHT)
		param->key[2] = 1;
	else if (keycode == LEFT)
		param->key[3] = 1;
	else if (keycode == TURNL)
		param->key[4] = 1;
	else if (keycode == TURNR)
		param->key[5] = 1;
	else if (param->bon != NULL && keycode == ACTION)
		attack(param);
	else if (keycode == EXIT)
		exit_propre(param);
//	printf("0x%x \n", keycode);
	return (1);
}

int		key_release(int keycode, t_cub_data *param)
{
	if (keycode == UP && param->key[0] == 1)
		param->key[0] = 0;
	else if (keycode == BACK && param->key[1] == 1)
		param->key[1] = 0;
	else if (keycode == RIGHT && param->key[2] == 1)
		param->key[2] = 0;
	else if (keycode == LEFT && param->key[3] == 1)
		param->key[3] = 0;
	else if (keycode == TURNL && param->key[4] == 1)
		param->key[4] = 0;
	else if (keycode == TURNR && param->key[5] == 1)
		param->key[5] = 0;
	return (1);
}

int		ft_keyhook(t_cub_data *param)
{
	if (param->key[0] == 1)
		go_forth(param);
	if (param->key[1] == 1)
		go_backward(param);
	if (param->key[2] == 1)
		go_right(param);
	if (param->key[3] == 1)
		go_left(param);
	if (param->key[4] == 1)
		turn_left(param);
	if (param->key[5] == 1)
		turn_right(param);
	sprite_vect_math(param);
	new_img(param, 0);
	mini_map_print(param);
	mlx_do_sync(param->mlx.mlx_ptr);
	return (1);
}
