/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:44:48 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/02 17:27:16 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas compris le str[0] = 0 du coup on print '\0' = demander gareth
//egalement du mal avec le cast de x et le va_arg = int

#include "ft_printf.h"

void	specifier_char(va_list arg, int *p, int *i, t_flag *flag)
{
	if (flag->star1 != 0)
		specifier_char_1(arg, p, i, flag);
	else
		specifier_char_2(arg, p, i, flag);
}
void	specifier_char_2(va_list arg, int *p, int *i, t_flag *flag)
{
	unsigned char x;

	x = (unsigned char)va_arg(arg, int);
	if (flag->n1 != 0)
		print_space_zero(flag->n1, p, x, flag);
	else
		ft_putchar(x, p);
	*i += 1;
}

void	specifier_char_1(va_list arg, int *p, int *i, t_flag *flag)
{
	unsigned char	x;
	int				nb;

	nb = va_arg(arg, int);
	x = (unsigned char)va_arg(arg, int);
	if (nb < 0)
	{
		flag->minus = 1;
		nb = nb * -1;
	}
	print_space_zero(nb, p, x, flag);
	*i += 1;
}
