/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:27:12 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/23 19:42:56 by nathanvbg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_index(t_index *idx)
{
	idx->zero = 0;
	idx->zero_perc = 0;
	idx->point = 0;
	idx->minus = 0;
	idx->neg = 0;
	idx->percentage = 0;
	idx->n1 = 0;
	idx->n2 = 0;
}

int		ft_printf(const char *fmt, ...)
{
	va_list arg;
	t_index idx;

	va_start(arg, fmt);
	idx.i = 0;
	idx.p = 0;
	while (fmt[idx.i])
	{
		ft_init_index(&idx);
		if (fmt[idx.i] == '%')
		{
			if (check_flags(arg, fmt, &idx) == -1)
				return (-1);
		}
		else
		{
			ft_putchar(fmt[idx.i], &idx.p);
			idx.i++;
		}
	}
	va_end(arg);
	return (idx.p);
}

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
		return (specifier_hex(arg, idx));
	else if (str[idx->i] == 'p')
		return (specifier_p(arg, idx));
	else
		return (0);
}
