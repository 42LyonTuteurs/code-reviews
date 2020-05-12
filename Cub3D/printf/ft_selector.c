/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:59:23 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:39:52 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_ft(t_bag *grossac)
{
	grossac->tabindex[0] = 's';
	grossac->tabindex[1] = 'c';
	grossac->tabindex[2] = 'p';
	grossac->tabindex[3] = 'i';
	grossac->tabindex[4] = 'd';
	grossac->tabindex[5] = 'x';
	grossac->tabindex[6] = 'X';
	grossac->tabindex[7] = 'u';
	grossac->tabindex[8] = '%';
	grossac->ft_selector[0] = select_s;
	grossac->ft_selector[1] = select_c;
	grossac->ft_selector[2] = select_p;
	grossac->ft_selector[3] = select_i;
	grossac->ft_selector[4] = select_i;
	grossac->ft_selector[5] = select_x;
	grossac->ft_selector[6] = select_bx;
	grossac->ft_selector[7] = select_u;
	grossac->ft_selector[8] = select_prcent;
}

int		ft_cutzero(t_bag *grossac, int i)
{
	int		nb;

	while (grossac->mask[i] != '.' && grossac->mask[i] == '0' &&
	grossac->mask[i])
		i++;
	if (chrchar(grossac->mask[i], ".*123456789") == 0)
		return (i - 1);
	else if (ft_isdigit(grossac->mask[i]) == 1 || grossac->mask[i] == '*')
		if (chrchar('.', &(grossac->mask[i])) > 0)
			return (ft_manzero(grossac, i));
	while (grossac->mask[i] == '.' && grossac->mask[i])
		i++;
	if (ft_isdigit(grossac->mask[i]) == 1)
		nb = ft_atoi(&(grossac->mask[i]));
	if (grossac->mask[i] == '\0')
		nb = 0;
	if (grossac->mask[i] == '*')
		return (i - 1);
	if (nb == 0)
		grossac->cut = 1;
	return (i - 1);
}

int		ft_manzero(t_bag *grossac, int i)
{
	int		tmp;

	if (ft_isdigit(grossac->mask[i]) == 1)
		tmp = ft_atou(&(grossac->mask[i]));
	else if (grossac->mask[i] == '*')
		tmp = va_arg(grossac->args, int);
	else
	{
		grossac->cut = 1;
		return (i);
	}
	if (tmp < 0)
		grossac->spa = -tmp;
	else
		grossac->spb = tmp;
	while ((ft_isdigit(grossac->mask[i]) == 1 || grossac->mask[i] == '*') &&
	grossac->mask[i])
		i++;
	if (grossac->mask[i] == '.')
		ft_zero_dot_cut(grossac, i);
	return (i);
}

void	ft_zero_dot_cut(t_bag *grossac, int i)
{
	int temp;

	temp = 0;
	while (grossac->mask[i] == '.')
		i++;
	if (chrchar(grossac->mask[i], "0123456789*") == 0)
		grossac->cut = 1;
	else if (grossac->mask[i] == '*')
		temp = va_arg(grossac->args, int);
	else if (ft_isdigit(grossac->mask[i]) == 1)
		temp = ft_atoi(&(grossac->mask[i]));
	if (temp == 0)
		grossac->cut = 1;
}

int		ft_cut_temp(t_bag *grossac, int temp)
{
	if (temp == 0)
		grossac->cut = 1;
	if (temp < 0)
		temp = 0;
	if (grossac->cut == 0)
		grossac->cut = -1;
	return (temp);
}
