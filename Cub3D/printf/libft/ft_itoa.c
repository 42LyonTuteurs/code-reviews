/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:15:12 by exam              #+#    #+#             */
/*   Updated: 2020/03/10 14:32:14 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_lennbr(long long nbr)
{
	long long		i;

	i = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char			*nballoc(long long nbr)
{
	char			*nb;

	if (nbr < 0)
	{
		if (!(nb = malloc(sizeof(char) * ft_lennbr(nbr) + 2)))
			return (0);
	}
	else
	{
		if (!(nb = malloc(sizeof(char) * ft_lennbr(nbr) + 1)))
			return (0);
	}
	return (nb);
}

static char			*fillstr(unsigned long div, long long n)
{
	unsigned long	i;
	char			*nb;

	i = 0;
	nb = nballoc(n);
	if (nb == 0)
		return (0);
	if (n < 0)
	{
		nb[i++] = '-';
		n = -n;
	}
	while (div > 9)
	{
		nb[i++] = (n / div) + 48;
		n = n % div;
		div = div / 10;
	}
	nb[i++] = n % 10 + 48;
	nb[i] = '\0';
	return (nb);
}

char				*ft_itoa(int n)
{
	long long		len;
	long long		div;
	long long		lln;
	char			*nb;

	lln = (long long)n;
	len = ft_lennbr(lln);
	div = 1;
	while (len > 1)
	{
		div = div * 10;
		len--;
	}
	nb = fillstr(div, lln);
	return (nb);
}
