/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:05:09 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 13:38:49 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			load_xpm(t_mlx *mlx, char *file, t_imag *img)
{
	if (!(img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, file, 			\
								&img->width, &img->height)))
		return (0);
	if (!(img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, 	\
								&img->size_l, &img->endian)))
		return (0);
	return (1);
}

static int	ft_check_rousta(t_cub_data *c)
{
	if (c->carte.map[3][28] != '3' &&
	c->carte.map[9][82] != '3' &&
	c->carte.map[17][3] != '3' &&
	c->carte.map[20][50] != '3' &&
	c->carte.map[42][16] != '3' &&
	c->carte.map[37][78] != '3')
	{
		ft_printf("Error\nbonus map is corrupted\n");
		ft_error_g(c, NULL, 0);
	}
	return (1);
}

int			main(void)
{
	t_cub_data *cub;

	if (!(cub = malloc(sizeof(t_cub_data))))
		return (ft_printf("Malloc() failed."));
	cub->mlx.mlx_ptr = mlx_init();
	ft_open_cub(&cub->carte, "./bonus/game.cub");
	ft_check_rousta(cub);
	init_game_bonus(cub);
	event_loop(cub);
	return (0);
}
