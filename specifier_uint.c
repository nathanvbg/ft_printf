

#include "ft_printf.h"

void	specifier_uint(va_list arg, int *p, int *i, t_flag *flag)
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
		ft_free(&x);
	len = ft_strlen(x);
	tri_flags(p, i, flag, x, len);
}

void	specifier_x(va_list arg, int *p, int *i, t_flag *flag)
{
	char			*x;
	unsigned int	nb;//unsigned int?
	int				len;

	nb = va_arg(arg, unsigned int);
	if (!(x = ft_itoa_base(nb, "0123456789abcdef", 16)))
		ft_free(&x);
	len = ft_strlen(x);
	tri_flags(p, i, flag, x, len);
}

void	specifier_hex(va_list arg, int *p, int *i, t_flag *flag)
{
	char			*x;
	unsigned int	nb;//unsigned int?
	int				len;

	nb = va_arg(arg, unsigned int);
	if (!(x = ft_itoa_base(nb, "0123456789ABCDEF", 16)))
		ft_free(&x);
	len = ft_strlen(x);
	tri_flags(p, i, flag, x, len);
}

void	specifier_pointer(va_list arg, int *p, int *i, t_flag *flag)
{
	char	*x;
	size_t	nb;//unsigned int?
	int		len;

	nb = va_arg(arg, size_t);
	if (!(x = ft_itoa_base(nb, "0123456789abcdef", 18)))
		ft_free(&x);
	len = ft_strlen(x);
	//if ((flag->n1 > len) && (flag->n1 > flag->n2)) 
	//else
	//{
		ft_putchar('0', p);
		ft_putchar('x', p);
		tri_flags(p, i, flag, x, len);
	//}
}
