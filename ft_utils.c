/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:00:09 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 15:16:32 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	handle_1(int nb, int *p, char *x, t_flag *flag)
{
	if ((int)ft_strlen(x) > nb)
		ft_putstr(x, p, ft_strlen(x));
	else if (flag->minus == 0)
	{
		while(nb - ft_strlen(x) > 0)
		{
			ft_putchar(' ', p);
			nb -= 1;
		}
		ft_putstr(x, p, ft_strlen(x));
	}
	else if (flag->minus == 1)
	{
		ft_putstr(x, p, ft_strlen(x));
		while(nb - ft_strlen(x) > 0)
		{
			ft_putchar(' ', p);
			nb -= 1;
		}
	}
}

void	handle_2(int nb, int *p, char *x, t_flag *flag)
{
	if (flag->n2 > (int)ft_strlen(x))//cast est bon ici? strlen = size_t
		flag->n2 = (int)ft_strlen(x);
	if (flag->minus == 0)
	{
		while(nb - flag->n2 > 0)
		{
			ft_putchar(' ', p);
			nb -= 1;
		}
		ft_putstr(x, p, flag->n2);
	}
	else if (flag->minus == 1)
	{
		ft_putstr(x, p, flag->n2);
		while(nb - flag->n2 > 0)
		{
			ft_putchar(' ', p);
			nb -= 1;
		}
	}
}

void	print_space_zero(int nb, int *p, unsigned char x, t_flag *flag)
{
	if (flag->minus == 0)
	{
		while(nb - 1 > 0)
		{
			ft_putchar(' ', p);
			nb -= 1;
		}
		ft_putchar(x, p);
	}
	if (flag->minus == 1)
	{
		ft_putchar(x, p);
		while(nb - 1 > 0)
		{
			ft_putchar(' ', p);
			nb -= 1;
		}
	}
}
