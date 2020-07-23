/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:28:39 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/23 19:30:20 by nathanvbg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(const char *str)
{
	int compteur;

	compteur = 0;
	if (str == NULL)
		return (6);
	else
	{
		while (str[compteur])
			compteur++;
	}
	return (compteur);
}
