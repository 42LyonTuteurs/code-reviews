/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector_prcent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:01:44 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:39:37 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		select_prcent(t_bag *grossac)
{
	int		i;

	i = 0;
	if (grossac->mask != NULL)
	{
		i = sel_prcent(grossac, i);
		fill_buff_prcent(grossac);
		if (grossac->buffer == NULL)
			return (-1);
		return (ft_countputstr(grossac->buffer));
	}
	else
	{
		grossac->buffer = ft_strdup("");
		write(1, "%", 1);
		return (1);
	}
}

int		sel_prcent(t_bag *grossac, int i)
{
	while (chrchar(grossac->mask[i], "-0123456789*.") == 0 &&
	grossac->mask[i] != '\0')
	{
		i++;
	}
	if (grossac->mask[i] == '0' && chrchar('-', grossac->mask) == 0)
	{
		while (grossac->mask[i + 1] == '0')
			i++;
		grossac->o = ft_zero_percent(grossac, i);
	}
	if ((grossac->mask[i] == '0' && chrchar('-', grossac->mask) > 0) ||
	(grossac->mask[i] == '-' && chrchar('0', grossac->mask) > 0))
	{
		ft_prcent_deg(grossac, i);
		return (i);
	}
	if (chrchar(grossac->mask[i], "123456789") == 1 || grossac->mask[i] == '*')
		grossac->spb = ft_spb(grossac, i);
	else if (grossac->mask[i] == '-')
		grossac->spa = ft_spa(grossac, i);
	else if (grossac->mask[i] == '.')
		return (i);
	return (i);
}

void	fill_buff_prcent(t_bag *grossac)
{
	char	*charbuff;

	charbuff = ft_strdup("%");
	if (grossac->spb > 0)
		grossac->buffer = add_space_bf(grossac, charbuff, 1, 0);
	else if (grossac->spa > 0)
		grossac->buffer = add_space_af(grossac, charbuff, 1, 0);
	else if (grossac->o > 0)
		grossac->buffer = add_zero(grossac, charbuff, 1, 0);
	else
		grossac->buffer = ft_strdup(charbuff);
	free(charbuff);
	charbuff = NULL;
}

void	ft_prcent_deg(t_bag *grossac, int i)
{
	int temp;

	temp = 0;
	if (grossac->mask[i] == '0')
	{
		while (grossac->mask[i] == '0' || grossac->mask[i] == '-')
			i++;
		if (chrchar(grossac->mask[i], "123456789") > 0)
			temp = ft_atou(&(grossac->mask[i]));
		else if (grossac->mask[i] == '*')
			temp = va_arg(grossac->args, int);
	}
	else if (grossac->mask[i] == '-')
	{
		while (grossac->mask[i] == '0' || grossac->mask[i] == '-')
			i++;
		if (chrchar(grossac->mask[i], "123456789") > 0)
			temp = ft_atou(&(grossac->mask[i]));
		else if (grossac->mask[i] == '*')
			temp = va_arg(grossac->args, int);
	}
	if (temp < 0)
		temp = temp * -1;
	grossac->spa = temp;
}
