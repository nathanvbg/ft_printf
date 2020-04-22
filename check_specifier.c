/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:11:34 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/26 20:18:28 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_specifier(va_list arg, char *str, int *p, int *i, t_flag *flag)
{
str[*i] == 'd' ? specifier_int(arg, p, i, flag) : 0;
str[*i] == 'i' ? specifier_int(arg, p, i, flag) : 0;
str[*i] == 'u' ? specifier_uint(arg, p, i, flag) : 0;
str[*i] == 'c' ? specifier_char(arg, p, i, flag) : 0;
str[*i] == 's' ? specifier_str(arg, p, i, flag) : 0;
str[*i] == 'x' ? specifier_x(arg, p, i, flag) : 0;
str[*i] == 'X' ? specifier_hex(arg, p, i, flag) : 0;
str[*i] == 'p' ? specifier_pointer(arg, p, i, flag) : 0;
}
