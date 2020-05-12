/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:28:00 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:36:01 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chchr(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (1);
	else
		return (0);
}

static int		charbeg(char const *s1, char const *set)
{
	unsigned long	i;

	i = 0;
	while (chchr(set, s1[i]) == 1 && s1[i])
		i++;
	return (i);
}

static int		charend(char const *s1, char const *set)
{
	unsigned long	i;

	i = ft_strlen(s1) - 1;
	while (chchr(set, s1[i]) == 1)
		i--;
	if (i == (ft_strlen(s1) - 1))
		return (0);
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	beg;
	unsigned long	end;
	char			*str;

	i = 0;
	if (!s1)
		return (0);
	beg = charbeg(s1, set);
	if (beg == ft_strlen(s1))
	{
		str = ft_calloc(1, 1 * sizeof(char));
		return (str);
	}
	end = charend(s1, set);
	if (end == 0)
		end = ft_strlen(s1) - 1;
	if (!(str = malloc((end - beg + 2) * sizeof(char))))
		return (0);
	while (beg <= end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}
