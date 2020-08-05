/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:55:03 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/31 17:55:19 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int nb)
{
	int compteur;

	compteur = 0;
	if (nb < 0)
	{
		compteur++;
		nb = nb * -1;
	}
	if (nb == 0)
		return (1);
	while (nb > 10)
	{
		nb = nb / 10;
		compteur++;
	}
	if (nb >= 1 && nb <= 9)
		compteur++;
	return (compteur);
}
