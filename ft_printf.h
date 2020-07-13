/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:05:38 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 16:41:20 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// refaire le f1

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

# include <stdio.h>

# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_flag
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
}				t_flag;

int		ft_printf(const char *cnt, ...);
int		flags(va_list arg, const char *str, int *p, int *i, t_flag *flag);
void	check_flags_0(const char *str, int *i, t_flag *flag);
void	check_flags_1(va_list arg, const char *str, int *i, t_flag *flag);
void	check_flags_2(const char *str, int *i, t_flag *flag);
void	check_flags_3(va_list arg, const char *str, int *i, t_flag *flag);
int		specifier(va_list arg, const char *str, int *p, int *i, t_flag *flag);
int		specifier_u(va_list arg, int *p, int *i, t_flag *flag);
int		specifier_x(va_list arg, int *p, int *i, t_flag *flag);
int		specifier_X(va_list arg, int *p, int *i, t_flag *flag);
int		specifier_p(va_list arg, int *p, int *i, t_flag *flag);
int		specifier_perc(int *p, int *i, t_flag *flag);
int		specifier_char(va_list arg, int *p, int *i, t_flag *flag);
int		specifier_str(va_list arg, int *p, int *i, t_flag *flag);
int		specifier_int(va_list arg, int *p, int *i, t_flag *flag);
void	int_tri_flags(int *p, int *i, t_flag *flag, char *x, int len);
void	int_no_point(int *p, int *i, t_flag *flag, char *x, int len);
void	int_point_plus(int *p, int *i, t_flag *flag, char *x, int len);
void	int_point_minus(int *p, int *i, t_flag *flag, char *x, int len);
void	str_no_point(int nb, int *p, char *x, t_flag *flag, char c);
void	str_point(int nb, int *p, char *x, t_flag *flag);
void	print_only_c(int *p, int nb, char c);
int		ft_free(char** str, int i);

#endif
