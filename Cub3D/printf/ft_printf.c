/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:35:09 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:37:41 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *pouet, ...)
{
	t_bag	grossac;

	if (chrchar('%', (char *)pouet) == 0)
		return (ft_countputstr((char *)pouet));
	va_start(grossac.args, (char *)pouet);
	initgrossac(&grossac, (char *)pouet);
	readline(&grossac, pouet);
	va_end(grossac.args);
	free(grossac.str);
	grossac.str = NULL;
	return (grossac.count);
}

int		selector_index(char c, t_bag *grossac)
{
	int		i;

	i = 0;
	while (c != grossac->tabindex[i])
		i++;
	return (i);
}

void	readline(t_bag *grossac, const char *pouet)
{
	int		i;

	i = 0;
	while (pouet[i] != '\0')
	{
		if (pouet[i] == '%')
		{
			i = percentpars(grossac, pouet, i);
			if (grossac->buffer == NULL)
			{
				clean_grossac(grossac);
				return ;
			}
			clean_grossac(grossac);
		}
		else
		{
			write(1, &(pouet[i]), 1);
			grossac->count++;
			i++;
		}
	}
}

int		percentpars(t_bag *grossac, const char *pouet, int i)
{
	int		s_index;

	i++;
	if (chrchar(pouet[i], "scpidxXu%") == 0)
	{
		grossac->mask = maskfiller(grossac, i);
	}
	while (chrchar(pouet[i], "scpidxXu%") == 0 && pouet[i])
	{
		i++;
	}
	s_index = selector_index(pouet[i], grossac);
	grossac->count += grossac->ft_selector[s_index](grossac);
	i++;
	return (i);
}

char	*maskfiller(t_bag *grossac, int i)
{
	int		j;
	int		len;
	char	*mask;

	j = i;
	len = 1;
	while (chrchar(grossac->str[i], "scpidxXu%") == 0)
	{
		len++;
		i++;
	}
	if (!(mask = malloc(len * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len - 1)
		mask[i++] = grossac->str[j++];
	mask[i] = '\0';
	return (mask);
}
