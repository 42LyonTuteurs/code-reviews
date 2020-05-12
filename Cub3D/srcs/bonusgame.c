/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:24:23 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 12:44:12 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_rousta(t_cub_data *c)
{
	if (c->bon->frame % 3 != 0)
		return ;
	roustata(c, 3, 28);
	roustata(c, 9, 82);
	roustata(c, 17, 3);
	roustata(c, 20, 50);
	roustata(c, 42, 16);
	roustata(c, 37, 78);
}

void	roustata(t_cub_data *c, int y, int x)
{
	if (chrchar(c->carte.map[y][x], "37") != 0)
		return ;
	if (c->carte.map[y][x] == 'x' && c->bon->frame == 0)
		c->carte.map[y][x] = '4';
	else if (c->carte.map[y][x] != 'x')
		c->carte.map[y][x] = c->carte.map[y][x] + 1;
}

void	init_game_bonus(t_cub_data *cub)
{
	init_data(cub);
	primary_pos_perso(cub);
	get_texture_bonus(cub);
	get_bonus(cub);
	game_win(cub, &cub->mlx, 0);
	sprite_vect_math(cub);
	new_img(cub, 0);
	mini_map_win(cub);
	mini_map_print(cub);
	print_hub(cub);
}

int		get_bonus(t_cub_data *cub)
{
	if (!(cub->bon = malloc(sizeof(t_hub))))
		return (ft_error_g(cub, "Malloc", 3));
	get_hub_text(cub);
	cub->bon->i = 0;
	cub->bon->life = 0;
	cub->bon->frame = 0;
	return (1);
}

int		clean_bonus(t_cub_data *c)
{
	int		i;

	i = 4;
	while (++i < 10)
		mlx_destroy_image(c->mlx.mlx_ptr, c->carte.text[i].img_ptr);
	i = -1;
	while (++i < 14)
		mlx_destroy_image(c->mlx.mlx_ptr, c->bon->text[i].img_ptr);
	if (c->bon->text)
		free(c->bon->text);
	c->bon->text = NULL;
	if (c->bon)
		free(c->bon);
	return (1);
}
