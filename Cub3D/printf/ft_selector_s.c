/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:11:46 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:39:40 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		select_s(t_bag *grossac)
{
	char	*buff;
	char	*nule;
	int		i;

	i = 0;
	if (grossac->mask != NULL)
	{
		i = sel_s(grossac, i);
		buff = va_arg(grossac->args, char*);
		if (buff == NULL)
		{
			nule = ft_strdup("(null)");
			fill_buff_s(grossac, nule);
			free(nule);
			nule = NULL;
		}
		else
			fill_buff_s(grossac, buff);
	}
	else
		ft_select_ss(grossac);
	if (grossac->buffer == NULL)
		return (-1);
	return (ft_countputstr(grossac->buffer));
}

void	ft_select_ss(t_bag *grossac)
{
	char	*buff;

	buff = va_arg(grossac->args, char*);
	if (buff == NULL)
		grossac->buffer = ft_strdup("(null)");
	else
		grossac->buffer = ft_strdup(buff);
}

void	fill_buff_s(t_bag *grossac, char *buff)
{
	char	*charbuff;
	int		len;

	len = ft_strlen(buff);
	if (grossac->cut != 0)
		charbuff = cut_string(grossac, buff, len);
	else
		charbuff = ft_strdup(buff);
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

int		sel_s(t_bag *grossac, int i)
{
	while (chrchar(grossac->mask[i], "-0123456789*.") == 0 &&
	grossac->mask[i] != '\0')
		i++;
	if (ft_isdigit(grossac->mask[i]) == 1 || grossac->mask[i] == '*')
		grossac->spb = ft_spb(grossac, i);
	if (grossac->mask[i] == '-')
		grossac->spa = ft_moins(grossac, i);
	if (grossac->mask[i] == '.')
		grossac->cut = ft_insecateur(grossac, i);
	i++;
	if (grossac->cut == 0)
	{
		while (grossac->mask[i] != '.' && grossac->mask[i] != '\0')
			i++;
		if (grossac->mask[i] == '.')
			grossac->cut = ft_insecateur(grossac, i);
	}
	return (i);
}

int		ft_moins(t_bag *grossac, int i)
{
	int		temp;

	while (grossac->mask[i] == '-' && grossac->mask[i])
		i++;
	if (ft_isdigit(grossac->mask[i]) == 1)
		return (ft_atoi(&(grossac->mask[i])));
	else if (grossac->mask[i] == '*')
	{
		temp = va_arg(grossac->args, int);
		if (temp < 0)
			temp = temp * -1;
		return (temp);
	}
	else
		return (0);
}
