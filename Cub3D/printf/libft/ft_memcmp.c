/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:18:20 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:32:59 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	unsigned const char		*strs1;
	unsigned const char		*strs2;

	if (n == 0)
		return (0);
	strs1 = s1;
	strs2 = s2;
	i = 0;
	while (i < n)
	{
		if (strs1[i] != strs2[i])
			return (strs1[i] - strs2[i]);
		i++;
	}
	return (0);
}
