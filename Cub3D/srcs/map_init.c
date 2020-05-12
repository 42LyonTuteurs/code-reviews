/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:27:38 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 12:19:45 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_tab_init(t_map *carte)
{
	int i;

	i = 0;
	while (i < carte->id_sprite)
	{
		carte->sprite[i].exist = 0;
		carte->sprite[i].istart = -1;
		carte->sprite[i].iend = -1;
		carte->sprite[i].dist = 0;
		carte->sprite[i].hauteur = 0;
		carte->sprite[i].cutend = -1;
		carte->sprite[i].cutstart = -1;
		carte->sprite[i].order = -1;
		carte->sprite[i].math.a = 0;
		carte->sprite[i].math.b = 0;
		carte->sprite[i].math.c = 0;
		i++;
	}
}

void	ft_sprite_pos_init(t_map *carte)
{
	int i;
	int j;
	int e;

	i = 0;
	j = 0;
	e = 0;
	while (j <= carte->map_h || e != carte->id_sprite)
	{
		i = 0;
		while (i < carte->map_w)
		{
			if (e == carte->id_sprite)
				return ;
			if (chrchar(carte->map[j][i], "23456789") != 0)
			{
				carte->sprite[e].pos = j * carte->map_w + i;
				carte->sprite[e].middle.x = i * TILE_SIZE + (TILE_SIZE * 0.5);
				carte->sprite[e].middle.y = j * TILE_SIZE + (TILE_SIZE * 0.5);
				e++;
			}
			i++;
		}
		j++;
	}
}

void	tab_init(t_map *carte)
{
	ft_map_struct_init(carte);
	carte->tabindex[0] = 'R';
	carte->tabindex[1] = 'N';
	carte->tabindex[2] = 'S';
	carte->tabindex[3] = 'W';
	carte->tabindex[4] = 'E';
	carte->tabindex[5] = 'S';
	carte->tabindex[6] = 'F';
	carte->tabindex[7] = 'C';
	carte->tabindex[8] = '1';
	carte->ft_parse_cub[0] = ft_resolution;
	carte->ft_parse_cub[1] = ft_text_nord;
	carte->ft_parse_cub[2] = ft_text_sud;
	carte->ft_parse_cub[3] = ft_text_ouest;
	carte->ft_parse_cub[4] = ft_text_est;
	carte->ft_parse_cub[5] = ft_text_sprite;
	carte->ft_parse_cub[6] = ft_couleur_sol;
	carte->ft_parse_cub[7] = ft_couleur_plafond;
	carte->ft_parse_cub[8] = ft_map;
}

void	ft_map_struct_init(t_map *carte)
{
	carte->resolution_w = -1;
	carte->resolution_h = -1;
	carte->texture_nord = NULL;
	carte->texture_sud = NULL;
	carte->texture_ouest = NULL;
	carte->texture_est = NULL;
	carte->texture_sprite = NULL;
	carte->couleur_plafond = -1;
	carte->couleur_sol = -1;
	carte->mapinit = NULL;
	carte->map = NULL;
	carte->sprite = NULL;
	carte->map_w = 0;
	carte->map_h = 0;
	carte->sdl = 0;
}

int		ft_sprite_tab_create(t_map *carte)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < carte->map_h)
	{
		j = 0;
		while (j < carte->map_w)
		{
			if (chrchar(carte->map[i][j], "23456789") != 0)
				count++;
			j++;
		}
		i++;
	}
	carte->id_sprite = count;
	if (!(carte->sprite = malloc(count * sizeof(t_sprite))))
		return (ft_error_parsing(carte, "malloc()", 3));
	sprite_tab_init(carte);
	ft_sprite_pos_init(carte);
	return (1);
}
