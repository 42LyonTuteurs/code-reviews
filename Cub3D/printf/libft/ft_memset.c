/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:53:14 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:33:13 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	l;
	char			*str;
	int				i;

	l = len;
	i = 0;
	str = (char *)b;
	while (l > 0)
	{
		str[i] = (unsigned char)c;
		i++;
		l--;
	}
	return (b);
}
