/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:27:12 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/26 19:45:06 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flag(t_flag *flag)
{
	flag->zero = 0;
	flag->point = 0;
	flag->minus = 0;
	flag->percentage = 0;
	flag->n1 = 0;
	flag->n2 = 0;
}

void	ft_init_compteur(t_compteur *compteur)
{
	compteur->i = 0;
	compteur->p = 0;
}

int		ft_printf(char *fmt, ...)
{
	va_list arg;
	t_flag flag;
	t_compteur compteur;

	va_start(arg, fmt);
	ft_init_compteur(&compteur);
	while (fmt[compteur.i])
	{
		ft_init_flag(&flag);
		if (fmt[compteur.i] == '%')
		{
			check_flags(arg, fmt, &compteur.p, &compteur.i, &flag);
		}
		else
		{
			ft_putchar(fmt[compteur.i], &compteur.p);
			compteur.i++;
		}
	}
	va_end(arg);


//	printf("%d\n%d\n%d\n%d\n%d\n", flag.minus, flag.star1, flag.n1, flag.star2, flag.n2);


	return(compteur.p);
}
