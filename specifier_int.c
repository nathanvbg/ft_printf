/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:41:28 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/19 13:58:07 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

void	specifier_int(va_list arg, int *p, int *i)
{
	int x;

	x = va_arg(arg, int);
	ft_putnbr(x, p);
	*i = *i + 1;
}

void	specifier_uint(va_list arg, int *p, int *i)
{
	unsigned int x;

	x = va_arg(arg, unsigned int);
	ft_putnbr_u(x, p);
	*i = *i + 1;
}

void	specifier_x(va_list arg, int *p, int *i)
{
	unsigned int x;

	x = va_arg(arg, unsigned int);
	ft_utoh(x, p);
	*i = *i + 1;
}

void	specifier_hex(va_list arg, int *p, int *i)
{
	unsigned int x;

	x = va_arg(arg, unsigned int);
	ft_utohex(x, p);
	*i = *i + 1;
}
