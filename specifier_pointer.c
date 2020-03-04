/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:09:26 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/21 13:46:47 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier_pointer(va_list arg, int *p, int *i)//seule difference avec hex c est que l argument est un unsigned long ou size_t ? 
{
	size_t x;// ou unsigned long?

	x = va_arg(arg, size_t);
	ft_putchar('0', p);
	ft_putchar('x', p);
	ft_stoh(x, p);
	*i = *i + 1;
}

