/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:10:08 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 12:44:12 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			get_texture(t_cub_data *cub)
{
	if (!(cub->carte.text = malloc(5 * sizeof(t_imag))))
		return (ft_error_g(cub, "malloc()", 3));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_nord, &cub->carte.text[0])))
		return (ft_error_g(cub, "north", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_sud, &cub->carte.text[1])))
		return (ft_error_g(cub, "south", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_est, &cub->carte.text[2])))
		return (ft_error_g(cub, "east", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_ouest, &cub->carte.text[3])))
		return (ft_error_g(cub, "west", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_sprite, &cub->carte.text[4])))
		return (ft_error_g(cub, "sprite", 2));
	free_text(&cub->carte);
	return (1);
}

int			init_data(t_cub_data *cub)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		cub->key[i] = 0;
		i++;
	}
	cub->mlx.img.img_ptr = NULL;
	cub->minimap.img_ptr = NULL;
	cub->mlx.win = NULL;
	cub->perso.side = 0;
	cub->perso.offset = 0;
	cub->perso.distance = 0;
	return (1);
}

int			init_game(t_cub_data *cub)
{
	int j;

	j = 0;
	ft_printf("resolution %d X %d,\nchemin texture :\nNO %s\nSO %s\nEA %s\nWE\
%s\nS  %s\ncouleur plafond %d\ncouleur sol     %d\nhauteur map %d\nlargeur map \
%d\n", cub->carte.resolution_w, cub->carte.resolution_h,\
cub->carte.texture_nord, cub->carte.texture_sud, cub->carte.texture_est,\
cub->carte.texture_ouest, cub->carte.texture_sprite,\
cub->carte.couleur_plafond, cub->carte.couleur_sol, cub->carte.map_h,\
cub->carte.map_w);
	while (j < cub->carte.map_h)
	{
		ft_printf("%s\n", cub->carte.map[j]);
		j++;
	}
	init_data(cub);
	primary_pos_perso(cub);
	get_texture(cub);
	game_win(cub, &cub->mlx, 0);
	sprite_vect_math(cub);
	new_img(cub, 0);
	mini_map_win(cub);
	mini_map_print(cub);
	cub->bon = NULL;
	return (1);
}

int			primary_pos_perso(t_cub_data *cub)
{
	int		i;
	int		j;
	char	dir;

	i = -1;
	j = -1;
	while (++i < cub->carte.map_h)
	{
		j = -1;
		while (++j < cub->carte.map_w)
		{
			if (chrchar(cub->carte.map[i][j], "NSWE") == 1)
			{
				dir = cub->carte.map[i][j];
				cub->perso.pos.x = j * TILE_SIZE + 1;
				cub->perso.pos.y = i * TILE_SIZE + 1;
				init_angle(dir, &cub->perso);
				cub->perso.tab_vect_init = tab_vect_init(cub);
				return (1);
			}
		}
	}
	return (0);
}

int			init_angle(char direction, t_perso *perso)
{
	if (direction == 'E')
	{
		perso->angle = 270;
		perso->direction.x = perso->pos.x + TILE_SIZE;
		perso->direction.y = perso->pos.y;
	}
	else if (direction == 'S')
	{
		perso->angle = 0;
		perso->direction.x = perso->pos.x;
		perso->direction.y = perso->pos.y + TILE_SIZE;
	}
	else if (direction == 'W')
	{
		perso->angle = 90;
		perso->direction.x = perso->pos.x - TILE_SIZE;
		perso->direction.y = perso->pos.y;
	}
	else if (direction == 'N')
	{
		perso->angle = 180;
		perso->direction.x = perso->pos.x;
		perso->direction.y = perso->pos.y - TILE_SIZE;
	}
	return (1);
}
