
#include "ft_printf.h"

int		specifier_u(va_list arg, t_index *idx)
{
	char			*x;
	unsigned int	nb;
	int				len;

	nb = va_arg(arg, unsigned int);
	if (nb < 0)
	{
		idx->neg = 1;
		nb = -nb;
	}
	if (!(x = ft_itoa_base(nb, "0123456789", 10)))
		ft_free(&x, -1);
	len = ft_strlen(x);
	int_tri_flags(idx, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_x(va_list arg, t_index *idx)
{
	char			*x;
	unsigned int	nb;//unsigned int?
	int				len;

	nb = va_arg(arg, unsigned int);
	if (!(x = ft_itoa_base(nb, "0123456789abcdef", 16)))
		ft_free(&x, -1);
	len = ft_strlen(x);
	int_tri_flags(idx, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_X(va_list arg, t_index *idx)
{
	char			*x;
	unsigned int	nb;//unsigned int?
	int				len;

	nb = va_arg(arg, unsigned int);
	if (!(x = ft_itoa_base(nb, "0123456789ABCDEF", 16)))
		ft_free(&x, -1);
	len = ft_strlen(x);
	int_tri_flags(idx, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_p(va_list arg, t_index *idx)
{
	char				*x;
	unsigned long long	nb;

	nb = va_arg(arg, unsigned long long);
	if (nb == 0 && idx->point == 1)
		x = "";
	else
	{
		if ((x = ft_itoa_base(nb, "0123456789abcdef", 16)) == NULL)
			ft_free(&x, -1);
	}
	if (idx->minus == 0)
		print_only_c(idx, (idx->n1 - ft_strlen(x) - 2), ' ');
	ft_putchar('0', &idx->p);
	ft_putchar('x', &idx->p);
	print_only_c(idx, (idx->n2 - ft_strlen(x)), '0');
	ft_putstr(x, &idx->p, ft_strlen(x));
	if (idx->minus == 1)
		print_only_c(idx, (idx->n1 - ft_strlen(x) - 2), ' ');
	idx->i += 1;
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_perc(t_index *idx)
{
	if (idx->zero == 1)
		print_only_c(idx, (idx->n1 - 1), '0');
	else if (idx->zero == 1 && idx->zero_perc == 1)
		print_only_c(idx, (idx->n1 - 1), ' ');
	if (idx->zero == 0 && idx->minus == 0)
		print_only_c(idx, (idx->n1 - 1), ' ');
	ft_putchar('%', &idx->p);
	if (idx->zero == 0 && idx->minus == 1)
		print_only_c(idx, (idx->n1 - 1), ' ');
	idx->i += 1;
	return (0);
}
