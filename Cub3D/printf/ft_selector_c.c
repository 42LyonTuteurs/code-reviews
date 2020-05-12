/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:13:13 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:37:48 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		select_c(t_bag *grossac)
{
	int		c;
	int		i;

	i = 0;
	if (grossac->mask != NULL)
	{
		i = sel_c(grossac, i);
		c = va_arg(grossac->args, int);
		if (c == '\0')
			return (ft_aff_backz(grossac));
		fill_buff_c(grossac, (char)c);
		if (grossac->buffer == NULL)
			return (-1);
		return (ft_countputstr(grossac->buffer));
	}
	else
	{
		grossac->buffer = ft_strdup("");
		c = va_arg(grossac->args, int);
		if (c == '\0')
			write(1, "\0", 1);
		else
			write(1, &c, 1);
		return (1);
	}
}

int		sel_c(t_bag *grossac, int i)
{
	while (chrchar(grossac->mask[i], "-0123456789*") == 0 &&
	grossac->mask[i] != '\0')
	{
		i++;
	}
	if (ft_isdigit(grossac->mask[i]) == 1 || grossac->mask[i] == '*')
		grossac->spb = ft_spb(grossac, i);
	if (grossac->mask[i] == '-')
		grossac->spa = ft_spa(grossac, i);
	return (i);
}

void	fill_buff_c(t_bag *grossac, char c)
{
	char	*charbuff;

	if (!(charbuff = malloc(2 * sizeof(char))))
		return ;
	charbuff[0] = c;
	charbuff[1] = '\0';
	if (grossac->spb > 0)
		grossac->buffer = add_space_bf(grossac, charbuff, 1, 0);
	else if (grossac->spa > 0)
		grossac->buffer = add_space_af(grossac, charbuff, 1, 0);
	else
		grossac->buffer = ft_strdup(charbuff);
	free(charbuff);
	charbuff = NULL;
}

int		ft_aff_backz(t_bag *grossac)
{
	int		ispace;
	int		i;

	i = 0;
	grossac->buffer = ft_strdup("");
	if (grossac->spa == 1 || grossac->spb == 1)
	{
		write(1, "\0", 1);
		return (1);
	}
	ispace = grossac->spb > 1 ? grossac->spb : grossac->spa;
	if (grossac->spb > 0)
	{
		while (i++ < ispace - 1)
			write(1, " ", 1);
		write(1, "\0", 1);
	}
	else
	{
		write(1, "\0", 1);
		while (i++ < ispace - 1)
			write(1, " ", 1);
	}
	return (ispace > 0 ? ispace : 1);
}
