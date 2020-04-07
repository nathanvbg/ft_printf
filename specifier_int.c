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
	if (flag->point == 0)
		specifier_int_2(arg, p, i, flag);
	else if (flag->point != 0)
		specifier_int_3(arg, p, i, flag);
}

void	specifier_int_2(va_list arg, int *p, int *i, t_flag *flag)
{
	char *x;

	x = ft_itoa(va_arg(arg, int));//comment securiser? avec break?
	if (flag->n1 != 0 && flag->zero == 0)
		handle_1(flag->n1, p, x, flag, ' ');
	else if (flag->n1 != 0 && flag->zero == 1)//ATTENTION STR
		handle_1(flag->n1, p, x, flag, '0');//! pas utilise, cherche derniere faute du test
	else
		ft_putstr(x, p, ft_strlen(x));
	*i+=1;
}

void	specifier_int_3(va_list arg, int *p, int *i, t_flag *flag)
{
	char *x;

	x = ft_itoa(va_arg(arg, int));//proteger
	if (flag->n2 == 0 && flag->n1 != 0)
		handle_1(flag->n1, p, x, flag, ' ');
	else if (flag->n1 != 0 && flag->n2 != 0)
	{
		if (flag->n2 > flag->n1)
			handle_1(flag->n1, p, x, flag, '0');
		//else if (flag->n2 < flag->n1)
			
	}
	else if (flag->n1 == 0 && flag->n2 != 0)
		handle_1(flag->n2, p, x, flag, '0');
	else
		ft_putstr(x, p, ft_strlen(x));
	*i += 1;
}

void	specifier_int_1(va_list arg, int *p, int *i, t_flag *flag)
{
	char *x;
	int nb;

	nb = va_arg(arg, int);
	x = ft_itoa(va_arg(arg, int));//securiser
	if (flag->point == 0)
		handle_1(nb, p, x, flag, ' ');
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
