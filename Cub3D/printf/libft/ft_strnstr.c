/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:47:00 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:35:52 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while ((haystack[i] != '\0' && i < (int)len))
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < (int)len)
			{
				j++;
				if (needle[j] == 0)
					return ((char *)&haystack[i]);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
