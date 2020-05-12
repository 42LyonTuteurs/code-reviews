/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:19:17 by lolopez           #+#    #+#             */
/*   Updated: 2020/04/18 18:45:55 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int		get_texture_bonus(t_cub_data *cub)
{
	if (!(cub->carte.text = malloc(10 * sizeof(t_imag))))
		return (ft_error_g(cub, "malloc()", 3));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_nord, &cub->carte.text[0])))
		return (ft_error_g(cub, "north", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_sud, &cub->carte.text[1])))
		return (ft_error_g(cub, "south", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_est, &cub->carte.text[2])))
		return (ft_error_g(cub, "east", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_ouest, &cub->carte.text[3])))
		return (ft_error_g(cub, "west", 2));
	if (!(load_xpm(&cub->mlx, cub->carte.texture_sprite, &cub->carte.text[4])))
		return (ft_error_g(cub, "sprite", 2));
	if (!(load_xpm(&cub->mlx, "./xpm/troll.xpm", &cub->carte.text[5])))
		return (ft_error_g(cub, "sprite", 2));
	if (!(load_xpm(&cub->mlx, "./xpm/exp1.xpm", &cub->carte.text[6])))
		return (ft_error_g(cub, "sprite", 2));
	if (!(load_xpm(&cub->mlx, "./xpm/exp2.xpm", &cub->carte.text[7])))
		return (ft_error_g(cub, "sprite", 2));
	if (!(load_xpm(&cub->mlx, "./xpm/exp3.xpm", &cub->carte.text[8])))
		return (ft_error_g(cub, "sprite", 2));
	if (!(load_xpm(&cub->mlx, "./xpm/sterousta.xpm", &cub->carte.text[9])))
		return (ft_error_g(cub, "sprite", 2));
	free_text(&cub->carte);
	return (1);
}

int		get_hub_text(t_cub_data *cub)
{
	if (!(cub->bon->text = malloc(14 * sizeof(t_imag))))
		(ft_error_g(cub, "malloc()", 3));
	if (!(load_xpm(&cub->mlx, "./xpm/main0.xpm", &cub->bon->text[0]) &&
	load_xpm(&cub->mlx, "./xpm/main1.xpm", &cub->bon->text[1]) &&
	load_xpm(&cub->mlx, "./xpm/main2.xpm", &cub->bon->text[2]) &&
	load_xpm(&cub->mlx, "./xpm/sel1.xpm", &cub->bon->text[3]) &&
	load_xpm(&cub->mlx, "./xpm/sel2.xpm", &cub->bon->text[4]) &&
	load_xpm(&cub->mlx, "./xpm/sel3.xpm", &cub->bon->text[5]) &&
	load_xpm(&cub->mlx, "./xpm/lb0.xpm", &cub->bon->text[6]) &&
	load_xpm(&cub->mlx, "./xpm/lb1.xpm", &cub->bon->text[7]) &&
	load_xpm(&cub->mlx, "./xpm/lb2.xpm", &cub->bon->text[8]) &&
	load_xpm(&cub->mlx, "./xpm/lb3.xpm", &cub->bon->text[9]) &&
	load_xpm(&cub->mlx, "./xpm/lb4.xpm", &cub->bon->text[10]) &&
	load_xpm(&cub->mlx, "./xpm/lb5.xpm", &cub->bon->text[11]) &&
	load_xpm(&cub->mlx, "./xpm/lb6.xpm", &cub->bon->text[12])))
		return (ft_error_g(cub, "mlx", 3));
	cub->bon->text[13].img_ptr = mlx_new_image(cub->mlx.mlx_ptr,\
	cub->carte.resolution_w, cub->carte.resolution_h);
	cub->bon->text[13].data =\
	(int *)mlx_get_data_addr(cub->bon->text[13].img_ptr,\
	&cub->bon->text[13].bpp, &cub->bon->text[13].size_l,\
	&cub->bon->text[13].endian);
	return (1);
}

void	ft_draw_hub(t_cub_data *c, int t)
{
	t_pos			img;
	t_vect			text;
	t_vect			ratio;
	unsigned int	color;

	ratio.x = (double)c->bon->text[t].width / (double)c->carte.resolution_w;
	ratio.y = (double)c->bon->text[t].height / (double)c->carte.resolution_h;
	img.x = -1;
	text.x = 0;
	while (++img.x < c->carte.resolution_w - 1)
	{
		img.y = -1;
		text.y = 0;
		while (++img.y < c->carte.resolution_h)
		{
			color = c->bon->text[t].data[(int)text.y *\
			c->bon->text[t].width + (int)text.x];
			if (color != 0)
				c->mlx.img.data[img.y *\
			c->carte.resolution_w + img.x] = color;
			text.y += ratio.y;
		}
		text.x += ratio.x;
	}
}

int		print_hub(t_cub_data *c)
{
	int				t;
	int				t_l;

	t = c->bon->i == 0 ? 0 : hub_text(c);
	t_l = c->bon->life + 6;
	ft_draw_hub(c, t);
	mlx_put_image_to_window(c->mlx.mlx_ptr, c->mlx.win,\
		c->mlx.img.img_ptr, 0, 0);
	mlx_put_image_to_window(c->mlx.mlx_ptr, c->mlx.win,\
	c->bon->text[t_l].img_ptr, c->carte.resolution_w -\
	c->bon->text[t_l].width, 0);
	if (c->bon->life == 6)
	{
		mlx_string_put(c->mlx.mlx_ptr, c->mlx.win, 735, 50, 0xae0b0b, "BRAVO");
		mlx_string_put(c->mlx.mlx_ptr, c->mlx.win, 561, 80, 0xae0b0b,\
		"Vous avez repandu votre sel sur tous les trolls de l'humanite !");
		mlx_string_put(c->mlx.mlx_ptr, c->mlx.win, 639, 100, 0xae0b0b,\
		"Appuyez sur 'Ech' pour quitter le jeu");
	}
	return (1);
}

int		hub_text(t_cub_data *c)
{
	if (c->bon->frame % 3 != 0)
		return (c->bon->i);
	else
	{
		c->bon->i = c->bon->i < 5 ? c->bon->i + 1 : 0;
		return (c->bon->i);
	}
}
