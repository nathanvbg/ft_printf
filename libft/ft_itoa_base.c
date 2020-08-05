/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:55:48 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/31 17:55:58 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_n(unsigned long long n, int base_size)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base_size;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long long n, char *base, int base_size)
{
	char	*str;
	int		i;

	i = ft_count_n(n, base_size);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = base[n % base_size];
		n = n / base_size;
	}
	return (str);
}
