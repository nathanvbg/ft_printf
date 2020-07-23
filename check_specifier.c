/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:11:34 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/23 13:51:34 by nathanvbg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_specifier(va_list arg, const char *str, t_index *idx)
{
	if (str[idx->i] == '%')
		return (specifier_perc(idx));
	else if (str[idx->i] == 'd')
		return (specifier_int(arg, idx));
	else if (str[idx->i] == 'i')
		return (specifier_int(arg, idx));
	else if (str[idx->i] == 'u')
		return (specifier_u(arg, idx));
	else if (str[idx->i] == 'c')
		return (specifier_char(arg, idx));
	else if (str[idx->i] == 's')
		return (specifier_str(arg, idx));
	else if (str[idx->i] == 'x')
		return (specifier_x(arg, idx));
	else if (str[idx->i] == 'X')
		return (specifier_X(arg, idx));
	else if (str[idx->i] == 'p')
		return (specifier_p(arg, idx));
	else
		return (0);
}
