/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:15:20 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/23 15:23:29 by nathanvbg        ###   ########.fr       */
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

	x = va_arg(arg, char*);//comment securiser ? on ne securise pas ? pq SIGABRT quand je le free ? pq evrard ne le free pas ? pq ligne d en dessous ?
	if (!x)// if (!(x = va_arg(arg, char*)))
				//x == "(null)";
		x = "(null)";// PQQ??
	if (idx->point == 0)
	{
		if (idx->n1 != 0 && idx->zero == 0)
			str_no_point(idx->n1, x, ' ', idx);
		else if (idx->n1 != 0 && idx->zero == 1)
			str_no_point(idx->n1, x, '0', idx);
		else
			ft_putstr(x, &idx->p, ft_strlen(x));
	}
	else if (idx->point != 0)
	{
		if (idx->n2 == 0 && idx->n1 != 0)
			print_only_c(idx, idx->n1, ' ');
		else if (idx->n1 != 0 && idx->n2 != 0)
			str_point(idx->n1, x, idx);
		else if (idx->n2 > 0)
			ft_putstr(x, &idx->p, idx->n2);
		else if (idx->n2 < 0)
			ft_putstr(x, &idx->p, ft_strlen(x));
	}
	idx->i += 1;
	return (0);
}

void	str_no_point(int nb, char *x, char c, t_index *idx)
{
	if (idx->minus == 0)
		print_only_c(idx, (nb - ft_strlen(x)), c);
	ft_putstr(x, &idx->p, ft_strlen(x));
	if (idx->minus == 1)
		print_only_c(idx, (nb - ft_strlen(x)), c);
}

void	str_point(int nb, char *x, t_index *idx)
{
	if (idx->n2 > ft_strlen(x) || idx->n2 < 0)
		idx->n2 = ft_strlen(x);
	if (idx->minus == 0)
		print_only_c(idx, (nb - idx->n2), ' ');
	ft_putstr(x, &idx->p, idx->n2);
	if (idx->minus == 1)
		print_only_c(idx, (nb - idx->n2), ' ');
}
void	print_only_c(t_index *idx, int nb, char c)
{
	if (nb > 0)
	{
		while (nb > 0)
		{
			ft_putchar(c, &idx->p);
			nb -= 1;
		}
	}
}
