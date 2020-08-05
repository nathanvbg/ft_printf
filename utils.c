/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:42:23 by nverbrug          #+#    #+#             */
/*   Updated: 2020/07/31 17:42:29 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c_no_point(int nb, char *x, char c, t_index *idx)
{
	if (idx->minus == 0)
		print_only_c(idx, (nb - ft_strlen(x)), c);
	ft_putstr(x, &idx->p, ft_strlen(x));
	if (idx->minus == 1)
		print_only_c(idx, (nb - ft_strlen(x)), c);
}

void	print_space_point(int nb, char *x, t_index *idx)
{
	if (idx->n2 > ft_strlen(x) || idx->n2 < 0)
		idx->n2 = ft_strlen(x);
	if (idx->minus == 0)
		print_only_c(idx, (nb - idx->n2), ' ');
	ft_putstr(x, &idx->p, idx->n2);
	if (idx->minus == 1)
		print_only_c(idx, (nb - idx->n2), ' ');
}

void	print_only_c(t_index *idx, int nb, char c)
{
	if (nb > 0)
	{
		while (nb > 0)
		{
			ft_putchar(c, &idx->p);
			nb -= 1;
		}
	}
}

int		ft_free(char **str, int i)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (i);
}
