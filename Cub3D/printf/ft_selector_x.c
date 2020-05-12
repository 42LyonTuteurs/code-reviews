/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:24:28 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:39:48 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		select_x(t_bag *grossac)
{
	int nb;
	int i;

	i = 0;
	if (grossac->mask != NULL)
	{
		fill_mask_x(grossac, i);
	}
	nb = va_arg(grossac->args, int);
	fill_buff_x(grossac, nb);
	if (grossac->buffer == NULL)
		return (-1);
	return (ft_countputstr(grossac->buffer));
}

void	fill_mask_x(t_bag *grossac, int i)
{
	while (chrchar(grossac->mask[i], "-0123456789*.") == 0 &&
	grossac->mask[i] != '\0')
		i++;
	if (chrchar(grossac->mask[i], "0.") == 1)
	{
		i = ft_cutzero(grossac, i);
		grossac->o = ft_zeroo(grossac, i);
	}
	else if (chrchar(grossac->mask[i], "123456789") == 1 ||
	grossac->mask[i] == '*')
		grossac->spb = ft_spb(grossac, i);
	else if (grossac->mask[i] == '-')
		grossac->spa = ft_spa(grossac, i);
	i++;
	while (grossac->mask[i] != '.' && grossac->mask[i] != '\0')
		i++;
	if (grossac->mask[i] == '.' && grossac->o == 0 && grossac->cut == 0)
	{
		i = ft_cutzero(grossac, i);
		grossac->o = ft_zeroo(grossac, i);
	}
}

void	fill_buff_x(t_bag *grossac, int nb)
{
	char		*charnb;
	char		*charbuff;
	int			len;

	charnb = ft_utoa_base(nb, "0123456789abcdef");
	len = ft_strlen(charnb);
	if (grossac->cut == 1 && nb == 0)
	{
		len = 0;
		free(charnb);
		charnb = ft_strdup("");
	}
	charbuff = fill_charbuff_x(grossac, &charnb, len);
	len = ft_strlen(charbuff);
	if (grossac->spb > 0)
		grossac->buffer = add_space_bf(grossac, charbuff, len, 0);
	else if (grossac->spa > 0)
		grossac->buffer = add_space_af(grossac, charbuff, len, 0);
	else
		grossac->buffer = ft_strdup(charbuff);
	free(charbuff);
	charbuff = NULL;
	free(charnb);
	charnb = NULL;
}

char	*fill_charbuff_x(t_bag *grossac, char **charnb, int len)
{
	char	*charbuff;

	if (grossac->o > 0)
	{
		charbuff = add_zero(grossac, *charnb, len, 0);
		return (charbuff);
	}
	else
		return (ft_strdup(*charnb));
}
