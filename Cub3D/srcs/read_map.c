/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:37:59 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 12:38:02 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_open_cub(t_map *carte, char *map_path)
{
	int		cub;

	if ((cub = open(map_path, O_RDONLY)) == -1)
	{
		perror("Error\n");
		exit(0);
	}
	if (ft_read_cub(carte, cub) == -1)
	{
		perror("Error\n");
		ft_error_parsing(carte, NULL, 0);
	}
	close(cub);
	map_error(carte);
	return (1);
}

int			is_a_wall(char *str, t_map *carte)
{
	int		i;

	i = 0;
	if (carte->sdl == 2)
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '1')
		return (1);
	if (str[i] == '0' || str[i] == '2')
	{
		ft_printf("Error\nThe map is not well defined\n");
		ft_error_parsing(carte, NULL, 0);
	}
	return (0);
}

int			ft_read_cub(t_map *carte, int cub)
{
	char	*line;
	char	*str;
	int		j;

	j = 1;
	tab_init(carte);
	while (j == 1)
	{
		if ((j = get_next_line(cub, &line)) == -1)
			return (-1);
		str = is_a_wall(line, carte) == 0 ? ft_strtrim(line, " 	") :\
		strdup(line);
		if (str[0] == '\0' && carte->sdl == 1)
			carte->sdl = 2;
		if (line[0] != '\0')
			if (carte->ft_parse_cub[ft_search_pref(carte, str)]\
(str, carte) == 0)
				err_gnl(carte, &str);
		free(str);
		str = NULL;
		free(line);
		line = NULL;
	}
	return (1);
}

int			ft_search_pref(t_map *carte, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i] == 'S')
		return (str[i + 1] != 'O' ? 5 : 2);
	else if ((str[i] == '0' || str[i] == '1' || str[i] == '2') &&\
	carte->sdl != 2)
		return (carte->sdl == 0 ? mapfirst(carte) : 8);
	else
		while (str[i] != carte->tabindex[j] &&\
		carte->tabindex[j] != '\0' && carte->sdl == 0)
			j++;
	if (carte->tabindex[j] == '\0' || carte->sdl == 2)
	{
		free(str);
		str = NULL;
		ft_printf("Error\nUnwelcome line in the *.cub\n");
		return (ft_error_parsing(carte, NULL, 0));
	}
	return (j);
}

int			mapfirst(t_map *carte)
{
	args_checker(carte);
	carte->sdl = 1;
	return (8);
}
