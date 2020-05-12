/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:33:45 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/09 18:36:30 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int		test_file_name(char *str)
{
	int i;
	int result;

	i = ft_strlen(str);
	result = 1;
	if (str[--i] != 'b')
		result = 0;
	if (str[--i] != 'u')
		result = 0;
	if (str[--i] != 'c')
		result = 0;
	if (str[--i] != '.')
		result = 0;
	return (result);
}

int		too_many_args(t_map *carte, char *var)
{
	ft_printf("Error\nThe %s is defined more than once\n", var);
	return (ft_error_parsing(carte, NULL, 0));
}

int		not_enough_args(t_map *carte, char *var)
{
	ft_printf("Error\nYou need to define the %s in the *.cub file\n", var);
	return (ft_error_parsing(carte, NULL, 0));
}

int		args_checker(t_map *carte)
{
	if (carte->resolution_h < 0)
		return (not_enough_args(carte, "resolution 'R'"));
	else if (carte->texture_est == NULL)
		return (not_enough_args(carte, "east texture 'EA'"));
	else if (carte->texture_sud == NULL)
		return (not_enough_args(carte, "south texture 'SO'"));
	else if (carte->texture_ouest == NULL)
		return (not_enough_args(carte, "west texture 'WE'"));
	else if (carte->texture_nord == NULL)
		return (not_enough_args(carte, "north texture 'NO'"));
	else if (carte->texture_sprite == NULL)
		return (not_enough_args(carte, "sprite texture 'S'"));
	else if (carte->couleur_plafond == -1)
		return (not_enough_args(carte, "ceiling color 'C'"));
	else if (carte->couleur_sol == -1)
		return (not_enough_args(carte, "floor color 'F'"));
	else
		return (1);
}

void	map_error(t_map *carte)
{
	primary_map_error_checker(carte);
	map_only_one_player(carte);
	fill_tab_map(carte);
	map_wall_error_checker(carte);
	ft_sprite_tab_create(carte);
}
