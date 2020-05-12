/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:02:54 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/13 13:17:35 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_error_g(t_cub_data *cub, char *str, int text)
{
	clear_map_struct(&cub->carte);
	clean_cub_perso(cub);
	if (cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win);
	if (text == 0)
		ft_printf("Exiting the program\n");
	else if (text == 1)
		ft_printf("Error\nThe %s is not well defined\nExiting the program\n");
	else if (text == 2)
		ft_printf("Error\nNot a valid %s texture\nExiting the program\n", str);
	else if (text == 3)
		ft_printf("Error\n%s failed ;(\nExiting the program\n", str);
	exit(0);
}

int		ft_error_parsing(t_map *carte, char *str, int text)
{
	clear_map_struct(carte);
	if (text == 0)
		ft_printf("Exiting the program\n");
	else if (text == 1)
		ft_printf("Error\nThe %s is not well defined\nExiting the program\n");
	else if (text == 3)
		ft_printf("Error\n%s failed ;(\nExiting the program\n", str);
	exit(0);
}

int		err_gnl(t_map *carte, char **line)
{
	free(*line);
	*line = NULL;
	return (ft_error_parsing(carte, NULL, 0));
}
