

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
