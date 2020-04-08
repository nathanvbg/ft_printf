/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:00:09 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 16:41:43 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
//	return (i);
}

void	handle_1(int nb, int *p, char *x, t_flag *flag, char c)
{
	if ((int)ft_strlen(x) > nb)
		ft_putstr(x, p, ft_strlen(x));
	else if (flag->minus == 0)
	{
		while(nb - ft_strlen(x) > 0)
		{
			ft_putchar(c, p);
			nb -= 1;
		}
		ft_putstr(x, p, ft_strlen(x));
	}
	else if (flag->minus == 1)
	{
		ft_putstr(x, p, ft_strlen(x));
		while(nb - ft_strlen(x) > 0)
		{
			ft_putchar(c, p);
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

void	print_only_space(int *p, int i)//pour str
{
	if (i != 0)
	{
		while (i > 0)
		{
			ft_putchar(' ', p);
			i -= 1;
		}
	}
	//else if (flag->n1 == 0)
}

/*
void	handle_5(int nb, int *p, char *x, t_flag *flag, char c)
{
	if ((int)ft_strlen(x) > nb)
		ft_putstr(x, p, ft_strlen(x));
	else if (flag->minus == 0)
	{
		while(nb - ft_strlen(x) > 0)
		{
			ft_putchar(c, p);
			nb -= 1;
		}
		ft_putstr(x, p, ft_strlen(x));
	}
	else if (flag->minus == 1)
	{
		ft_putstr(x, p, ft_strlen(x));
		while(nb - ft_strlen(x) > 0)
		{
			ft_putchar(c, p);
			nb -= 1;
		}
	}
}
void	handle_6(int nb, int *p, int x, t_flag *flag)
{
	nb = 0;
	if ((ft_intlen(x) >= flag->n1) && (ft_intlen(x) >= flag->n2))
		ft_putnbr(x, p);
	else if (flag->n2 > ft_intlen(x) && flag->n2 >= flag->n1)
	{
		if (x < 0)
		{
			ft_putchar('-', p);
			x *= -1;
		}
		handle_5(flag->n2, p, x, flag,'0');
	}
	else if (flag->n1 > flag->n2 && flag->n2 > ft_intlen(x))
	{
		handle_7(p, x, flag);
		if (x < 0)
			x *= -1;
		handle_5(flag->n2, p, x, flag, '0');
	}
}

void	handle_7(int *p, int x, t_flag *flag)
{
	while (flag->n1 > flag->n2 + 1)
	{
		ft_putchar(' ', p);
		flag->n1 -= 1;
	}
	if (x < 0)
	{
		ft_putchar('-', p);
	}
	else
	ft_putchar(' ', p);
}
*/
