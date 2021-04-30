/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:35:54 by nverbrug          #+#    #+#             */
/*   Updated: 2020/08/05 14:03:56 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(va_list arg, const char *str, t_index *idx)
{
	idx->i = idx->i + 1;
	check_flags_0(str, idx);
	check_flags_1(arg, str, idx);
	check_flags_2(str, idx);
	check_flags_3(arg, str, idx);
	if (idx->minus == 1)
		idx->zero = 0;
	if (check_specifier(arg, str, idx) == -1)
		return (-1);
	return (0);
}

void	check_flags_0(const char *str, t_index *idx)
{
	if (str[idx->i] == '0')
	{
		idx->zero = 1;
		idx->i += 1;
	}
}

void	check_flags_1(va_list arg, const char *str, t_index *idx)
{
	while (ft_isdigit(str[idx->i]) == 1 || str[idx->i] == '-'
			|| str[idx->i] == '*')
	{
		if (str[idx->i] == '-')
		{
			idx->minus = 1;
			idx->i += 1;
		}
		if (str[idx->i] == '*')
		{
			idx->n1 = va_arg(arg, int);
			if (idx->n1 < 0)
			{
				idx->minus = 1;
				idx->n1 *= -1;
			}
			idx->i += 1;
		}
		while (str[idx->i] >= '0' && str[idx->i] <= '9')
		{
			idx->n1 = (idx->n1 * 10) + (str[idx->i] - '0');
			idx->i += 1;
		}
	}
}

void	check_flags_2(const char *str, t_index *idx)
{
	if (str[idx->i] == '.')
	{
		idx->point = 1;
		idx->i += 1;
	}
}

void	check_flags_3(va_list arg, const char *str, t_index *idx)
{
	while (ft_isdigit(str[idx->i]) == 1 || str[idx->i] == '-'
			|| str[idx->i] == '*')
	{
		if (str[idx->i] == '0')
		{
			idx->zero_perc = 1;
			idx->i += 1;
		}
		if (str[idx->i] == '-')
		{
			idx->minus = 1;
			idx->i += 1;
		}
		if (str[idx->i] == '*')
		{
			idx->n2 = va_arg(arg, int);
			idx->i += 1;
		}
		while (str[idx->i] >= '0' && str[idx->i] <= '9')
		{
			idx->n2 = (idx->n2 * 10) + (str[idx->i] - '0');
			idx->i += 1;
		}
	}
}
