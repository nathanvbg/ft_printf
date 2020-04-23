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
	//static char	a01;
/*static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

	//ft_printf("=%d\n", ft_printf("%.6d", 3));

	ft_printf("=%d\n\n", ft_printf("%p\n", &a01));
	printf("=%d\n\n", printf("%5p\n", &a01));
*/
ft_printf("=%d\n\n", ft_printf("%s%s\n", "hello", "world"
));
//printf("=%d\n\n", printf("%s%s\n", "hello", "world"));
return(0);
}
