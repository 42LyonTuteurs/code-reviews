/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:07:06 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:32:50 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
int c, size_t n)
{
	unsigned char		*strdst;
	const unsigned char	*strsrc;
	unsigned long		i;

	i = 0;
	strdst = (unsigned char *)dst;
	strsrc = src;
	while (i < n)
	{
		strdst[i] = strsrc[i];
		i++;
		if (strdst[i - 1] == (unsigned char)c)
			return (&strdst[i]);
	}
	return (0);
}
