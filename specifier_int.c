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
	int nb;
	char *x;

	nb = va_arg(arg, int);
	if (nb < 0)
	{
		flag->neg_nb = 1;
		nb = -nb;
	}
	if (!(x = ft_itoa(nb)))
		ft_free(&x);
	tri_flags(p, i, flag, x);
}

void	tri_flags(int *p, int *i, t_flag *flag, char *x)
{
	if (flag->minus == 1)
		flag->zero = 0;
	if (flag->point == 0)
		no_point(p, i, flag, x);
	else if (flag->point != 0)
		int_point_1(p, i, flag, x);
}

void	no_point(int *p, int *i, t_flag *flag, char *x)
{
	if (flag->neg_nb == 1)
	{
		if (((ft_strlen(x) + 1) >= flag->n1) || (flag->minus == 1) 
			|| flag->zero == 1)
				ft_putchar('-', p);
		else if (flag->minus == 0 && flag->zero == 0)
			{
					print_only_c(p, (flag->n1 - ft_strlen(x) - 1), ' ');
					ft_putchar('-', p);
			}
		if (flag->zero == 1)
			print_only_c(p, (flag->n1 - ft_strlen(x) - 1), '0');
		ft_putstr(x, p, ft_strlen(x));
		if (flag->minus == 1)
			print_only_c(p, (flag->n1 - ft_strlen(x) - 1), ' ');
	}
	else if (flag->n1 != 0 && flag->zero == 0)
		handle_1(flag->n1, p, x, flag, ' ');
	else if (flag->n1 != 0 && flag->zero == 1)
			handle_1(flag->n1, p, x, flag, '0');
	else
		ft_putstr(x, p, ft_strlen(x));
	*i+=1;
}

void	int_point_1(int *p, int *i, t_flag *flag, char *x)
{
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
