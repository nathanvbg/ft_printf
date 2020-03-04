/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:05:38 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 13:32:04 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		star1;
	int		star2;
	int		minus;
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
void			check_flags_1(char *str, int *i, t_flag *flag);
void			check_flags_2(char *str, int *i, t_flag *flag);
void			check_flags_3(char *str, int *i, t_flag *flag);
void			check_specifier(va_list arg, char *str, int *p, int *i, t_flag *flag);
void			specifier_int(va_list arg, int *p, int *i);
void			specifier_uint(va_list arg, int *p, int *i);
void			specifier_x(va_list arg, int *p, int *i);
void			specifier_hex(va_list arg, int *p, int *i);
void			specifier_char(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_char_1(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_char_2(va_list arg, int *p, int *i, t_flag *flag);
void			print_space_zero(int nb, int *p, unsigned char x, t_flag *flag);
void			specifier_str(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_str_1(va_list arg, int *p, int *i, t_flag *flag);
void			specifier_str_2(va_list arg, int *p, int *i, t_flag *flag);
void			handle_1(int nb, int *p, char *x, t_flag *flag);
void			handle_2(int nb, int *p, char *x, t_flag *flag);
void			specifier_pointer(va_list arg, int *p, int *i);
void			flags_percentage(int *p, int *i);
void			flags_zero(va_list arg, char *str, int *p, int *i);
void			nbr_zero_int(va_list arg, char *str, int *p, int *i, int n);
void			nbr_zero_hex(va_list arg, char *str, int *p, int *i, int n);
int				count_nbr(int n, int base);

#endif
