/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:59:02 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/17 16:47:56 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		load_xpm(t_mlx *mlx, char *file, t_imag *img)
{
	if (!(img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, file, 			\
								&img->width, &img->height)))
		return (0);
	if (!(img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, 	\
								&img->size_l, &img->endian)))
		return (0);
	return (1);
}

int		nobonus_check(t_cub_data *c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < c->carte.map_h)
	{
		i = 0;
		while (i < c->carte.map_w)
		{
			if (chrchar(c->carte.map[j][i], "012NWES") == 0)
			{
				ft_printf("Error\nmultisprites only available in bonus mode\n");
				return (ft_error_parsing(&c->carte, NULL, 0));
			}
			i++;
		}
		j++;
	}
	c->bon = NULL;
	return (1);
}

int		main(int ac, char **av)
{
	t_cub_data *cub;

	if ((ac == 3 && ft_strncmp(av[2], "--save", 6) != 0))
		return (ft_printf("Error\nYou need to specify a *.cub path\n"));
	else if (ac != 2 && ac != 3)
		return (ft_printf("Error\nYou need to specify a *.cub path\n"));
	if (test_file_name(av[1]) == 0)
	{
		ft_printf("Error\nWrong file name\n");
		return (0);
	}
	if (!(cub = malloc(sizeof(t_cub_data))))
		return (ft_printf("Malloc() failed."));
	cub->mlx.mlx_ptr = mlx_init();
	ft_open_cub(&cub->carte, av[1]);
	nobonus_check(cub);
	if (ac == 3 && ft_strncmp(av[2], "--save", 6) == 0)
		screenshot(cub);
	init_game(cub);
	event_loop(cub);
	return (0);
}
