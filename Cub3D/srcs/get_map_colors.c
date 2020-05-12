/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:51:15 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/09 14:37:15 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			read_color(int *red, int *green, int *blue, char *str)
{
	int			i;

	i = 1;
	while (str[i] && (*red == -1 || *blue == -1 || *green == -1))
	{
		if (chrchar(str[i], " 0123456789,") == 0)
			*red = -2;
		if (ft_isdigit(str[i]) == 1 && ft_isdigit(str[i - 1]) == 0)
		{
			if (*red == -1)
				*red = ft_atoi(&str[i]);
			else if (*green == -1)
				*green = ft_atoi(&str[i]);
			else if (*blue == -1)
				*blue = ft_atoi(&str[i]);
		}
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
		*red = -2;
}

void			toomucccommas(char *str, t_map *carte)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
	{
		ft_printf("Error\nThe colors must be separated by only one comma\n");
		ft_error_parsing(carte, NULL, 0);
	}
}

int				ft_couleur_sol(char *str, t_map *carte)
{
	int			red;
	int			green;
	int			blue;

	if (carte->couleur_sol != -1)
		return (too_many_args(carte, "floor color"));
	red = -1;
	green = -1;
	blue = -1;
	toomucccommas(str, carte);
	read_color(&red, &green, &blue, str);
	if (red < 0 || green < 0 || blue < 0 || str[1] != ' ')
	{
		ft_printf("Error\nYou need to set the floor \
color\nexample - F 'red','green','blue'\n");
		return (0);
	}
	if (red > 255 || green > 255 || blue > 255)
	{
		ft_printf("Error\nYou can define only 256 tones in one color \
for the floor\nset R,G,B from 0 to 255\n");
		return (0);
	}
	carte->couleur_sol = (red * 65536) + (green * 256) + blue;
	return (1);
}

int				ft_couleur_plafond(char *str, t_map *carte)
{
	int			red;
	int			green;
	int			blue;

	if (carte->couleur_plafond != -1)
		return (too_many_args(carte, "ceiling color"));
	red = -1;
	green = -1;
	blue = -1;
	toomucccommas(str, carte);
	read_color(&red, &green, &blue, str);
	if (red < 0 || green < 0 || blue < 0 || str[1] != ' ')
	{
		ft_printf("Error\nYou need to set the ceiling color \n\
example - C 'red','green','blue'\n");
		return (0);
	}
	if (red > 255 || green > 255 || blue > 255)
	{
		ft_printf("Error\nYou can define only 256 tones in one color for \
the ceiling\nset R,G,B from 0 to 255\n");
		return (0);
	}
	carte->couleur_plafond = (red * 65536) + (green * 256) + blue;
	return (1);
}
