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

int		specifier_int(va_list arg, int *p, int *i, t_flag *flag)
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
	if (nb == INT_MIN)//pq int_min pas int_max?
	{
		if ((x = ft_strdup("2147483648")) == NULL)
			(ft_free(&x, -1));
	}
	else
	{
		if (!(x = ft_itoa(nb)))
			ft_free(&x, -1);
	}
	len = ft_strlen(x);
	int_tri_flags(p, i, flag, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

void	int_tri_flags(int *p, int *i, t_flag *flag, char *x, int len)
{
	if (flag->point == 1 && flag->n2 == 0 && flag->minus == 0)
	{
		if (x[0] == '0' && x[1] == '\0')
			print_only_c(p, (flag->n1), ' ');
		else
		{
			print_only_c(p, (flag->n1 - len - flag->neg), ' ');
			if (flag->neg == 1)
				ft_putchar('-', p);
			ft_putstr(x, p, len);
		}
		*i += 1;
	}
	else if (flag->point == 0)
		int_no_point(p, i, flag, x, len);
	else if (flag->point != 0)
		{
			if (flag->minus == 0)
				int_point_plus(p, i, flag, x, len);
			else
				int_point_minus(p, i, flag, x, len);
		}
}

void	int_no_point(int *p, int *i, t_flag *flag, char *x, int len)
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
		str_no_point(flag->n1, p, x, flag, ' ');
	else if (flag->n1 != 0 && flag->zero == 1)
		str_no_point(flag->n1, p, x, flag, '0');
	else
		ft_putstr(x, p, len);
	*i+=1;
}

void	int_point_plus(int *p, int *i, t_flag *flag, char *x, int len)
{
	//printf("jeeai");
	if ((flag->n1 > flag->n2) && (flag->n2 > len) && (flag->neg == 0))
		print_only_c(p, (flag->n1 - flag->n2), ' ');
	if((flag->n1 > flag->n2) && (flag->n2 > len) && (flag->neg == 1))
		print_only_c(p, (flag->n1 - flag->n2 - 1), ' ');
	if ((flag->n1 > len) && (flag->n2 <= len) 
			&& (flag->n2 >= 0)  && (flag->neg == 0))
		print_only_c(p, (flag->n1 - len), ' ');
	if (flag->n1 > len && flag->n2 <= len && flag->n2 > 0 && flag->neg == 1)
		print_only_c(p, (flag->n1 - len - 1), ' ');
	if (flag->n2 < 0 && flag->zero == 0 && flag->neg == 1)
		print_only_c(p, (flag->n1 - len - 1), ' ');
	if (flag->neg == 1)
		ft_putchar('-', p);
	if (flag->n2 < 0 && flag->zero == 0 && flag->neg == 1)
		ft_putstr(x, p, ft_strlen(x));
	else if (flag->zero == 1 && flag->n2 < 0 && flag->neg == 1)
		str_no_point(flag->n1 - 1, p, x, flag, '0');
	else if (flag->zero == 1 && flag->n2 < 0 && flag->neg == 0)
		str_no_point(flag->n1, p, x, flag, '0');
	else if (flag->n2 > 0)
		str_no_point(flag->n2, p, x, flag, '0');
	else
		str_point(flag->n1, p, x, flag);
	*i += 1;
}

void	int_point_minus(int *p, int *i, t_flag *flag, char *x, int len)
{
	//printf("jeeai");
	if (flag->minus == 1 && x[0] == '0' && x[1] == '\0' && flag->n2 == 0)
		print_only_c(p, flag->n1, ' ');
	else
	{
		if (len < flag->n2)
			len = flag->n2;
		if (flag->neg == 1)
			ft_putchar('-', p);
		flag->minus = 0;
		str_no_point(flag->n2, p, x, flag, '0');
		if (flag->neg == 0)
			print_only_c(p, (flag->n1 - len), ' ');
		else
			print_only_c(p, (flag->n1 - len - 1), ' ');
	}
	*i += 1;
}
