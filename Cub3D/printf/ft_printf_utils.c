/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:19:26 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:37:32 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chrchar(char c, char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int		ft_countputstr(char *str)
{
	size_t len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

void	initgrossac(t_bag *grossac, char *pouet)
{
	grossac->str = ft_strdup(pouet);
	grossac->buffer = NULL;
	grossac->mask = NULL;
	grossac->o = 0;
	grossac->spb = 0;
	grossac->spa = 0;
	grossac->cut = 0;
	grossac->dot = 0;
	grossac->count = 0;
	ft_fill_ft(grossac);
}

void	clean_grossac(t_bag *grossac)
{
	if (grossac->mask)
		free(grossac->mask);
	grossac->mask = NULL;
	if (grossac->buffer)
		free(grossac->buffer);
	grossac->buffer = NULL;
	grossac->o = 0;
	grossac->spb = 0;
	grossac->spa = 0;
	grossac->cut = 0;
	grossac->dot = 0;
}
