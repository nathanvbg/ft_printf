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
		specifier_char_2(arg, p, i, flag);//useless
}
void	specifier_char_2(va_list arg, int *p, int *i, t_flag *flag)
{
	char x;// unsigned char dans d autres travaux, pq..?

	x = (char)va_arg(arg, int);//??? char int ???
	if (flag->n1 != 0)
		print_space(flag->n1, p, x, flag);
	else
		ft_putchar(x, p);
	*i += 1;
}

void	print_space(int nb, int *p, char x, t_flag *flag)
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

/*
 void    handle_1(int nb, int *p, char *x, t_flag *flag, char c)
 {
     if (flag->n2 == 0)
         flag->n2 = (int)ft_strlen(x);//cast bon?
     else if (flag->n2 > (int)ft_strlen(x))
         flag->n2 = (int)ft_strlen(x);
     if (flag->n2 > nb)
         ft_putstr(x, p, flag->n2);
     else if (flag->minus == 0)
     {
         while(nb - flag->n2 > 0)
         {
             ft_putchar(c, p);
             nb -= 1;
         }
         ft_putstr(x, p, flag->n2);
     }
     else if (flag->minus == 1)
     {
         ft_putstr(x, p, flag->n2);
         while(nb - flag->n2 > 0)
         {
             ft_putchar(c, p);
             nb -= 1;
         }
     }
 }
 */
