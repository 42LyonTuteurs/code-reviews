/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:17:21 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:30:29 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_join(char *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		lens1;
	size_t		lens2;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(str = malloc((lens1 + lens2 + 1) * sizeof(char))))
		return (NULL);
	while (j < lens1)
		str[j++] = s1[i++];
	i = 0;
	while (i < lens2)
		str[j++] = s2[i++];
	str[lens1 + lens2] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char		*strdup_n(const char *s1, int backn)
{
	unsigned long	i;
	char			*s2;

	if (!s1)
		return (NULL);
	i = -1;
	if (backn == 0)
	{
		if (!(s2 = malloc((ft_strlen(s1) + 1) * sizeof(char))))
			return (NULL);
		while (s1[++i] != '\0')
			s2[i] = s1[i];
	}
	else
	{
		if (!(s2 = malloc((chrsdl((char *)s1) + 1) * sizeof(char))))
			return (NULL);
		while (s1[++i] != '\n')
			s2[i] = s1[i];
	}
	s2[i] = '\0';
	return (s2);
}

void		realic(char ***str)
{
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (chrsdl(**str) >= 0)
		while ((**str)[i] != '\n')
			i++;
	i++;
	while ((**str)[i + j] != '\0')
		j++;
	if (!(tmp = malloc((j + 1) * sizeof(char))))
	{
		free(**str);
		**str = NULL;
		return ;
	}
	j = 0;
	while ((**str)[i] != '\0')
		tmp[j++] = (**str)[i++];
	tmp[j] = '\0';
	if (str != NULL)
		free(**str);
	(**str) = tmp;
}

int			chrsdl(char *temp)
{
	int			i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
