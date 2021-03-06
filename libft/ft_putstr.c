/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:07:28 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 16:09:52 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int *p, int nb)
{
	int i;

	i = 0;
	if (str == NULL && nb == 0)
	{
		write(1, "(null)", 6);
		*p += 6;
	}
	else
	{
		if (str == NULL && nb != 0)
			str = "(null)";
		while (str[i] != '\0' && i < nb)
		{
			ft_putchar(str[i], p);
			i++;
		}
	}
}
