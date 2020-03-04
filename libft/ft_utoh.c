/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:31:07 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/19 14:02:19 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_utoh(unsigned int x, int *p)
{
	if (x > 16)
	{
		ft_utoh(x / 16, p);
		ft_utoh(x % 16, p);
	}
	else
	x < 10 ? ft_putchar(x + '0', p) : 0;
	x == 10 ? ft_putchar('a', p) : 0;
	x == 11 ? ft_putchar('b', p) : 0;
	x == 12 ? ft_putchar('c', p) : 0;
	x == 13 ? ft_putchar('d', p) : 0;
	x == 14 ? ft_putchar('e', p) : 0;
	x == 15 ? ft_putchar('f', p) : 0;
}
