/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:15:20 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 16:41:36 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_char(va_list arg, int *p, int *i, t_flag *flag)
{
	char x;// unsigned char dans d autres travaux, pq..?

	x = (char)va_arg(arg, int);//??? char int ???
	if (flag->minus == 0 && flag->n1 != 0)
		print_only_c(p, (flag->n1 - 1), ' ');
	ft_putchar(x, p);
	if (flag->minus == 1 && flag->n1 != 0)
		print_only_c(p, (flag->n1 - 1), ' ');
	*i += 1;
	return (0);
}

int		specifier_str(va_list arg, int *p, int *i, t_flag *flag)
{
	char *x;

	x = va_arg(arg, char*);//comment securiser ? on ne securise pas ? pq SIGABRT quand je le free ? pq evrard ne le free pas ? pq ligne d en dessous ?
	if (!x)// if (!(x = va_arg(arg, char*)))
				//x == "(null)";
		x = "(null)";// PQQ??
	if (flag->point == 0)
	{
		if (flag->n1 != 0 && flag->zero == 0)
			str_no_point(flag->n1, p, x, flag, ' ');
		else if (flag->n1 != 0 && flag->zero == 1)
			str_no_point(flag->n1, p, x, flag, '0');
		else
			ft_putstr(x, p, ft_strlen(x));
	}
	else if (flag->point != 0)
	{
		if (flag->n2 == 0 && flag->n1 != 0)
			print_only_c(p, flag->n1, ' ');
		else if (flag->n1 != 0 && flag->n2 != 0)
			str_point(flag->n1, p, x, flag);
		else if (flag->n2 > 0)
			ft_putstr(x, p, flag->n2);
		else if (flag->n2 < 0)
			ft_putstr(x, p, ft_strlen(x));
	}
	*i += 1;
	return (0);
}

void	str_no_point(int nb, int *p, char *x, t_flag *flag, char c)
{
	if (flag->minus == 0) //|| flag->n2 < 0)
		print_only_c(p, (nb - ft_strlen(x)), c);
	ft_putstr(x, p, ft_strlen(x));
	if (flag->minus == 1)
		print_only_c(p, (nb - ft_strlen(x)), c);
}

void	str_point(int nb, int *p, char *x, t_flag *flag)
{
	if (flag->n2 > ft_strlen(x) || flag->n2 < 0)
		flag->n2 = ft_strlen(x);
	if (flag->minus == 0)
		print_only_c(p, (nb - flag->n2), ' ');
	ft_putstr(x, p, flag->n2);
	if (flag->minus == 1)
		print_only_c(p, (nb - flag->n2), ' ');
}
void	print_only_c(int *p, int nb, char c)
{
	if (nb > 0)
	{
		while (nb > 0)
		{
			ft_putchar(c, p);
			nb -= 1;
		}
	}
}
