/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:36:37 by nverbrug          #+#    #+#             */
/*   Updated: 2020/08/05 13:34:33 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_index
{
	int		zero;
	int		zero_perc;
	int		point;
	int		percentage;
	int		minus;
	int		neg;
	int		n1;
	int		n2;
	int		i;
	int		p;
}				t_index;

int				ft_printf(const char *cnt, ...);
int				check_flags(va_list arg, const char *str, t_index *idx);
void			check_flags_0(const char *str, t_index *idx);
void			check_flags_1(va_list arg, const char *str, t_index *idx);
void			check_flags_2(const char *str, t_index *idx);
void			check_flags_3(va_list arg, const char *str, t_index *idx);
int				check_specifier(va_list arg, const char *str, t_index *idx);
int				specifier_u(va_list arg, t_index *idx);
int				specifier_x(va_list arg, t_index *idx);
int				specifier_hex(va_list arg, t_index *idx);
int				specifier_p(va_list arg, t_index *idx);
int				specifier_perc(t_index *idx);
int				specifier_char(va_list arg, t_index *idx);
int				specifier_str(va_list arg, t_index *idx);
void			specifier_str_no_point(char *x, t_index *idx);
int				specifier_int(va_list arg, t_index *idx);
void			int_tri_flags(t_index *idx, char *x, int len);
void			int_no_point(t_index *idx, char *x, int len);
void			int_point_plus(t_index *idx, char *x, int len);
void			int_point_minus(t_index *idx, char *x, int len);
void			print_c_no_point(int nb, char *x, char c, t_index *idx);
void			print_space_point(int nb, char *x, t_index *idx);
void			print_only_c(t_index *idx, int nb, char c);
int				ft_free(char **str, int i);
void			ft_init_index(t_index *idx);

#endif
