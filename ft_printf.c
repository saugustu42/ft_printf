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

void		ft_print_parsed(const char *str, int *printed, va_list ap)
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
}

int			ft_save_num(va_list ap, char **form)
{
	int		num;

	num = 0;
	if (**form == '*')
	{
		num = va_arg(ap, int);
		(*form)++;
	}
	while (ft_isdigit(**form))
	{
		num = num * 10 + **form - '0';
		(*form)++;
	}
	return (num);
}

void		ft_set_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = -1;
}



void		ft_parser(char **form, int *printed, va_list ap)
{
	t_flags flags;
	
	ft_set_flags(&flags);
	while (**form == '-' || **form == '0')
	{
		if (**form == '-')
			flags.minus = 1;
		if (**form == '0')
			flags.zero = 1;
	}
	flags.width = ft_save_num(ap, form);
	if (flags.width < 0)
	{
		flags.zero = 1;
		flags.width *= -1;
	}
	if (flags.minus)
		flags.zero = 0;
	if (**form == '.')
		flags.dot = ft_save_num(ap, form);
	ft_print_parsed(*form, printed, ap);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_printf(const char *form, ...)
{
	int		printed;

	char *tmp;
	va_list ap;

	tmp = (char *)form;
	va_start(ap, form);
	printed = 0;
	while (*tmp)
	{
		if (*tmp == '%' && *(tmp + 1))
		{
//			ft_parser(&((char *)(tmp + 1)), &printed, ap);
			tmp++;
			ft_parser(&(tmp), &printed, ap);
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
