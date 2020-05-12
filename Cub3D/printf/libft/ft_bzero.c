/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:59:40 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:31:29 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	char			*str;
	unsigned long	l;

	str = (char *)s;
	l = n;
	i = 0;
	while (l > 0)
	{
		str[i] = 0;
		i++;
		l--;
	}
}
