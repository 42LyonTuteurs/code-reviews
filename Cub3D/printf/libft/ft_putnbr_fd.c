/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:09:08 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:33:26 by lolopez          ###   ########lyon.fr   */
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

static void			ptnb(unsigned long div, long long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (div > 9)
	{
		ft_putchar_fd((n / div) + '0', fd);
		n = n % div;
		div = div / 10;
	}
	ft_putchar_fd(n % 10 + '0', fd);
}

void				ft_putnbr_fd(int n, int fd)
{
	long long		len;
	long long		div;
	long long		lln;

	lln = (long long)n;
	len = ft_lennbr(lln);
	div = 1;
	while (len > 1)
	{
		div = div * 10;
		len--;
	}
	if (fd >= 0)
	{
		ptnb(div, lln, fd);
	}
}
