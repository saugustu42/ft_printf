#include "ft_printf.h"
#include <stdlib.h>

static int	ch_count(unsigned long n, int base)
{
	int		counter;

	counter = 0;
	while (n)
	{
		n = n / base;
		counter++;
	}
	return (counter);
}

char		*ft_conv_pos(unsigned long n, int base)
{
	char	*str;
	int		char_count;

/*
	if (n == 0)
		return (ft_strdup("0"));
*/
	char_count = ch_count(n, base);
	str = malloc(sizeof(char) * (char_count + 1));
	if (str == NULL)
		return (NULL);
	str[char_count] = '\0';
	while (char_count && n)
	{
		if (n % base < 10)
			str[char_count - 1] = n % base + '0';
		else
			str[char_count - 1] = n % base + 'a' - 10;
		n = n / base;
		char_count--;
	}
	return (str);
}

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

int			ft_print_u(int num, int *printed)
{
	char	*str;

	str = ft_conv_pos(num, 10);
	if (!str)
		return (0);
	ft_putstr(str, printed);
	free(str);
	return (1);
}



int			ft_print_hex(unsigned long num, int *printed, char c)
{
	char	*str;
	int		i;

	str = ft_conv_pos(num, 16);
	if (!str)
		return (0);
	if (c == 'X')
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= ' ';
			i++;
		}
	}
	ft_putstr(str, printed);
	free(str);
	return (1);
}


int			ft_print_parsed(const char *str, int *printed, va_list ap)
{
	if (*str == '%')
		ft_putchar('%', printed);
	if (*str == 'c')
		ft_putchar(va_arg(ap, int), printed);
	if (*str == 's')
		ft_putstr(va_arg(ap, char *), printed);
	if (*str == 'u')
	{
		if (!(ft_print_u(va_arg(ap, int), printed)))
			return (0);
	}
	if (*str == 'x' || *str == 'X')
	{
		if (!(ft_print_hex(va_arg(ap, int), printed, *str)))
			return (0);
	}
	if (*str == 'p')
	{
		if (!(ft_print_hex(va_arg(ap, unsigned long), printed, *str)))
			return (0);
	}
	return (1);
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



int			ft_parser(char **form, int *printed, va_list ap)
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
	if (!ft_print_parsed(*form, printed, ap))
		return (0);
	(*form)++;
	return (1);
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
			tmp++;
			if (!(ft_parser(&(tmp), &printed, ap)))
			{
				printed = -1;
				break;
			}
		}
		else
		{
			ft_putchar(*tmp, &printed);
			tmp++;
		}
	}
	va_end(ap);
	return (printed);
}
