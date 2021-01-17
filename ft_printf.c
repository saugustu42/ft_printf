#include "ft_printf.h"

void		ft_putchar(int *printed, char c)
{
	*printed += write(1, &c, 1);
}

int			ft_printf(const char *format, ...)
{
	int printed;

	printed = 0;
	while (*format)
		ft_putchar(&printed, *format++);
	return (printed);
}
