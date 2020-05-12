/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:16:15 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:36:44 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t		ft_lennbr(unsigned int nbr, size_t base)
{
	int				i;

	i = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

static char			*fillstr(unsigned int div, unsigned int n,
char *base, size_t sbase)
{
	unsigned int	i;
	char			*nb;

	i = 0;
	if (!(nb = malloc(sizeof(char) * ft_lennbr(n, sbase) + 1)))
		return (0);
	if (nb == 0)
		return (0);
	nb[div] = '\0';
	while (div > i)
	{
		nb[--div] = base[n % sbase];
		n = n / sbase;
	}
	return (nb);
}

char				*ft_utoa_base(unsigned int nbr, char *base)
{
	size_t			sbase;
	unsigned int	div;
	char			*nb;

	sbase = ft_strlen(base);
	div = ft_lennbr(nbr, sbase);
	nb = fillstr(div, nbr, base, sbase);
	return (nb);
}

int					ft_atou(char *str)
{
	int				i;
	long			res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res);
}
