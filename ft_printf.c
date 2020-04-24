/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:27:12 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/26 19:45:06 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_free(char **str, int i)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (i);
}

void	ft_init_flag(t_flag *flag)
{
	flag->zero = 0;
	flag->point = 0;
	flag->minus = 0;
	flag->neg = 0;
	flag->percentage = 0;
	flag->n1 = 0;
	flag->n2 = 0;
}

int		ft_printf(char *fmt, ...)
{
	va_list arg;
	t_flag flag;

	va_start(arg, fmt);
	flag.i = 0;
	flag.p = 0;
	while (fmt[flag.i])
	{
		ft_init_flag(&flag);
		if (fmt[flag.i] == '%')
		{
			if (check_flags(arg, fmt, &flag.p, &flag.i, &flag) == -1)
				return (-1);
		}
		else
		{
			ft_putchar(fmt[flag.i], &flag.p);
			flag.i++;
		}
	}
	va_end(arg);
	return(flag.p);
}
