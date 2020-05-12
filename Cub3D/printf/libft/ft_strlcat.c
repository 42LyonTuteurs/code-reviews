/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:29:17 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:35:33 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long		i;
	unsigned long		j;

	i = 0;
	j = 0;
	while (dst[i] && size > 0)
	{
		i++;
		size--;
	}
	if (!src || src[j] == '\0')
		return (ft_strlen((char *)src) + i);
	while (src[j] && size > 1)
	{
		dst[i + j] = src[j];
		j++;
		size--;
	}
	if (size == 1 || src[j] == '\0')
		dst[i + j] = '\0';
	return (ft_strlen((char *)src) + i);
}
