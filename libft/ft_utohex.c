/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:48:51 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/19 14:38:06 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_utohex(unsigned int x, int *p)
{
	if (x > 16)
	{
		ft_utohex(x / 16, p);
		ft_utohex(x % 16, p);
	}
	else
	{
		x < 10 ? ft_putchar(x + '0', p) : 0;
		x == 10 ? ft_putchar('A', p) : 0;
		x == 11 ? ft_putchar('B', p) : 0;
		x == 12 ? ft_putchar('C', p) : 0;
		x == 13 ? ft_putchar('D', p) : 0;
		x == 14 ? ft_putchar('E', p) : 0;
		x == 15 ? ft_putchar('F', p) : 0;
	}
}
