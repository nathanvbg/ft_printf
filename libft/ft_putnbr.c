/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:40:56 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/17 14:34:02 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb, int *p)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48, p);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, p);
		ft_putnbr(nb % 10, p);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*p = *p + 11;
	}
	else
	{
		ft_putchar('-', p);
		ft_putnbr(nb * -1, p);
	}
}
