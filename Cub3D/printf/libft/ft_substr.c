/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:52:16 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:36:06 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	unsigned long	i;
	unsigned long	j;
	char			*s2;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
	{
		s2 = ft_calloc(1, 1 * sizeof(char));
		return (s2);
	}
	if (!(s2 = malloc((len + 1) * sizeof(char))))
		return (0);
	while (s[i] != '\0' && j < len)
		s2[j++] = s[i++];
	s2[j] = '\0';
	return (s2);
}
