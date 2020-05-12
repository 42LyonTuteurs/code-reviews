/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:44:23 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 18:35:04 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

void	screenshot(t_cub_data *cub)
{
	primary_pos_perso(cub);
	get_texture(cub);
	game_win(cub, &cub->mlx, 1);
	sprite_vect_math(cub);
	cub->perso.side = 0;
	new_img(cub, 1);
	create_bmp(cub);
	exit_bmp(cub);
}

void	convert_bits(uint8_t *header, long int data)
{
	header[0] = (uint8_t)(data);
	header[1] = (uint8_t)(data >> 8);
	header[2] = (uint8_t)(data >> 16);
	header[3] = (uint8_t)(data >> 24);
}

void	bmp_h(t_cub_data *cub, int fd)
{
	uint8_t			header[54];
	int				i;
	unsigned long	len;

	len = (cub->carte.resolution_h * cub->carte.resolution_w * 3) + 54;
	i = -1;
	while (++i < 54)
		header[i] = 0;
	header[0] = (uint8_t)'B';
	header[1] = (uint8_t)'M';
	convert_bits(header + 2, len);
	header[10] = (uint8_t)54;
	header[14] = (uint8_t)40;
	convert_bits(header + 18, cub->carte.resolution_w);
	convert_bits(header + 22, cub->carte.resolution_h);
	header[26] = (uint8_t)1;
	header[28] = (uint8_t)32;
	write(fd, &header, 54);
}

void	bmp_colors(t_cub_data *cub, int fd)
{
	int				x;
	int				y;

	x = -1;
	y = cub->carte.resolution_h;
	while (--y >= 0)
	{
		x = -1;
		while (++x < cub->carte.resolution_w)
			write(fd, &cub->mlx.img.data[y * cub->carte.resolution_w + x], 4);
	}
}

int		create_bmp(t_cub_data *cub)
{
	int				fd;

	if (!(fd = open("./screenshot.bmp", O_WRONLY | O_CREAT |\
	O_TRUNC | O_APPEND, 0644)))
		return (0);
	bmp_h(cub, fd);
	bmp_colors(cub, fd);
	close(fd);
	return (1);
}
