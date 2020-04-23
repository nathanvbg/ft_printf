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

# include <stdarg.h>
# include <unistd.h>

# include <stdio.h>

# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	int		zero;
	int		point;
	int		percentage;
	int		minus;
	int		neg;
	int		n1;
	int		n2;
}				t_flag;

typedef struct	s_compteur
{
	int		i;
	int		p;
}				t_compteur;

int				ft_printf(char *cnt, ...);
void			check_flags(va_list arg, char *str, int *p, int *i, t_flag *flag);
void			check_flags_0(char *str, int *i, t_flag *flag);
void			check_flags_1(va_list arg, char *str, int *i, t_flag *flag);
void			check_flags_2(char *str, int *i, t_flag *flag);
void			check_flags_3(va_list arg, char *str, int *i, t_flag *flag);
void			check_specifier(va_list arg, char *str, int *p, int *i, t_flag *flag);
void			specifier_uint(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_x(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_hex(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_pointer(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_percentage(int *p, int *i, t_flag *flag);
void			specifier_char(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_char_2(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_str(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_int(va_list arg, int *p, int *i, t_flag *flag);
void			tri_flags(int *p, int *i, t_flag *flag, char *x, int len);
void			no_point(int *p, int *i, t_flag *flag, char *x, int len);
void			int_point_plus(int *p, int *i, t_flag *flag, char *x, int len);
void			int_point_minus(int *p, int *i, t_flag *flag, char *x, int len);
void			handle_1(int nb, int *p, char *x, t_flag *flag, char c);
void			handle_2(int nb, int *p, char *x, t_flag *flag);
void			print_only_c(int *p, int nb, char c);
void			print_space(int nb, int *p, char x, t_flag *flag);
void			ft_free(char** str);

#endif
