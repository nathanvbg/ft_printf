
#include "ft_printf.h"

int		specifier_u(va_list arg, int *p, int *i, t_flag *flag)
{
	char			*x;
	unsigned int	nb;
	int				len;

	nb = va_arg(arg, unsigned int);
	if (nb < 0)
	{
		flag->neg = 1;
		nb = -nb;
	}
	if (!(x = ft_itoa_base(nb, "0123456789", 10)))
		ft_free(&x, -1);
	len = ft_strlen(x);
	int_tri_flags(p, i, flag, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_x(va_list arg, int *p, int *i, t_flag *flag)
{
	char			*x;
	unsigned int	nb;//unsigned int?
	int				len;

	nb = va_arg(arg, unsigned int);
	if (!(x = ft_itoa_base(nb, "0123456789abcdef", 16)))
		ft_free(&x, -1);
	len = ft_strlen(x);
	int_tri_flags(p, i, flag, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_X(va_list arg, int *p, int *i, t_flag *flag)
{
	char			*x;
	unsigned int	nb;//unsigned int?
	int				len;

	nb = va_arg(arg, unsigned int);
	if (!(x = ft_itoa_base(nb, "0123456789ABCDEF", 16)))
		ft_free(&x, -1);
	len = ft_strlen(x);
	int_tri_flags(p, i, flag, x, len);
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_p(va_list arg, int *p, int *i, t_flag *flag)
{
	char				*x;
	unsigned long long	nb;

	nb = va_arg(arg, unsigned long long);
	if (nb == 0 && flag->point == 1)
		x = "";
	else
	{
		if ((x = ft_itoa_base(nb, "0123456789abcdef", 16)) == NULL)
			ft_free(&x, -1);
	}
	if (flag->minus == 0)
		print_only_c(p, (flag->n1 - ft_strlen(x) - 2), ' ');
	ft_putchar('0', p);
	ft_putchar('x', p);
	print_only_c(p, (flag->n2 - ft_strlen(x)), '0');
	ft_putstr(x, p, ft_strlen(x));
	if (flag->minus == 1)
		print_only_c(p, (flag->n1 - ft_strlen(x) - 2), ' ');
	*i += 1;
	return (ft_strncmp(x, "", 1) != 0 ? ft_free(&x, 0) : 0);
}

int		specifier_perc(int *p, int *i, t_flag *flag)
{
	if (flag->zero == 1)
		print_only_c(p, (flag->n1 - 1), '0');
	else if (flag->zero == 1 && flag->zero_perc == 1)
		print_only_c(p, (flag->n1 - 1), ' ');
	if (flag->zero == 0 && flag->minus == 0)
		print_only_c(p, (flag->n1 - 1), ' ');
	ft_putchar('%', p);
	if (flag->zero == 0 && flag->minus == 1)
		print_only_c(p, (flag->n1 - 1), ' ');
	*i += 1;
	return (0);
}