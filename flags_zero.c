/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:36:56 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/19 17:44:36 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_nbr(int n, int base)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i += 1;
		n *= -1;
	}
	while (n > 0)
	{
		i += 1;
		n = n / base;
	}
	return (i);
}

void	nbr_zero_int(va_list arg, char *str, int *p, int *i, int n)
{
	int tmp;
	int diff;

	tmp = va_arg(arg, int);
	diff = n - count_nbr(tmp, 10);
	while (diff > 0)
	{
		ft_putchar('0', p);
		diff--;
	}
	if (str[*i] == 'i' || str[*i] == 'd')
		ft_putnbr(tmp, p);
	if (str[*i] == 'u')
		ft_putnbr_u(tmp, p);
}

void	nbr_zero_hex(va_list arg, char *str, int *p, int *i, int n)
{
	unsigned int tmp;
	int diff;

	tmp = va_arg(arg, unsigned int);
	diff = n - count_nbr(tmp, 16);
	while (diff > 0)
	{
		ft_putchar('0', p);
		diff--;
	}
	if (str[*i] == 'x')
		ft_utoh(tmp, p);
	if (str[*i] == 'X')
		ft_utohex(tmp, p);
}

void	flags_zero(va_list arg, char *str, int *p, int *i)//doit encore gerer 0- ou 0+
{
	long int n; // doit traiter les int et les unsigned int, du coup alz si je met un long?

	while (str[*i] >= '0' && str[*i] <= '9')
	{
		n = (n * 10) + str[*i] - '0';
		*i += 1;
	}
	if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u')
	{
		nbr_zero_int(arg, str, p, i, n);
		*i += 1;
	}
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		nbr_zero_hex(arg, str,  p, i, n);
		*i += 1;
	}
}
