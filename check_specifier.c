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

int		specifier(va_list arg, const char *str, int *p, int *i, t_flag *flag)
{
	if (str[*i] == '%')
		return (specifier_perc(p, i, flag));
	else if (str[*i] == 'd')
		return (specifier_int(arg, p, i, flag));
	else if (str[*i] == 'i')
		return (specifier_int(arg, p, i, flag));
	else if (str[*i] == 'u')
		return (specifier_u(arg, p, i, flag));
	else if (str[*i] == 'c')
		return (specifier_char(arg, p, i, flag));
	else if (str[*i] == 's')
		return (specifier_str(arg, p, i, flag));
	else if (str[*i] == 'x')
		return (specifier_x(arg, p, i, flag));
	else if (str[*i] == 'X')
		return (specifier_X(arg, p, i, flag));
	else if (str[*i] == 'p')
		return (specifier_p(arg, p, i, flag));
	else
		return (0);
}
