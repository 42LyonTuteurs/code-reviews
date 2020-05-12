/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:32:10 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/17 18:45:19 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_text_nord(char *str, t_map *carte)
{
	int		i;

	if (carte->texture_nord != NULL)
		return (too_many_args(carte, "north texture"));
	i = 2;
	while (str[i] != '.' && ft_isalpha(str[i]) == 0 && str[i])
		i++;
	if (str[i] == '\0' || str[1] != 'O')
	{
		ft_printf("Error\nNo texture path defined for north faced walls.\n");
		ft_error_parsing(carte, NULL, 0);
	}
	carte->texture_nord = ft_strtrim(&str[i], " ");
	return (1);
}

int		ft_text_sud(char *str, t_map *carte)
{
	int		i;

	if (carte->texture_sud != NULL)
		return (too_many_args(carte, "south texture"));
	i = 2;
	while (str[i] != '.' && ft_isalpha(str[i]) == 0 && str[i])
		i++;
	if (str[i] == '\0' || str[1] != 'O')
	{
		ft_printf("Error\nNo texture path defined for south faced walls.\n");
		ft_error_parsing(carte, NULL, 0);
	}
	carte->texture_sud = ft_strtrim(&str[i], " ");
	return (1);
}

int		ft_text_est(char *str, t_map *carte)
{
	int		i;

	if (carte->texture_est != NULL)
		return (too_many_args(carte, "east texture"));
	i = 2;
	while (str[i] != '.' && ft_isalpha(str[i]) == 0 && str[i])
		i++;
	if (str[i] == '\0' || str[1] != 'A')
	{
		ft_printf("Error\nNo texture path defined for east faced walls.\n");
		ft_error_parsing(carte, NULL, 0);
	}
	carte->texture_est = ft_strtrim(&str[i], " ");
	return (1);
}

int		ft_text_ouest(char *str, t_map *carte)
{
	int		i;

	if (carte->texture_ouest != NULL)
		return (too_many_args(carte, "west texture"));
	i = 2;
	while (str[i] != '.' && ft_isalpha(str[i]) == 0 && str[i])
		i++;
	if (str[i] == '\0' || str[1] != 'E')
	{
		ft_printf("Error\nNo texture path defined for west faced walls.\n");
		ft_error_parsing(carte, NULL, 0);
	}
	carte->texture_ouest = ft_strtrim(&str[i], " ");
	return (1);
}

int		ft_text_sprite(char *str, t_map *carte)
{
	int		i;

	if (carte->texture_sprite != NULL)
		return (too_many_args(carte, "sprite texture"));
	i = 1;
	while (str[i] != '.' && ft_isalpha(str[i]) == 0 && str[i])
		i++;
	if (str[i] == '\0' || str[1] != ' ')
	{
		ft_printf("Error\nNo texture path defined for sprite.\n");
		ft_error_parsing(carte, NULL, 0);
	}
	carte->texture_sprite = ft_strtrim(&str[i], " ");
	return (1);
}
