#include "ft_printf.h"

void		ft_putchar(char c, int *printed)
{
	*printed += write(1, &c, 1);
}

void		ft_putnbr(int n, int *printed)
{
	if (n / 10)
		ft_putnbr(n / 10, printed);
	ft_putchar(n % 10 + '0', printed);
}

int			ft_printf(const char *form, ...)
{
	int		printed;
	int 	num_args;

	va_list list;
	va_start(list, form);
	printed = 0;
	num_args = 0;
	while (*form)
	{
		if (*form == '%' && *(form + 1) == '%')
		{
			ft_putchar('%', &printed);
			form++;
		}
		else if (*form == '%' && *(form + 1) != '%')
		{
			num_args++;
			ft_putnbr(num_args, &printed);
			form++;
		}
		else
			ft_putchar(*form, &printed);
		form++;
	}
	va_end(list);
	return (printed);
}
