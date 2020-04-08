/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:33:52 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/24 18:23:42 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// done
// specifier : c
// flags :-, ., *, 0(! cas avec -), %

//
// not done
// specifier : d et i, s, u, x, X, p(mais pas bien compris

#include "ft_printf.h"

int		main(void)
{

	//ft_printf("=%d\n", ft_printf("%.6d", 3));

	printf("=%d\n\n", printf("%-10.15d\n", -123));
	printf("=%d\n\n", printf("%-15.10d\n", -123));

return(0);
}
