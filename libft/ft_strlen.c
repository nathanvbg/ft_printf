/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:28:39 by nverbrug          #+#    #+#             */
/*   Updated: 2020/03/04 16:10:22 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t compteur;

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
