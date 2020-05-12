/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:17:12 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:30:25 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*perecastor(char *buff, int fd, int **ret)
{
	char			temp[BUFFER_SIZE + 1];

	**ret = read(fd, temp, BUFFER_SIZE);
	temp[**ret] = '\0';
	if (!buff)
		buff = strdup_n(temp, 0);
	else
		buff = ft_join(buff, temp);
	if (**ret != BUFFER_SIZE || chrsdl(buff) >= 0)
		return (buff);
	else
		while (chrsdl(buff) < 0)
		{
			**ret = read(fd, temp, BUFFER_SIZE);
			temp[**ret] = '\0';
			buff = ft_join(buff, temp);
			if (**ret != BUFFER_SIZE)
				return (buff);
		}
	return (buff);
}

char	*fill_line(char **buff, int fd, int *ret)
{
	char			*line;

	if (!(*buff) || chrsdl(*buff) < 0)
	{
		*buff = perecastor(*buff, fd, &ret);
		if (*ret != BUFFER_SIZE && chrsdl(*buff) < 0)
		{
			*ret = -2;
			line = strdup_n(*buff, 0);
			return (line);
		}
	}
	if (!buff)
		return (NULL);
	line = strdup_n(*buff, 1);
	realic(&buff);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*buff;

	ret = BUFFER_SIZE;
	if (!line || fd < 0 || BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0))
	{
		*line = strdup_n("", 0);
		return (-1);
	}
	*line = fill_line(&buff, fd, &ret);
	if (line == NULL)
	{
		free(buff);
		buff = NULL;
		free(line);
		return (-1);
	}
	if (ret == -2)
	{
		free(buff);
		buff = NULL;
		return (0);
	}
	return (1);
}
