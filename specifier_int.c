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

void	specifier_int(va_list arg, int *p, int *i, t_flag *flag)
{
	if (flag->star1 != 0)
		specifier_int_1(arg, p, i, flag);
	else
		specifier_int_2(arg, p, i, flag);
}

void	specifier_int_2(va_list arg, int *p, int *i, t_flag *flag)
{
	int x;

	x = va_arg(arg, int);
	if (flag->point == 0)
	{
		if (flag->n1 != 0 && flag->zero == 0)
			handle_5(flag->n1, p, x, flag, ' ');
		else if (flag->n1 != 0 && flag->zero == 1)//ATTENTION STR
			handle_5(flag->n1, p, x, flag, '0');//! pas utilise, cherche derniere faute du test
		else
			ft_putnbr(x, p);
	}
	else if (flag->point != 0)
	{
		if (flag->n2 == 0 && flag->n1 != 0)//ATTENTION STR
			handle_3(p, flag);
		else if (flag->n1 != 0 && flag->n2 != 0)
			handle_6(flag->n1, p, x, flag);
		else
			ft_putnbr(x, p);//ATTNETION STR
	}
	*i += 1;
}

void	specifier_int_1(va_list arg, int *p, int *i, t_flag *flag)
{
	int x;
	int nb;

	nb = va_arg(arg, int);
	x = va_arg(arg, int);
	if (nb < 0)
	{
		flag->minus = 1;
		nb = nb * -1;
	}
	if (flag->point == 0)
		handle_5(nb, p, x, flag, ' ');
	else if (flag->point != 0)
	{
		handle_2(nb, p, "test", flag);
	}
	*i += 1;
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
