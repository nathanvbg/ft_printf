/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:27:12 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/21 12:16:01 by nathanvbg        ###   ########.fr       */
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
	return(idx.p);
}
