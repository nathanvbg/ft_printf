
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:33:52 by nverbrug          #+#    #+#             */
/*   Updated: 2020/02/24 18:23:42 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int a;
	int b;

	ft_printf("%d\n", 2147483648);
	// [-] prec == 0
	printf("[-] prec == 0\n");
	a = ft_printf("%-10c%-10.0s%-10p%-10.0d%-10.0i%-10.0u%-10.0x%-10.0X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%-10c%-10.0s%-10p%-10.0d%-10.0i%-10.0u%-10.0x%-10.0X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 74: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-] width > prec
	printf("[-] width > prec\n");
	a = ft_printf("%-10c%-10.2s%-10p%-10.2d%-10.2i%-10.2u%-10.2x%-10.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%-10c%-10.2s%-10p%-10.2d%-10.2i%-10.2u%-10.2x%-10.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 80: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-] width == prec
	printf("[-] width == prec\n");
	a = ft_printf("%-2c%-2.2s%-2p%-2.2d%-2.2i%-2.2u%-2.2x%-2.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%-2c%-2.2s%-2p%-2.2d%-2.2i%-2.2u%-2.2x%-2.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 86: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-] width < prec
	printf("[-] width < prec\n");
	a = ft_printf("%-2c%-2.10s%-2p%-2.10d%-2.10i%-2.10u%-2.10x%-2.10X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%-2c%-2.10s%-2p%-2.10d%-2.10i%-2.10u%-2.10x%-2.10X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 92: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	//[] prec == 0
	printf("[] prec == 0\n");
	a = ft_printf("%10c%10.0s%10p%10.0d%10.0i%10.0u%10.0x%10.0X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%10c%10.0s%10p%10.0d%10.0i%10.0u%10.0x%10.0X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 100: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//[] width > prec
	printf("[] width > prec\n");
	a = ft_printf("%10c%10.2s%10p%10.2d%10.2i%10.2u%10.2x%10.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%10c%10.2s%10p%10.2d%10.2i%10.2u%10.2x%10.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 106: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//[] width == prec
	printf("[] width == prec\n");
	a = ft_printf("%2c%2.2s%2p%2.2d%2.2i%2.2u%2.2x%2.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%2c%2.2s%2p%2.2d%2.2i%2.2u%2.2x%2.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 112: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//[] width < prec
	printf("[] width < prec\n");
	a = ft_printf("%2c%2.10s%2p%2.10d%2.10i%2.10u%2.10x%2.10X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%2c%2.10s%2p%2.10d%2.10i%2.10u%2.10x%2.10X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 118: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	//[0] prec == 0
	printf("[0] prec == 0\n");
	a = ft_printf("%10c%10.0s%10p%010.0d%010.0i%010.0u%010.0x%010.0X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%10c%10.0s%10p%010.0d%010.0i%010.0u%010.0x%010.0X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 126: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//[0] width > prec
	printf("[0] width > prec\n");
	a = ft_printf("%10c%10.2s%10p%010.2d%010.2i%010.2u%010.2x%010.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%10c%10.2s%10p%010.2d%010.2i%010.2u%010.2x%010.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 132: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//[0] width == prec
	printf("[0] width == prec\n");
	a = ft_printf("%2c%02.2s%02p%02.2d%02.2i%02.2u%02.2x%02.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%2c%2.2s%2p%02.2d%02.2i%02.2u%02.2x%02.2X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 138: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//[0] width < prec
	printf("[0] width < prec\n");
	a = ft_printf("%2c%2.10s%2p%02.10d%02.10i%02.10u%02.10x%02.10X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	b = printf("%2c%2.10s%2p%02.10d%02.10i%02.10u%02.10x%02.10X\n", 'a', "hello", NULL, -42, 42, 42069, 123, 123);
	printf("line 144: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	// [*].[*] prec == 0
	printf("[*].[*] prec == 0\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, 0, "hello", 5, NULL, 5, 0, -42, 5, 0, 42, 5, 0, 42069, 5, 0, 123, 5, 0, 123, 5, 0);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, 0, "hello", 5, NULL, 5, 0, -42, 5, 0, 42, 5, 0, 42069, 5, 0, 123, 5, 0, 123, 5, 0);
	printf("line 152: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [*].[*] width == 0
	printf("[*].[*] width == 0\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, 5, "hello", 0, NULL, 0, 5, -42, 0, 5, 42, 0, 5, 42069, 0, 5, 123, 0, 5, 123, 0, 5);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, 5, "hello", 0, NULL, 0, 5, -42, 0, 5, 42, 0, 5, 42069, 0, 5, 123, 0, 5, 123, 0, 5);
	printf("line 158: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [*].[*] width == 0 && prec == 0
	printf("[*].[*] width == 0 && prec == 0\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	printf("line 164: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [*].[*] width == prec
	printf("[*].[*] width == prec\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	printf("line 170: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [*].[*] width > prec
	printf("[*].[*] width > prec\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, 1, "hello", 5, NULL, 5, 1, -42, 5, 1, 42, 5, 1, 42069, 5, 1, 123, 5, 1, 123, 5, 1);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, 1, "hello", 5, NULL, 5, 1, -42, 5, 1, 42, 5, 1, 42069, 5, 1, 123, 5, 1, 123, 5, 1);
	printf("line 176: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [*].[*] width < prec
	printf("[*].[*] width < prec\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 1, 5, "hello", 5, NULL, 1, 5, -42, 1, 5, 42, 1, 5, 42069, 1, 5, 123, 1, 5, 123, 1, 5);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 1, 5, "hello", 5, NULL, 1, 5, -42, 1, 5, 42, 1, 5, 42069, 1, 5, 123, 1, 5, 123, 1, 5);
	printf("line 182: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	// [-][*].[*] prec == 0
	printf("[-][*].[*] prec == 0\n");
	a = ft_printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 5, 0, "hello", 5, NULL, 5, 0, -42, 5, 0, 42, 5, 0, 42069, 5, 0, 123, 5, 0, 123, 5, 0);
	b = printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 5, 0, "hello", 5, NULL, 5, 0, -42, 5, 0, 42, 5, 0, 42069, 5, 0, 123, 5, 0, 123, 5, 0);
	printf("line 190: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-][*].[*] width == 0
	printf("[-][*].[*] width == 0\n");
	a = ft_printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 0, 'a', 0, 5, "hello", 0, NULL, 0, 5, -42, 0, 5, 42, 0, 5, 42069, 0, 5, 123, 0, 5, 123, 0, 5);
	b = printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 0, 'a', 0, 5, "hello", 0, NULL, 0, 5, -42, 0, 5, 42, 0, 5, 42069, 0, 5, 123, 0, 5, 123, 0, 5);
	printf("line 196: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-][*].[*] width == 0 && prec == 0
	printf("[-][*].[*] width == 0 && prec == 0\n");
	a = ft_printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	b = printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	printf("line 202: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-][*].[*] width == prec
	printf("[-][*].[*] width == prec\n");
	a = ft_printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	b = printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	printf("line 208: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-][*].[*] width > prec
	printf("[-][*].[*] width > prec\n");
	a = ft_printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 5, 1, "hello", 5, NULL, 5, 1, -42, 5, 1, 42, 5, 1, 42069, 5, 1, 123, 5, 1, 123, 5, 1);
	b = printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 5, 1, "hello", 5, NULL, 5, 1, -42, 5, 1, 42, 5, 1, 42069, 5, 1, 123, 5, 1, 123, 5, 1);
	printf("line 214: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [-][*].[*] width < prec
	printf("[-][*].[*] width < prec\n");
	a = ft_printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 1, 5, "hello", 5, NULL, 1, 5, -42, 1, 5, 42, 1, 5, 42069, 1, 5, 123, 1, 5, 123, 1, 5);
	b = printf("%-*c%-*.*s%-*p%-*.*d%-*.*i%-*.*u%-*.*x%-*.*X%-*.*%\n", 5, 'a', 1, 5, "hello", 5, NULL, 1, 5, -42, 1, 5, 42, 1, 5, 42069, 1, 5, 123, 1, 5, 123, 1, 5);
	printf("line 220: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	// [0][*].[*] prec == 0
	printf("[0][*].[*] prec == 0\n");
	a = ft_printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 5, 0, "hello", 5, NULL, 5, 0, -42, 5, 0, 42, 5, 0, 42069, 5, 0, 123, 5, 0, 123, 5, 0);
	b = printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 5, 0, "hello", 5, NULL, 5, 0, -42, 5, 0, 42, 5, 0, 42069, 5, 0, 123, 5, 0, 123, 5, 0);
	printf("line 228: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [0][*].[*] width == 0
	printf("[0][*].[*] width == 0\n");
	a = ft_printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 0, 'a', 0, 5, "hello", 0, NULL, 0, 5, -42, 0, 5, 42, 0, 5, 42069, 0, 5, 123, 0, 5, 123, 0, 5);
	b = printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 0, 'a', 0, 5, "hello", 0, NULL, 0, 5, -42, 0, 5, 42, 0, 5, 42069, 0, 5, 123, 0, 5, 123, 0, 5);
	printf("line 234: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [0][*].[*] width == 0 && prec == 0
	printf("[0][*].[*] width == 0 && prec == 0\n");
	a = ft_printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	b = printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	printf("line 240: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [0][*].[*] width == prec
	printf("[0][*].[*] width == prec\n");
	a = ft_printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	b = printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	printf("line 246: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [0][*].[*] width > prec
	printf("[0][*].[*] width > prec\n");
	a = ft_printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 5, 1, "hello", 5, NULL, 5, 1, -42, 5, 1, 42, 5, 1, 42069, 5, 1, 123, 5, 1, 123, 5, 1);
	b = printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 5, 1, "hello", 5, NULL, 5, 1, -42, 5, 1, 42, 5, 1, 42069, 5, 1, 123, 5, 1, 123, 5, 1);
	printf("line 252: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [0][*].[*] width < prec
	printf("[0][*].[*] width < prec\n");
	a = ft_printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 1, 5, "hello", 5, NULL, 1, 5, -42, 1, 5, 42, 1, 5, 42069, 1, 5, 123, 1, 5, 123, 1, 5);
	b = printf("%*c%*.*s%*p%0*.*d%0*.*i%0*.*u%0*.*x%0*.*X%0*.*%\n", 5, 'a', 1, 5, "hello", 5, NULL, 1, 5, -42, 1, 5, 42, 1, 5, 42069, 1, 5, 123, 1, 5, 123, 1, 5);
	printf("line 258: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	// [][*].[*] prec == 0 && width negative
	printf("[][*].[*] prec == 0 && width negative\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", -5, 'a', -5, 0, "hello", -5, NULL, -5, 0, -42, -5, 0, 42, -5, 0, 42069, -5, 0, 123, -5, 0, 123, -5, 0);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", -5, 'a', -5, 0, "hello", -5, NULL, -5, 0, -42, -5, 0, 42, -5, 0, 42069, -5, 0, 123, -5, 0, 123, -5, 0);
	printf("line 266: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width == 0 && prec negative
	printf("[][*].[*] width == 0 && prec negative\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, -5, "hello", 0, NULL, 0, -5, -42, 0, -5, 42, 0, -5, 42069, 0, -5, 123, 0, -5, 123, 0, -5);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, -5, "hello", 0, NULL, 0, -5, -42, 0, -5, 42, 0, -5, 42069, 0, -5, 123, 0, -5, 123, 0, -5);
	printf("line 272: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width == 0 && prec == 0
	printf("[][*].[*] width == 0 && prec == 0\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 0, 'a', 0, 0, "hello", 0, NULL, 0, 0, -42, 0, 0, 42, 0, 0, 42069, 0, 0, 123, 0, 0, 123, 0, 0);
	printf("line 278: %d|%d\n\n", a, b);

	// [][*].[*] width == prec && both negative
	printf("[][*].[*] width == prec && both negative\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", -5, 'a', -5, -5, "hello", -5, NULL, -5, -5, -42, -5, -5, 42, -5, -5, 42069, -5, -5, 123, -5, -5, 123, -5, -5);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", -5, 'a', -5, -5, "hello", -5, NULL, -5, -5, -42, -5, -5, 42, -5, -5, 42069, -5, -5, 123, -5, -5, 123, -5, -5);
	printf("line 284: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width > prec && prec negative
	printf("[][*].[*] width > prec && prec negative\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, -1, "hello", 5, NULL, 5, -1, -42, 5, -1, 42, 5, -1, 42069, 5, -1, 123, 5, -1, 123, 5, -1);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", 5, 'a', 5, -1, "hello", 5, NULL, 5, -1, -42, 5, -1, 42, 5, -1, 42069, 5, -1, 123, 5, -1, 123, 5, -1);
	printf("line 290: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width < prec && width negative
	printf("[][*].[*] width < prec && width negative\n");
	a = ft_printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", -5, 'a', 1, -5, "hello", -5, NULL, -5, 1, -42, -5, 1, 42, -5, 1, 42069, -5, 1, 123, -5, 1, 123, -5, 1);
	b = printf("%*c%*.*s%*p%*.*d%*.*i%*.*u%*.*x%*.*X%*.*%\n", -5, 'a', 1, -5, "hello", -5, NULL, -5, 1, -42, -5, 1, 42, -5, 1, 42069, -5, 1, 123, -5, 1, 123, -5, 1);
	printf("line 296: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	printf("POSITIVE []\n");
	// [][*].[*] width == 0 && prec == 0
	printf("[][*].[*] width == 0 && prec == 0\n");
	a = ft_printf("%*.*%|\n", 0, 0);
	b = printf("%*.*%|\n", 0, 0);
	printf("line 305: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width > prec && prec == 0
	printf("[][*].[*] width > prec && prec == 0\n");
	a = ft_printf("%*.*%|\n", 5, 0);
	b = printf("%*.*%|\n", 5, 0);
	printf("line 311: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width > prec && width == 0
	printf("[][*].[*] width < prec && width == 0\n");
	a = ft_printf("%*.*%|\n", 0, 5);
	b = printf("%*.*%|\n", 0, 5);
	printf("line 317: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width == prec
	printf("[][*].[*] width == prec\n");
	a = ft_printf("%*.*%|\n", 5, 5);
	b = printf("%*.*%|\n", 5, 5);
	printf("line 323: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width > prec
	printf("[][*].[*] width > prec\n");
	a = ft_printf("%*.*%|\n", 5, 1);
	b = printf("%*.*%|\n", 5, 1);
	printf("line 329: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width < prec
	printf("[][*].[*] width < prec\n");
	a = ft_printf("%*.*%|\n", 1, 5);
	b = printf("%*.*%|\n", 1, 5);
	printf("line 335: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");


	printf("NEGATIVE []\n");
	// [][*].[*] width == 0 && prec == 0
	printf("[][*].[*] width == 0 && prec == 0\n");
	a = ft_printf("%-*.*%|\n", 0, 0);
	b = printf("%-*.*%|\n", 0, 0);
	printf("line 343: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width negative && prec == 0
	printf("[][*].[*] width negative && prec == 0\n");
	a = ft_printf("%*.*%|\n", -5, 0);
	b = printf("%*.*%|\n", -5, 0);
	printf("line 349: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [][*].[*] width == 0 && prec negative
	printf("[][*].[*] width == 0 && prec negative\n");
	a = ft_printf("%*.*%|\n", 0, -5);
	b = printf("%*.*%|\n", 0, -5);
	printf("line 355: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("4\n");
	a = ft_printf("%*.*%|\n", -5, -5);
	b = printf("%*.*%|\n", -5, -5);
	printf("line 360: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("5\n");
	a = ft_printf("%*.*%|\n", -5, 1);
	b = printf("%*.*%|\n", -5, 1);
	printf("line 365: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("6\n");
	a = ft_printf("%*.*%|\n", 1, -5);
	b = printf("%*.*%|\n", 1, -5);
	printf("line 370: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("7\n");
	a = ft_printf("%*.*%|\n", 5, -1);
	b = printf("%*.*%|\n", 5, -1);
	printf("line 375: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("8\n");
	a = ft_printf("%*.*%|\n", -1, 5);
	b = printf("%*.*%|\n", -1, 5);
	printf("line 380: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	printf("POSITIVE [0]\n");
	printf("1\n");
	a = ft_printf("%0*.*%|\n", 0, 0);
	b = printf("%0*.*%|\n", 0, 0);
	printf("line 388: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("2\n");
	a = ft_printf("%0*.*%|\n", 5, 0);
	b = printf("%0*.*%|\n", 5, 0);
	printf("line 393: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("3\n");
	a = ft_printf("%0*.*%|\n", 0, 5);
	b = printf("%0*.*%|\n", 0, 5);
	printf("line 398: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("4\n");
	a = ft_printf("%0*.*%|\n", 5, 5);
	b = printf("%0*.*%|\n", 5, 5);
	printf("line 403: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("5\n");
	a = ft_printf("%0*.*%|\n", 5, 1);
	b = printf("%0*.*%|\n", 5, 1);
	printf("line 408: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("6\n");
	a = ft_printf("%0*.*%|\n", 1, 5);
	b = printf("%0*.*%|\n", 1, 5);
	printf("line 413: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("NEGATIVE [0]\n");
	printf("1\n");
	a = ft_printf("%-*.*%|\n", 0, 0);
	b = printf("%-*.*%|\n", 0, 0);
	printf("line 419: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("2\n");
	a = ft_printf("%0*.*%|\n", -5, 0);
	b = printf("%0*.*%|\n", -5, 0);
	printf("line 424: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("3\n");
	a = ft_printf("%0*.*%|\n", 0, -5);
	b = printf("%0*.*%|\n", 0, -5);
	printf("line 429: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("4\n");
	a = ft_printf("%0*.*%|\n", -5, -5);
	b = printf("%0*.*%|\n", -5, -5);
	printf("line 434: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("5\n");
	a = ft_printf("%0*.*%|\n", -5, 1);
	b = printf("%0*.*%|\n", -5, 1);
	printf("line 439: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("6\n");
	a = ft_printf("%0*.*%|\n", 1, -5);
	b = printf("%0*.*%|\n", 1, -5);
	printf("line 444: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("7\n");
	a = ft_printf("%0*.*%|\n", 5, -1);
	b = printf("%0*.*%|\n", 5, -1);
	printf("line 449: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("8\n");
	a = ft_printf("%0*.*%|\n", -1, 5);
	b = printf("%0*.*%|\n", -1, 5);
	printf("line 454: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	printf("POSITIVE [-]\n");
	printf("1\n");
	a = ft_printf("%-*.*%|\n", 0, 0);
	b = printf("%-*.*%|\n", 0, 0);
	printf("line 462: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("2\n");
	a = ft_printf("%-*.*%|\n", 5, 0);
	b = printf("%-*.*%|\n", 5, 0);
	printf("line 467: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("3\n");
	a = ft_printf("%-*.*%|\n", 0, 5);
	b = printf("%-*.*%|\n", 0, 5);
	printf("line 472: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("4\n");
	a = ft_printf("%-*.*%|\n", 5, 5);
	b = printf("%-*.*%|\n", 5, 5);
	printf("line 477: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("5\n");
	a = ft_printf("%-*.*%|\n", 5, 1);
	b = printf("%-*.*%|\n", 5, 1);
	printf("line 482: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("6\n");
	a = ft_printf("%-*.*%|\n", 1, 5);
	b = printf("%-*.*%|\n", 1, 5);
	printf("line 487: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("NEGATIVE [-]\n");
	printf("1\n");
	a = ft_printf("%-*.*%|\n", 0, 0);
	b = printf("%-*.*%|\n", 0, 0);
	printf("line 493: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("2\n");
	a = ft_printf("%-*.*%|\n", -5, 0);
	b = printf("%-*.*%|\n", -5, 0);
	printf("line 498: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("3\n");
	a = ft_printf("%-*.*%|\n", 0, -5);
	b = printf("%-*.*%|\n", 0, -5);
	printf("line 503: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("4\n");
	a = ft_printf("%-*.*%|\n", -5, -5);
	b = printf("%-*.*%|\n", -5, -5);
	printf("line 508: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("5\n");
	a = ft_printf("%-*.*%|\n", -5, 1);
	b = printf("%-*.*%|\n", -5, 1);
	printf("line 513: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("6\n");
	a = ft_printf("%-*.*%|\n", 1, -5);
	b = printf("%-*.*%|\n", 1, -5);
	printf("line 518: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("7\n");
	a = ft_printf("%-*.*%|\n", 5, -1);
	b = printf("%-*.*%|\n", 5, -1);
	printf("line 523: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	printf("8\n");
	a = ft_printf("%-*.*%|\n", -1, 5);
	b = printf("%-*.*%|\n", -1, 5);
	printf("line 528: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	//-------------------------------------------------------------------------

	// [--] multiple flags
	printf("[--][*].[*] width == prec\n");
	a = ft_printf("%--*c%--*.*s%--*p%--*.*d%--*.*i%--*.*u%--*.*x%--*.*X%--*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	b = printf("%--*c%--*.*s%--*p%--*.*d%--*.*i%--*.*u%--*.*x%--*.*X%--*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	printf("line 536: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	// [00] multiple flags
	printf("[00][*].[*] width == prec\n");
	a = ft_printf("%*c%*.*s%*p%00*.*d%00*.*i%00*.*u%00*.*x%00*.*X%00*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	b = printf("%*c%*.*s%*p%00*.*d%00*.*i%00*.*u%00*.*x%00*.*X%00*.*%\n", 5, 'a', 5, 5, "hello", 5, NULL, 5, 5, -42, 5, 5, 42, 5, 5, 42069, 5, 5, 123, 5, 5, 123, 5, 5);
	printf("line 542: %d|%d    %s\n\n", a, b, (a == b) ? "TRUE" : "FALSE");

	system("leaks a.out");
	return (0);
}

/*
int		main(void)
{
	printf("hello");
	int t;
	char c;
	int		nb;
	nb = -45;
	char	*str;
	str = "";

	c = 'a';
	t = 50;
	
	ft_printf("p0 %.3s\n", "cccc");
	ft_printf("pp %.50d\n", 10000);
	ft_printf("p1 %.4s\n", "cccc");
	printf("p2 %.10s\n", "cccc");
	printf("p3 %.4s\n", NULL);
	printf("p4 %.5s\n", "aaaaa");
	printf("p5 %.3d\n", 100);
	printf("p6 %.0d\n", 100);
	printf("p7 %.4d\n", 100);
	printf("p8 %.10d\n", 100);
	printf("p9 %.50d\n", 100);
	ft_printf("p10 %.1d\n", 100);
	ft_printf("p11 %.3d\n", 100);
	printf("p12 %.0d\n", 0);
	ft_printf("p13 %.3i\n", 100);
	ft_printf("p14 %.0i\n", 100);
	ft_printf("p15 %.4i\n", 100);
	ft_printf("p16 %.10i\n", 100);
	ft_printf("p17 %.50i\n", 100);
	ft_printf("p18 %.1i\n", 100);
	ft_printf("p19 %.3x\n", 100);
	ft_printf("st119 %*s\n", 1000, "hello");

	ft_printf( "%c ", c);
	ft_printf( "%1c ", c);
	ft_printf( "%7c ", c);
	ft_printf( "%-1c ", c);
	ft_printf( "%-5c ", c);
	ft_printf("%c", c);
	ft_printf("%12c", c);
	ft_printf("%-1c", c);
	ft_printf("%1c", c);
	ft_printf("%5c", c);
	ft_printf("%-5c", c);
	ft_printf(" %c\n", 0);
	ft_printf("%c\n", 0);
	ft_printf("%%\n");
	ft_printf("%%%%%d\n", -120);

	ft_printf("space% d\n", nb);
	ft_printf("plus:%+d\n", nb);
	ft_printf("precision:%.5d\n", nb);
	ft_printf("space + prec:% .5d\n", nb);
	ft_printf("Plus + prec / grande:%+.5d\n", nb);
	ft_printf("Plus + prec / petite:%+.0d\n", nb);
	ft_printf("Prec + 0:%0.5d\n", nb);
	ft_printf("Prec + minus:%-.5d\n", nb);
	ft_printf("size:%5d\n", nb);
	ft_printf("size + space:% 5d\n", nb);
	ft_printf("size + plus:%+5d\n", nb);
	ft_printf("size + minus:%-5d\n", nb);
	ft_printf("size + 0:%05d\n", nb);
	ft_printf("size + 0 + plus:%+05d\n", nb);
	ft_printf("size + 0 + plus:%0+5d\n", nb);
	ft_printf("size + 0 + prec:%05.3d\n", nb);
	ft_printf("size + minus + prec:%-5.3d\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3d\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3d\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3d\n", nb);

ft_printf("space%i\n", nb);
	ft_printf("plus:%i\n", nb);
	ft_printf("precision:%.5i\n", nb);
	ft_printf("space + prec:%.5i\n", nb);
	ft_printf("Plus + prec / grande:%.5i\n", nb);
	ft_printf("Plus + prec / petite:%.0i\n", nb);
	ft_printf("Prec + 0:%0.5i\n", nb);
	ft_printf("Prec + minus:%-.5i\n", nb);
	ft_printf("size:%5i\n", nb);
	ft_printf("size + space:%5i\n", nb);
	ft_printf("size + plus:%5i\n", nb);
	ft_printf("size + minus:%-5i\n", nb);
	ft_printf("size + 0:%05i\n", nb);
	ft_printf("size + 0 + plus:%05i\n", nb);
	ft_printf("size + 0 + plus:%05i\n", nb);
	ft_printf("size + 0 + prec:%05.3i\n", nb);
	ft_printf("size + minus + prec:%-5.3i\n", nb);
	ft_printf("size + plus + 0 + prec:%5.3i\n", nb);
	ft_printf("size + espace + zero + prec:%5.3i\n", nb);
	ft_printf("size + espace + zero + prec:%05.3i\n", nb);

	ft_printf("test basique:%s", str);
	ft_printf("precision / zero:%.0s", str);
	ft_printf("precision / petite:%.5s", str);
	ft_printf("precision / grande:%.15s", str);
	ft_printf("prec + minus:%-.5s", str);
	ft_printf("size / petite:%5s", str);
	ft_printf("size / grande:%15s", str);
	ft_printf("Minus + size / petite:%-5s", str);
	ft_printf("Minus + size / grande:%-15s", str);
	ft_printf("Minus + size + prec:%-15.5s", str);
	ft_printf("NULL:%12s", NULL);
	ft_printf("NULL:%1s", NULL);
	ft_printf("NULL:%-5.6s", NULL);
	ft_printf("NULL:%-.8s", NULL);
	ft_printf("NULL:%.12s", NULL);
	ft_printf("empty:%-.5s", "");
	ft_printf("empty:%-1.32s", "");
	ft_printf("empty:%1.4s", "");
	ft_printf("empty:%23s", "");
		ft_printf("test basique:%s", str);
	ft_printf("precision / zero:%.0s", str);
	ft_printf("precision / petite:%.5s", str);
	ft_printf("precision / grande:%.15s", str);
	ft_printf("prec + minus:%-.5s", str);
	ft_printf("size / petite:%5s", str);
	ft_printf("size / grande:%15s", str);
	ft_printf("Minus + size / petite:%-5s", str);
	ft_printf("Minus + size / grande:%-15s", str);
	ft_printf("Minus + size + prec:%-15.5s", str);
	ft_printf("NULL:%12s", NULL);
	ft_printf("NULL:%1s", NULL);
	ft_printf("NULL:%-5.6s", NULL);
	ft_printf("NULL:%-.8s", NULL);
	ft_printf("NULL:%.12s", NULL);
	ft_printf("empty:%-.5s", "");
	ft_printf("empty:%-1.32s", "");
	ft_printf("empty:%1.4s", "");
	ft_printf("empty:%23s", "");
	ft_printf("test basique:%s", str);
	ft_printf("precision / zero:%.0s", str);
	ft_printf("precision / petite:%.5s", str);
	ft_printf("precision / grande:%.15s", str);
	ft_printf("prec + minus:%-.5s", str);
	ft_printf("size / petite:%5s", str);
	ft_printf("size / grande:%15s", str);
	ft_printf("Minus + size / petite:%-5s", str);
	ft_printf("Minus + size / grande:%-15s", str);
	ft_printf("Minus + size + prec:%-15.5s", str);
	ft_printf("NULL:%12s", NULL);
	ft_printf("NULL:%1s", NULL);
	ft_printf("NULL:%-5.6s", NULL);
	ft_printf("NULL:%-.8s", NULL);
	ft_printf("NULL:%.12s", NULL);
	ft_printf("empty:%-.5s", "");
	ft_printf("empty:%-1.32s", "");
	ft_printf("empty:%1.4s", "");
	ft_printf("empty:%23s", "");

ft_printf("precision:%.5u\n", nb);
	ft_printf("Prec + 0:%0.5u\n", nb);
	ft_printf("Prec + minus:%-.5u\n", nb);
	ft_printf("size:%5u\n", nb);
	ft_printf("size + minus:%-5u\n", nb);
	ft_printf("size + 0:%05u\n", nb);
	ft_printf("size + 0 + prec:%05.3u\n", nb);
	ft_printf("size + minus + prec:%-5.3u\n", nb);
	ft_printf("%-5.3u\n", nb);
	ft_printf("%-1.45u\n", nb);
	ft_printf("%-55.35u\n", nb);
		ft_printf("precision:%.5u\n", nb);
	ft_printf("Prec + 0:%0.5u\n", nb);
	ft_printf("Prec + minus:%-.5u\n", nb);
	ft_printf("size:%5u\n", nb);
	ft_printf("size + minus:%-5u\n", nb);
	ft_printf("size + 0:%05u\n", nb);
	ft_printf("size + 0 + prec:%05.3u\n", nb);
	ft_printf("size + minus + prec:%-5.3u\n", nb);
	ft_printf("%-5.3u\n", nb);
	ft_printf("%050.u\n", nb);
	ft_printf("%-1.45u\n", nb);
	ft_printf("%-55.35u\n", nb);
ft_printf("%5p\n", &nb);
	ft_printf("%-15p\n", &nb);
	ft_printf("%-5p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%-18p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%5p\n", &c);
	ft_printf("%-15p\n", &c);
	ft_printf("%-5p\n", &c);
	ft_printf("%42p\n", &c);
	ft_printf("%-18p\n", &c);
	ft_printf("%42p\n", &c);
	ft_printf("%x", nb);
	ft_printf("test X:%X", nb);
	ft_printf("Hash:%#X", nb);
	ft_printf("prec / grande:%.5X", nb);
	ft_printf("prec / petite:%.0X", nb);
	ft_printf("hash + prec / grande:%#.5X", nb);
	ft_printf("hash + prec / petite:%#.1X", nb);
	ft_printf("prec + 0: %0.5X", nb);
	ft_printf("Prec + minus:%-.5X", nb);
	ft_printf("size:%5X", nb);
	ft_printf("size + prec:%7.3X", nb);
	ft_printf("size + mminus:%-5X", nb);
	ft_printf("size + 0:%05X", nb);
	ft_printf("size + 0 + hash:%#05X", nb);
	ft_printf("size + 0 + prec:%05.3X", nb);
	ft_printf("size + minus + prec:%-5.3X", nb);
	ft_printf("size + hash + 0 + prec:%#05.3X", nb);
	ft_printf("size + hash + 0 + prec:%0#5.3X", nb);
	ft_printf("size + hash + minus + prec:%-#7.3X", nb);
	ft_printf("%x", nb);
	ft_printf("test X:%X", nb);
	ft_printf("Hash:%#X", nb);
	ft_printf("prec / grande:%.5X", nb);
	ft_printf("hash + prec / grande:%#.5X", nb);
	ft_printf("hash + prec / petite:%#.1X", nb);
	ft_printf("prec + 0: %0.5X", nb);
	ft_printf("Prec + minus:%-.5X", nb);
	ft_printf("size:%5X", nb);
	ft_printf("size + prec:%7.3X", nb);
	ft_printf("size + minus:%-5X", nb);
	ft_printf("size + 0:%05X", nb);
	ft_printf("size + 0 + hash:%#05X", nb);
	ft_printf("size + 0 + prec:%05.3X", nb);
	ft_printf("size + minus + prec:%-5.3X", nb);
	ft_printf("size + hash + 0 + prec:%#05.3X", nb);
	ft_printf("size + hash + 0 + prec:%0#5.3X", nb);
	ft_printf("size + hash + minus + prec:%-#7.3X", nb);

	system("leaks a.out");
	return (0);
}
*/
