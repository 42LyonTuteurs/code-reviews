/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:52:37 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:35:26 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned long	i;
	char			*s2;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(s2 = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	if (s1[i] == '\0')
		s2[i] = '\0';
	return (s2);
}
