/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:52:39 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 12:49:57 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

void	free_text(t_map *carte)
{
	if (carte->texture_nord)
		free(carte->texture_nord);
	carte->texture_nord = NULL;
	if (carte->texture_sud)
		free(carte->texture_sud);
	carte->texture_sud = NULL;
	if (carte->texture_ouest)
		free(carte->texture_ouest);
	carte->texture_ouest = NULL;
	if (carte->texture_est)
		free(carte->texture_est);
	carte->texture_est = NULL;
	if (carte->texture_sprite)
		free(carte->texture_sprite);
	carte->texture_sprite = NULL;
}

void	clear_map_struct(t_map *carte)
{
	int		j;

	j = 0;
	free_text(carte);
	if (carte->mapinit != NULL)
		free(carte->mapinit);
	carte->mapinit = NULL;
	if (carte->map != NULL)
	{
		while (j < carte->map_h)
		{
			if (carte->map[j])
				free(carte->map[j]);
			carte->map[j++] = NULL;
		}
		free(carte->map);
	}
	carte->map = NULL;
	if (carte->id_sprite > 0 && carte->sprite != NULL)
		free(carte->sprite);
	carte->sprite = NULL;
}

int		exit_bmp(t_cub_data *param)
{
	int		i;

	i = -1;
	clear_map_struct(&param->carte);
	clean_cub_perso(param);
	if (param->perso.tab_vect_init)
		free(param->perso.tab_vect_init);
	param->perso.tab_vect_init = NULL;
	mlx_destroy_image(param->mlx.mlx_ptr, param->mlx.img.img_ptr);
	while (++i < 5)
		mlx_destroy_image(param->mlx.mlx_ptr, param->carte.text[i].img_ptr);
	if (param->carte.text)
		free(param->carte.text);
	param->carte.text = NULL;
	free(param->mlx.mlx_ptr);
	param->mlx.mlx_ptr = NULL;
	free(param);
	param = NULL;
	exit(0);
}
