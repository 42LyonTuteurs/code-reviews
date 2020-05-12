/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolopez <lolopez@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:36:29 by lolopez           #+#    #+#             */
/*   Updated: 2020/03/10 14:40:43 by lolopez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <inttypes.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct	s_preplist
{
	char	*str;
	va_list	args;
	char	*buffer;
	char	*mask;
	int		(*ft_selector[9])(struct s_preplist *);
	char	tabindex[9];
	int		o;
	int		spb;
	int		spa;
	int		cut;
	int		dot;
	int		count;
}				t_bag;

/*
** printf et lecture basique de la chaine
*/
int				ft_printf(const char *pouet, ...);
void			readline(t_bag *grossac, const char *str);
int				percentpars(t_bag *grossac, const char *pouet, int i);

/*
** gestion du gros sac
*/
void			initgrossac(t_bag *grossac, char	*pouet);
void			clean_grossac(t_bag *grossac);

/*
** gestion des selectors
*/

void			ft_fill_ft(t_bag *grossac);
int				select_c(t_bag *grossac);
int				select_s(t_bag *grossac);
int				select_i(t_bag *grossac);
int				select_p(t_bag *grossac);
int				select_u(t_bag *grossac);
int				select_x(t_bag *grossac);
int				select_bx(t_bag *grossac);
int				select_prcent(t_bag *grossac);
int				selector_index(char c, t_bag *grossac);

/*
** gestion des flags dans mask
*/

char			*maskfiller(t_bag *grossac, int i);
char			*add_zero(t_bag *grossac, char *buff, int len, int minus);
char			*add_space_bf(t_bag *grossac, char *buff, int len, int minus);
char			*add_space_af(t_bag *grossac, char *buff, int len, int minus);
char			*cut_string(t_bag *grossac, char *buff, int len);
int				ft_spb(t_bag *grossac, int i);
int				ft_spa(t_bag *grossac, int i);
int				ft_insecateur(t_bag *grossac, int i);
int				ft_cutzero(t_bag *grossac, int i);
int				ft_dot(t_bag *grossac, int i);
int				ft_cut_temp(t_bag *grossac, int temp);
int				ft_moins(t_bag *grossac, int i);
int				ft_manzero(t_bag *grossac, int i);
void			ft_zero_dot_cut(t_bag *grossac, int i);
int				ft_zero_percent(t_bag *grossac, int i);

/*
** selector c
*/

int				sel_c(t_bag *grossac, int i);
int				ft_aff_backz(t_bag *grossac);
void			fill_buff_c(t_bag *grossac, char c);

/*
** selector s
*/

int				sel_s(t_bag *grossac, int i);
int				select_s(t_bag *grossac);
void			fill_buff_s(t_bag *grossac, char *buff);
void			ft_select_ss(t_bag *grossac);

/*
** selector id
*/

int				select_i(t_bag *grossac);
void			fill_mask_i(t_bag *grossac, int i);
void			fill_buff_i(t_bag *grossac, int	nb);
char			*fill_charbuff(t_bag *grossac, int nb, char **charnb, int len);

/*
** selector u
*/

int				select_u(t_bag *grossac);
void			fill_mask_u(t_bag *grossac, int i);
void			fill_buff_u(t_bag *grossac, int nb);
char			*fill_charbuff_u(t_bag *grossac, char **charnb, int len);

/*
** selector x
*/

int				select_x(t_bag *grossac);
void			fill_mask_x(t_bag *grossac, int i);
void			fill_buff_x(t_bag *grossac, int nb);
char			*fill_charbuff_x(t_bag *grossac, char **charnb, int len);

/*
** selector X
*/

int				select_bx(t_bag *grossac);
void			fill_mask_bx(t_bag *grossac, int i);
void			fill_buff_bx(t_bag *grossac, int nb);
char			*fill_charbuff_bx(t_bag *grossac, char **charnb, int len);

/*
** selector %
*/

int				select_prcent(t_bag *grossac);
int				sel_prcent(t_bag *grossac, int i);
void			fill_buff_prcent(t_bag *grossac);
void			ft_prcent_deg(t_bag *grossac, int i);

/*
** selector p
*/

int				select_p(t_bag *grossac);
void			fill_buff_p(t_bag *grossac, uintptr_t uip);
int				adrss_zero(void);
int				ft_zeroo(t_bag *grossac, int i);

/*
** utils
*/

char			*ft_utoa_base(unsigned int nbr, char *base);
char			*ft_itoa_ll_base(unsigned long n, char *base);
int				ft_atou(char *str);
int				chrchar(char c, char *str);
int				ft_countputstr(char *str);

#endif
