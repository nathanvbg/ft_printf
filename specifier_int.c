/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:41:28 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/23 17:32:40 by nathanvbg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_int(va_list arg, t_index *idx)
{
	int nb;
	char *x;
	int len;

	nb = va_arg(arg, int);
	if (nb < 0)
	{
		idx->neg = 1;
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
	int_tri_flags(idx, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

void	int_tri_flags(t_index *idx, char *x, int len)
{
	if (idx->point == 1 && idx->n2 == 0 && idx->minus == 0)
	{
		if (x[0] == '0' && x[1] == '\0')
			print_only_c(idx, (idx->n1), ' ');
		else
		{
			print_only_c(idx, (idx->n1 - len - idx->neg), ' ');
			if (idx->neg == 1)
				ft_putchar('-', &idx->p);//pq & ici?
			ft_putstr(x, &idx->p, len);//attention
		}
		idx->i += 1;
	}
	else if (idx->point == 0)
		int_no_point(idx, x, len);
	else if (idx->point != 0)
		{
			if (idx->minus == 0)
				int_point_plus(idx, x, len);
			else
				int_point_minus(idx, x, len);
		}
}

void	int_no_point(t_index *idx, char *x, int len)
{
	if (idx->neg == 1)
	{
		if (((len + 1) >= idx->n1) || (idx->minus == 1) 
			|| idx->zero == 1)
				ft_putchar('-', &idx->p);
		else if (idx->minus == 0 && idx->zero == 0)
			{
					print_only_c(idx, (idx->n1 - len - 1), ' ');
					ft_putchar('-', &idx->p);
			}
		if (idx->zero == 1)
			print_only_c(idx, (idx->n1 - len - 1), '0');
		ft_putstr(x, &idx->p, len);
		if (idx->minus == 1)
			print_only_c(idx, (idx->n1 - len - 1), ' ');
	}
	else if (idx->n1 != 0 && idx->zero == 0)
		str_no_point(idx->n1, x, ' ', idx);
	else if (idx->n1 != 0 && idx->zero == 1)
		str_no_point(idx->n1, x, '0', idx);
	else
		ft_putstr(x, &idx->p, len);
	idx->i += 1;
}

void	int_point_plus(t_index *idx, char *x, int len)
{
	//printf("jeeai");
	if ((idx->n1 > idx->n2) && (idx->n2 > len) && (idx->neg == 0))
		print_only_c(idx, (idx->n1 - idx->n2), ' ');
	if((idx->n1 > idx->n2) && (idx->n2 > len) && (idx->neg == 1))
		print_only_c(idx, (idx->n1 - idx->n2 - 1), ' ');
	if ((idx->n1 > len) && (idx->n2 <= len) 
			&& (idx->n2 >= 0)  && (idx->neg == 0))
		print_only_c(idx, (idx->n1 - len), ' ');
	if (idx->n1 > len && idx->n2 <= len && idx->n2 > 0 && idx->neg == 1)
		print_only_c(idx, (idx->n1 - len - 1), ' ');
	if (idx->n2 < 0 && idx->zero == 0 && idx->neg == 1)
		print_only_c(idx, (idx->n1 - len - 1), ' ');
	if (idx->neg == 1)
		ft_putchar('-', &idx->p);
	if (idx->n2 < 0 && idx->zero == 0 && idx->neg == 1)
		ft_putstr(x, &idx->p, ft_strlen(x));
	else if (idx->zero == 1 && idx->n2 < 0 && idx->neg == 1)
		str_no_point(idx->n1 - 1, x, '0', idx);
	else if (idx->zero == 1 && idx->n2 < 0 && idx->neg == 0)
		str_no_point(idx->n1, x, '0', idx);
	else if (idx->n2 > 0)
		str_no_point(idx->n2, x, '0', idx);
	else
		str_point(idx->n1, x, idx);
	idx->i += 1;
}

void	int_point_minus(t_index *idx, char *x, int len)
{
	//printf("jeeai");
	if (idx->minus == 1 && x[0] == '0' && x[1] == '\0' && idx->n2 == 0)
		print_only_c(idx, idx->n1, ' ');
	else
	{
		if (len < idx->n2)
			len = idx->n2;
		if (idx->neg == 1)
			ft_putchar('-', &idx->p);
		idx->minus = 0;
		str_no_point(idx->n2, x, '0', idx);
		if (idx->neg == 0)
			print_only_c(idx, (idx->n1 - len), ' ');
		else
			print_only_c(idx, (idx->n1 - len - 1), ' ');
	}
	idx->i += 1;
}
