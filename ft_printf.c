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

void		ft_putstr(char *str, int *printed)
{
	while (*str)
	{
		ft_putchar(*str, printed);
		str++;
	}
}

int			ft_print_parced(const char *str, int *printed, va_list ap)
{
	if (*str == '%')
	{
		ft_putchar('%', printed);
	}
	if (*str == 'c')
	{
		ft_putchar(va_arg(ap, int), printed);
	}
	if (*str == 's')
	{
		ft_putstr(va_arg(ap, char *), printed);
	}
	return (2);
}


int			ft_printf(const char *form, ...)
{
	int		printed;

	va_list ap;
	va_start(ap, form);
	printed = 0;
	while (*form)
	{
		if (*form == '%' && *(form + 1))
		{
			form += ft_print_parced(form + 1, &printed, ap);
		}
		else
		{
			ft_putchar(*form, &printed);
			form++;
		}
	}
	va_end(ap);
	return (printed);
}
