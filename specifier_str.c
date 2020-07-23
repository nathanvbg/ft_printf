/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:15:20 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/23 19:05:10 by nathanvbg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_char(va_list arg, t_index *idx)
{
	char x;// unsigned char dans d autres travaux, pq..?

	x = (char)va_arg(arg, int);//??? char int ???
	if (idx->minus == 0 && idx->n1 != 0)
		print_only_c(idx, (idx->n1 - 1), ' ');
	ft_putchar(x, &idx->p);
	if (idx->minus == 1 && idx->n1 != 0)
		print_only_c(idx, (idx->n1 - 1), ' ');
	idx->i += 1;
	return (0);
}

int		specifier_str(va_list arg, t_index *idx)
{
	char *x;

	x = va_arg(arg, char*);
	if (!x)
		x = "(null)";
	if (idx->point == 0)
	{
		if (idx->n1 != 0 && idx->zero == 0)
			print_c_no_point(idx->n1, x, ' ', idx);
		else if (idx->n1 != 0 && idx->zero == 1)
			print_c_no_point(idx->n1, x, '0', idx);
		else
			ft_putstr(x, &idx->p, ft_strlen(x));
	}
	else if (idx->point != 0)
		specifier_str_no_point(x, idx);
	idx->i += 1;
	return (0);
}

void	specifier_str_no_point(char *x, t_index *idx)
{
	if (idx->n2 == 0 && idx->n1 != 0)
		print_only_c(idx, idx->n1, ' ');
	else if (idx->n1 != 0 && idx->n2 != 0)
		print_space_point(idx->n1, x, idx);
	else if (idx->n2 > 0)
		ft_putstr(x, &idx->p, idx->n2);
	else if (idx->n2 < 0)
		ft_putstr(x, &idx->p, ft_strlen(x));
}
