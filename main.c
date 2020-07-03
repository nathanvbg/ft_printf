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

#include "ft_printf.h"

int		main(void)
{
	ft_printf("p = %d\n", ft_printf("-->|%04.0%|<--\n"));
	printf("p = %d\n", printf("-->|%04.0%|<--\n"));
	return (0);
}
