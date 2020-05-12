/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_attack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:28:03 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:37:25 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_space_bf(t_bag *grossac, char *buff, int len, int minus)
{
	int		finallen;
	char	*buffdelespace;
	char	*buffer;
	int		i;

	i = 0;
	finallen = grossac->spb - len;
	if (finallen < 0)
		return (ft_strdup(buff));
	if (!(buffdelespace = malloc((finallen + 1) * sizeof(char))))
		return (NULL);
	if (minus == 1)
		buffdelespace[i++] = '-';
	while (i < finallen)
		buffdelespace[i++] = ' ';
	buffdelespace[i] = '\0';
	buffer = ft_strjoin(buffdelespace, buff);
	free(buffdelespace);
	buffdelespace = NULL;
	return (buffer);
}

char		*add_zero(t_bag *grossac, char *buff, int len, int minus)
{
	int		finallen;
	char	*buffdelespace;
	char	*buffer;
	int		i;

	i = 0;
	finallen = grossac->o - len;
	if (finallen <= 0 && minus == 0)
		return (ft_strdup(buff));
	if (finallen < 0 && minus == 1)
		return (ft_strjoin("-", buff));
	if (minus == 1)
		finallen = finallen + 1;
	if (!(buffdelespace = malloc((finallen + 1) * sizeof(char))))
		return (NULL);
	if (minus == 1)
		buffdelespace[i++] = '-';
	while (i < finallen)
		buffdelespace[i++] = '0';
	buffdelespace[i] = '\0';
	buffer = ft_strjoin(buffdelespace, buff);
	free(buffdelespace);
	buffdelespace = NULL;
	return (buffer);
}

char		*cut_string(t_bag *grossac, char *buff, int len)
{
	int		finallen;
	char	*buffdelespace;
	int		i;

	i = 0;
	finallen = len > grossac->cut ? grossac->cut : len;
	if (finallen == -1)
		return (ft_strdup(""));
	if (!(buffdelespace = malloc((finallen + 1) * sizeof(char))))
		return (NULL);
	while (i < finallen)
	{
		buffdelespace[i] = buff[i];
		i++;
	}
	buffdelespace[i] = '\0';
	return (buffdelespace);
}

char		*add_space_af(t_bag *grossac, char *buff, int len, int minus)
{
	int		finallen;
	char	*buffdelespace;
	char	*buffer;
	int		i;

	i = 0;
	finallen = grossac->spa - len;
	if (finallen < 0)
		return (ft_strdup(buff));
	if (!(buffdelespace = malloc((finallen + 1) * sizeof(char))))
		return (NULL);
	if (minus == 1)
		buffdelespace[i++] = '-';
	while (i < finallen)
		buffdelespace[i++] = ' ';
	buffdelespace[i] = '\0';
	buffer = ft_strjoin(buff, buffdelespace);
	free(buffdelespace);
	buffdelespace = NULL;
	return (buffer);
}

int			ft_insecateur(t_bag *grossac, int i)
{
	int		temp;

	temp = 0;
	if (grossac->mask[i + 1] == '\0')
		return (-1);
	if (grossac->mask[i + 1] == '-')
		return (0);
	while (grossac->mask[i] == '.' && grossac->mask[i])
		i++;
	if (grossac->mask[i] == '*')
	{
		temp = va_arg(grossac->args, int);
		if (temp < 0)
			return (0);
		else if (temp == 0)
			return (-1);
		else
			return (temp);
	}
	else if (ft_isdigit(grossac->mask[i]) == 1)
		temp = ft_atou(&(grossac->mask[i]));
	if (temp == 0)
		return (-1);
	return (temp);
}
