/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:24:46 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:37:29 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_spb(t_bag *grossac, int i)
{
	int		temp;

	if (grossac->mask[i] == '*')
	{
		temp = va_arg(grossac->args, int);
		if (temp < 0)
		{
			grossac->spa = temp * -1;
			return (0);
		}
		return (temp);
	}
	else
		temp = ft_atou(&(grossac->mask[i]));
	return (temp);
}

int		ft_spa(t_bag *grossac, int i)
{
	int		temp;

	while (grossac->mask[i] == '-')
		i++;
	if (grossac->mask[i] == '*')
	{
		temp = va_arg(grossac->args, int);
		if (temp < 0)
			temp = temp * -1;
		return (temp);
	}
	else
		temp = ft_atou(&(grossac->mask[i - 1]));
	return (temp);
}

int		ft_zeroo(t_bag *grossac, int i)
{
	int		temp;

	i++;
	if (chrchar('.', &(grossac->mask[i - 1])) > 0 && grossac->o == 0 &&
	grossac->cut == 0)
		return (ft_dot(grossac, i));
	if (grossac->mask[i] == '*')
	{
		temp = va_arg(grossac->args, int);
		if (temp < 0)
		{
			if (grossac->spa == 0)
				grossac->spa = -temp;
			return (0);
		}
		return (temp);
	}
	else if (chrchar('-', grossac->mask) > 0 && (grossac->spa == 0 &&
	grossac->spb == 0))
	{
		grossac->spa = ft_atou(&(grossac->mask[i]));
		return (0);
	}
	else
		return (ft_atou(&(grossac->mask[i])));
}

int		ft_zero_percent(t_bag *grossac, int i)
{
	int		temp;

	while (grossac->mask[i] == '0')
		i++;
	if (grossac->mask[i] == '*' && grossac->mask[i - 1] == '0')
	{
		temp = va_arg(grossac->args, int);
		if (grossac->mask[i + 1] == '.')
			return (0);
		if (temp < 0)
		{
			if (grossac->spa == 0)
				grossac->spa = -temp;
			return (0);
		}
		return (temp);
	}
	else if (chrchar('-', grossac->mask) > 0 && (grossac->spa == 0 &&
	grossac->spb == 0))
	{
		grossac->spa = ft_atou(&(grossac->mask[i]));
		return (0);
	}
	else
		return (ft_atou(&(grossac->mask[i])));
}

int		ft_dot(t_bag *grossac, int i)
{
	int		temp;

	if (grossac->cut == 1)
		return (0);
	grossac->dot = 1;
	while (chrchar(grossac->mask[i], "0123456789*-") == 0 && grossac->mask[i])
		i++;
	if (grossac->mask[i] == '*')
	{
		temp = va_arg(grossac->args, int);
		return (ft_cut_temp(grossac, temp));
	}
	else if (chrchar('-', &(grossac->mask[i])) > 0)
		return (0);
	else
		temp = ft_atou(&(grossac->mask[i]));
	return (ft_cut_temp(grossac, temp));
}
