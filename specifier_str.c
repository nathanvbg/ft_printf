/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:15:20 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 13:32:28 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier_str(va_list arg, int *p, int *i, t_flag *flag)
{
	if (flag->star1 != 0)
		specifier_str_1(arg, p, i, flag);
	else
		specifier_str_2(arg, p, i, flag);
}

void	specifier_str_2(va_list arg, int *p, int *i, t_flag *flag)
{
	char *x;

	x = va_arg(arg, char*);
	if (flag->point == 0)
	{
		if (flag->n1 != 0)
			handle_1(flag->n1, p, x, flag);
		else
			ft_putstr(x, p, ft_strlen(x));
	}
	else if (flag->point != 0)
	{
		
	}
	*i += 1;
}

void	specifier_str_1(va_list arg, int *p, int *i, t_flag *flag)
{
	char	*x;
	int		nb;

	nb = va_arg(arg, int);
	x = va_arg(arg, char*);
	if (nb < 0)
	{
		flag->minus = 1;
		nb = nb * -1;
	}
	if (flag->point == 0)
		handle_1(nb, p, x, flag);
	else if (flag->point != 0)
	{
		handle_2(nb, p, x, flag);
	}
	*i += 1;
}
