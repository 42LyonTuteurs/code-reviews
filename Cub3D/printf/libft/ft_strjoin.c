/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:14:40 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:35:30 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	i;
	unsigned long	len;
	char			*str;

	if (!s1 && !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2));
	i = ft_strlen(s1);
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(&str[i], s2, ft_strlen(s2));
	str[len] = '\0';
	return (str);
}
