/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:12:19 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:33:08 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int		i;
	char				*strsrc;
	char				*strdst;

	if (!src && !dst)
		return (0);
	strsrc = (char *)src;
	strdst = (char *)dst;
	i = 0;
	if (src > dst)
		while (i < len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	else
		while (len > 0)
		{
			len--;
			strdst[len] = strsrc[len];
		}
	return (dst);
}
