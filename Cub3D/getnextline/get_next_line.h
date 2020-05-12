/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:17:26 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:30:19 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 500

int			chrsdl(char *temp);
char		*ft_join(char *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_eof(char **buff);
char		*fill_line(char **buff, int fd, int *ret);
char		*strdup_n(const char *s1, int backn);
void		realic(char ***s1);
int			get_next_line(int fd, char **line);
char		*perecastor(char *buff, int fd, int **ret);

#endif
