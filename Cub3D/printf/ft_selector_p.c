/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:15:10 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:37:56 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		select_p(t_bag *grossac)
{
	uintptr_t	uip;
	int			i;

	i = 0;
	if (grossac->mask != NULL)
	{
		while (chrchar(grossac->mask[i], "-0123456789*") == 0 &&
		grossac->mask[i] != '\0')
			i++;
		if (ft_isdigit(grossac->mask[i]) == 1 || grossac->mask[i] == '*')
			grossac->spb = ft_spb(grossac, i);
		if (grossac->mask[i] == '-')
			grossac->spa = ft_atou(&(grossac->mask[i]));
	}
	uip = va_arg(grossac->args, uintptr_t);
	fill_buff_p(grossac, uip);
	if (grossac->buffer == NULL)
		return (-1);
	return (ft_countputstr(grossac->buffer));
}

void	fill_buff_p(t_bag *grossac, uintptr_t uip)
{
	char		*charbuff;
	char		*tmp;
	int			len;

	if (grossac->mask != NULL && chrchar('.', grossac->mask) == 1 && uip == 0)
		charbuff = ft_strdup("0x");
	else
	{
		tmp = ft_itoa_ll_base(uip, "0123456789abcdef");
		charbuff = ft_strjoin("0x", tmp);
		free(tmp);
		tmp = NULL;
	}
	len = ft_strlen(charbuff);
	if (grossac->spb > 0)
		grossac->buffer = add_space_bf(grossac, charbuff, len, 0);
	else if (grossac->spa > 0)
		grossac->buffer = add_space_af(grossac, charbuff, len, 0);
	else
		grossac->buffer = ft_strdup(charbuff);
	free(charbuff);
	charbuff = NULL;
}
