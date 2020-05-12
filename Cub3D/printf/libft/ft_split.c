/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:31:26 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:36:30 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countch(char const *s, char c)
{
	unsigned long	i;
	unsigned long	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int		countlet(char const *s, char c, int pos)
{
	unsigned long	i;
	int				count;
	unsigned long	j;

	i = 0;
	count = 0;
	j = 0;
	while (s[i] && count <= pos)
	{
		while (s[i] == c && s[i])
			i++;
		count++;
		while (s[i] != c && count <= pos && s[i])
			i++;
	}
	while (s[i + j] && s[i + j] != c)
		j++;
	return (j);
}

static char		**split_alloc(char const *s, char c)
{
	int				count;
	char			**strs;

	count = 0;
	if (!s)
		return (0);
	if (!(strs = malloc((1 + countch(s, c)) * sizeof(char *))))
		return (0);
	while (count <= countch(s, c))
	{
		if (!(strs[count] = malloc((1 + countlet(s, c, count)) * sizeof(char))))
		{
			free(strs);
			return (0);
		}
		count++;
	}
	return (strs);
}

char			**ft_split(char const *s, char c)
{
	int				count;
	int				i;
	int				j;
	char			**strs;

	j = 0;
	i = 0;
	count = 0;
	strs = split_alloc(s, c);
	if (countch(s, c) == 0 || strs == 0)
		return (ft_calloc(1, 1 * sizeof(char **)));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			strs[count][j++] = s[i++];
		if (s[i - 1] != c)
			strs[count][j] = '\0';
		count++;
		j = 0;
	}
	strs[countch(s, c)] = NULL;
	return (strs);
}
