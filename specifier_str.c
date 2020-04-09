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

void	specifier_str(va_list arg, int *p, int *i, t_flag *flag)
{
		specifier_str_2(arg, p, i, flag);//useless
}

void	specifier_str_2(va_list arg, int *p, int *i, t_flag *flag)
{
	char *x;

	x = va_arg(arg, char*);
	if (flag->point == 0)
	{
		if (flag->n1 != 0 && flag->zero == 0)
			handle_1(flag->n1, p, x, flag, ' ');
		else if (flag->n1 != 0 && flag->zero == 1)
			handle_1(flag->n1, p, x, flag, '0');//! pas utilise, cherche derniere faute du test
		else
			ft_putstr(x, p, ft_strlen(x));
	}
	else if (flag->point != 0)
	{
		if (flag->n2 == 0 && flag->n1 != 0)
			print_only_c(p, flag->n1, ' ');
		else if (flag->n1 != 0)
			handle_2(flag->n1, p, x, flag);
		else
			ft_putstr(x, p, flag->n2);
	}
	*i += 1;
}
