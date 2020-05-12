/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:54:24 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:24 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			mini_map_win(t_cub_data *cub)
{
	int		win_height;
	int		win_width;

	win_height = cub->carte.resolution_w > 999 ? 200 : 100;
	win_width = cub->carte.resolution_w > 999 ? 200 : 100;
	if (!(cub->minimap.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, win_width,\
	win_height)))
		return (ft_error_g(cub, "mlx", 3));
	if (!(cub->minimap.data = (int *)mlx_get_data_addr(cub->minimap.img_ptr,\
	&cub->minimap.bpp, &cub->minimap.size_l,
		&cub->minimap.endian)))
		return (ft_error_g(cub, "mlx", 3));
	cub->carte.minimap_res.y = win_height;
	cub->carte.minimap_res.x = win_width;
	return (1);
}
