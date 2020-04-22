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
	int len;

	nb = va_arg(arg, int);
	if (nb < 0)
	{
		flag->neg = 1;
		nb = -nb;
	}
	if (!(x = ft_itoa(nb)))
		ft_free(&x);
	len = ft_strlen(x);
	tri_flags(p, i, flag, x, len);
}

void	tri_flags(int *p, int *i, t_flag *flag, char *x, int len)
{
	if (flag->minus == 1)
		flag->zero = 0;
	if (flag->point == 1 && flag->n2 == 0)
	{
		print_only_c(p, flag->n1, ' ');
		*i += 1;
	}
	else if (flag->point == 0)
		no_point(p, i, flag, x, len);
	else if (flag->point != 0)
		{
			if (flag->minus == 0)
				int_point_plus(p, i, flag, x, len);
			else
				int_point_minus(p, i, flag, x, len);
		}
}

void	no_point(int *p, int *i, t_flag *flag, char *x, int len)
{
	if (flag->neg == 1)
	{
		if (((len + 1) >= flag->n1) || (flag->minus == 1) 
			|| flag->zero == 1)
				ft_putchar('-', p);
		else if (flag->minus == 0 && flag->zero == 0)
			{
					print_only_c(p, (flag->n1 - len - 1), ' ');
					ft_putchar('-', p);
			}
		if (flag->zero == 1)
			print_only_c(p, (flag->n1 - len - 1), '0');
		ft_putstr(x, p, len);
		if (flag->minus == 1)
			print_only_c(p, (flag->n1 - len - 1), ' ');
	}
	else if (flag->n1 != 0 && flag->zero == 0)
		handle_1(flag->n1, p, x, flag, ' ');
	else if (flag->n1 != 0 && flag->zero == 1)
			handle_1(flag->n1, p, x, flag, '0');
	else
		ft_putstr(x, p, len);
	*i+=1;
}

void	int_point_plus(int *p, int *i, t_flag *flag, char *x, int len)
{
	if ((flag->n1 > flag->n2) && (flag->n2 > len) && (flag->neg == 0))
		print_only_c(p, (flag->n1 - flag->n2), ' ');
	if((flag->n1 > flag->n2) && (flag->n2 > len) && (flag->neg == 1))
		print_only_c(p, (flag->n1 - flag->n2 - 1), ' ');
	if ((flag->n1 > len) && (flag->n2 < len) && (flag->neg == 0))
		print_only_c(p, (flag->n1 - len), ' ');
	if ((flag->n1 > len) && (flag->n2 < len )&& flag->neg == 1)
		print_only_c(p, (flag->n1 - len - 1), ' ');
	if (flag->neg == 1)
		ft_putchar('-', p);
	handle_1(flag->n2, p, x, flag, '0');
	*i += 1;
}

void	int_point_minus(int *p, int *i, t_flag *flag, char *x, int len)
{
	if (len < flag->n2)
		len = flag->n2;
	if (flag->neg == 1)
		ft_putchar('-', p);
	flag->minus = 0;
	handle_1(flag->n2, p, x, flag, '0');
	if (flag->neg == 0)
		print_only_c(p, (flag->n1 - len), ' ');
	else
		print_only_c(p, (flag->n1 - len - 1), ' ');
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
