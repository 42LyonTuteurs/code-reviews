/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:50:01 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/12 15:46:40 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			primary_map_error_checker(t_map *carte)
{
	int		i;

	i = 0;
	while (carte->mapinit[i])
	{
		if (chrchar(carte->mapinit[i], "0123456789 NSEW`") == 0)
		{
			ft_printf("Error\nUnwelcome char in the map\n");
			return (ft_error_parsing(carte, NULL, 0));
		}
		else if (carte->mapinit[i] == '`' && carte->mapinit[i - 1] == '`')
		{
			ft_printf("Error\nUnwelcome char in the map\n");
			return (ft_error_parsing(carte, NULL, 0));
		}
		i++;
	}
	return (1);
}

int			map_wall_error_checker(t_map *carte)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < carte->map_h)
	{
		j = -1;
		while (++j < carte->map_w)
		{
			if (carte->map[i][j] != '1' && carte->map[i][j] != ' ')
			{
				if (!(fouillefouine(carte, i, j)))
				{
					ft_printf("Error\nThe map is not surrounded by walls\n");
					ft_error_parsing(carte, NULL, 0);
				}
			}
		}
	}
	walls_outside(carte);
	return (1);
}

int			fouillefouine(t_map *c, int y, int x)
{
	if (y == c->map_h - 1 || y == 0 || x == c->map_w - 1 || x == 0)
		return (0);
	if (c->map[y - 1][x] == ' ')
		return (0);
	if (c->map[y][x + 1] == ' ')
		return (0);
	if (c->map[y + 1][x] == ' ')
		return (0);
	if (c->map[y][x - 1] == ' ')
		return (0);
	return (1);
}

int			map_only_one_player(t_map *carte)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (carte->mapinit[i])
	{
		if (chrchar(carte->mapinit[i], "NESW") == 1)
			count++;
		i++;
	}
	if (count != 1)
	{
		ft_printf("Error\nYou need to set one and only one\
player on the map\n");
		return (ft_error_parsing(carte, NULL, 0));
	}
	else
		return (1);
}

int			walls_outside(t_map *carte)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < carte->map_h)
	{
		i = 0;
		while (carte->map[j][i] != '\0')
		{
			if (carte->map[j][i] == ' ')
				carte->map[j][i] = '1';
			i++;
		}
		j++;
	}
	return (1);
}
