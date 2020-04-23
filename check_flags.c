/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:12:25 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/26 19:35:10 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_0(char *str,int *i, t_flag *flag)
{
	if (str[*i] == '0')
	{
		flag->zero = 1;
		*i += 1;
	}
}

void	check_flags_1(va_list arg, char *str, int *i, t_flag*flag)
{
	while (ft_isdigit(str[*i]) == 1 || str[*i] == '-' || str[*i] == '*')
	{
		if (str[*i] == '-')
		{
			flag->minus = 1;
			*i += 1;
		}
		if (str[*i] == '*')
		{
			flag->n1 = va_arg(arg, int);
			if (flag->n1 < 0)
			{
				flag->minus = 1;
				flag->n1 *= -1;
			}
			*i += 1;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			flag->n1 = (flag->n1 * 10) + (str[*i] - '0');
			*i += 1;
		}
	}
}

void	check_flags_2(char *str, int *i, t_flag*flag)
{
	if (str[*i] == '.')
	{
		flag->point = 1;
		*i += 1;
	}
	if (str[*i] == '0')
	{
		flag->zero = 1;
		*i += 1;
	}
}

void	check_flags_3(va_list arg, char *str, int *i, t_flag*flag)
{
	while (ft_isdigit(str[*i]) == 1 || str[*i] == '-' || str[*i] == '*')
	{
		if (str[*i] == '-')
		{
			flag->minus = 1;
			*i += 1;
		}
		if (str[*i] == '*')
		{
			flag->n2 = va_arg(arg, int);
			*i += 1;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			flag->n2 = (flag->n2 * 10) + (str[*i] - '0');
			*i += 1;
		}
	}
}

void	check_flags(va_list arg, char *str, int *p, int *i, t_flag *flag)
{
	*i = *i + 1;

	check_flags_0(str, i, flag);
	check_flags_1(arg, str, i, flag);
	check_flags_2(str, i, flag);
	check_flags_3(arg, str, i, flag);
	check_specifier(arg, str, p, i, flag);
}
