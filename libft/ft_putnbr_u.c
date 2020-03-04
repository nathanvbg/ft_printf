/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:13:52 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/17 17:10:25 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_u(unsigned int x, int *p)
{
	if (x > 9)
	{
		ft_putnbr_u(x / 10, p);
		ft_putnbr_u(x % 10, p);
	}
	else
		ft_putchar(x + 48, p);
}
