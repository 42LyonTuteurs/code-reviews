/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:36:34 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:32:09 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t		ft_lennbr(long long nbr, int base)
{
	int				i;

	i = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
	}
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

static char			*nballoc(long long nbr, size_t sbase)
{
	char			*nb;

	if (nbr < 0)
	{
		if (!(nb = malloc(sizeof(char) * ft_lennbr(nbr, sbase) + 2)))
			return (0);
	}
	else
	{
		if (!(nb = malloc(sizeof(char) * ft_lennbr(nbr, sbase) + 1)))
			return (0);
	}
	return (nb);
}

static char			*fillstr(unsigned long div, long long n,
char *base, size_t sbase)
{
	unsigned long	i;
	char			*nb;

	i = 0;
	nb = nballoc(n, sbase);
	if (nb == 0)
		return (0);
	if (n < 0)
	{
		nb[i++] = '-';
		div++;
		n = n * -1;
	}
	nb[div] = '\0';
	while (div > i)
	{
		nb[--div] = base[n % sbase];
		n = n / sbase;
	}
	return (nb);
}

char				*ft_itoa_base(long long nbr, char *base)
{
	size_t			sbase;
	long long		div;
	long long		lln;
	char			*nb;

	sbase = ft_strlen(base);
	lln = (long long)nbr;
	div = ft_lennbr(lln, sbase);
	nb = fillstr(div, lln, base, sbase);
	return (nb);
}
