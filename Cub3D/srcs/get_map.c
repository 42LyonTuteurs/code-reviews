/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:56:35 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/12 15:44:25 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_map(char *str, t_map *carte)
{
	int		i;

	i = -1;
	while (str[++i])
		if (chrchar(str[i], " 012NSEW3456789") == 0)
		{
			ft_printf("Error\nwrong character in the map\n");
			return (ft_error_parsing(carte, NULL, 0));
		}
	if (!(carte->mapinit))
	{
		carte->mapinit = ft_strdup(str);
		carte->mapinit = ft_join(carte->mapinit, "`");
	}
	else
	{
		carte->mapinit = ft_join(carte->mapinit, str);
		carte->mapinit = ft_join(carte->mapinit, "`");
	}
	if (carte->mapinit == NULL)
		return (0);
	return (1);
}

void		fill_tab_map(t_map *carte)
{
	int		index_str;
	int		index_tab;
	int		index_str_tab;

	index_str = -1;
	index_tab = 0;
	index_str_tab = 0;
	carte->map_h = chrchar('`', carte->mapinit);
	map_width(carte);
	malloc_tab_map(carte);
	while (carte->mapinit[++index_str])
	{
		if (chrchar(carte->mapinit[index_str], " 1023456789NSEW") != 0)
			carte->map[index_tab][index_str_tab++] = carte->mapinit[index_str];
		else if (chrchar(carte->mapinit[index_str], "`") != 0)
		{
			while (index_str_tab < carte->map_w)
				carte->map[index_tab][index_str_tab++] = ' ';
			carte->map[index_tab][index_str_tab] = '\0';
			index_tab++;
			index_str_tab = 0;
		}
	}
	free(carte->mapinit);
	carte->mapinit = NULL;
}

int			malloc_tab_map(t_map *carte)
{
	int		index_tab;

	index_tab = 0;
	if (!(carte->map = malloc(carte->map_h * sizeof(char *))))
	{
		perror("Error\n");
		return (ft_error_parsing(carte, "malloc", 3));
	}
	while (index_tab < carte->map_h)
	{
		if (!(carte->map[index_tab] =\
malloc((carte->map_w + 1) * sizeof(char))))
		{
			perror("Error\n");
			return (ft_error_parsing(carte, "malloc", 3));
		}
		index_tab++;
	}
	return (1);
}

int			map_width(t_map *carte)
{
	int		i;
	int		count;
	int		best;

	best = 0;
	i = 0;
	while (carte->mapinit[i])
	{
		count = 0;
		while (carte->mapinit[i] != '`' && carte->mapinit[i])
		{
			if (chrchar(carte->mapinit[i], " 1023456789NESW") != 0)
				count++;
			i++;
		}
		best = count > best ? count : best;
		i++;
	}
	carte->map_w = best;
	return (1);
}
