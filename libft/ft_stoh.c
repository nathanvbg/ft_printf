/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:45:25 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/21 13:45:50 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stoh(size_t x, int *p)
{
	if (x > 16)
	{
		ft_stoh(x / 16, p);
		ft_stoh(x % 16, p);
	}
	else
	{
		x < 10 ? ft_putchar(x + '0', p) : 0;
		x == 10 ? ft_putchar('a', p) : 0;
		x == 11 ? ft_putchar('b', p) : 0;
		x == 12 ? ft_putchar('c', p) : 0;
		x == 13 ? ft_putchar('d', p) : 0;
		x == 14 ? ft_putchar('e', p) : 0;
		x == 15 ? ft_putchar('f', p) : 0;
	}
}
