/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:35:54 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/17 16:26:00 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int				ft_resolution(char *str, t_map *carte)
{
	if (carte->resolution_h != -1 || carte->resolution_w != -1)
		return (too_many_args(carte, "resolution"));
	fill_resolution(str, carte);
	if (carte->resolution_h == -1 || carte->resolution_w == -1)
	{
		ft_printf("Error\nYou need to set the resolution of the screen\n\
example - R 'width' * 'height'\n");
		return (0);
	}
	else
		return (1);
}

void			fill_resolution(char *str, t_map *carte)
{
	int			i;
	int			h;
	int			w;

	h = -1;
	w = -1;
	i = 0;
	while (str[++i] && (h == -1 || w == -1))
	{
		if (chrchar(str[i], " 0123456789") == 0)
			ft_error_parsing(carte, "resolution", 1);
		if (ft_isdigit(str[i]) == 1 && ft_isdigit(str[i - 1]) == 0)
		{
			if (w == -1)
				w = ft_atoi(&str[i]);
			else if (h == -1)
				h = ft_atoi(&str[i]);
		}
	}
	if (resolution_err(i, str) == 0)
		ft_error_parsing(carte, NULL, 0);
	res_eq(carte, w, h);
}

void			res_eq(t_map *carte, int w, int h)
{
	if (w == -1 || h == -1)
		ft_error_parsing(carte, "resolution", 1);
	carte->resolution_w = w > 3200 ? 3200 : w;
	carte->resolution_h = h > 1800 ? 1800 : h;
	carte->resolution_w = carte->resolution_w < 100 ? 100 :\
	carte->resolution_w;
	carte->resolution_h = carte->resolution_h < 100 ? 100 : carte->resolution_h;
}

int				resolution_err(int i, char *str)
{
	while (ft_isdigit(str[i]) == 1)
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
	{
		ft_printf("Error\nResolution is not well defined\n");
		return (0);
	}
	return (1);
}
