#include "ft_printf.h"
#include <stdlib.h>

char		*ft_strdup(const char *s)
{
	return (ft_strjoin(s, ""));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2 + 1);
	return (new);
}

size_t		ft_strlen(const char *s)
{
	size_t counter;

	counter = 0;
	while (*s++)
		counter++;
	return (counter);
}

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char*)dst;
	s = (const unsigned char*)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

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

char		*ft_conv_pos(unsigned long n, int bs, char c)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ch_count(n, bs);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len && n)
	{
		if (n % bs < 10)
			str[len - 1] = n % bs + '0';
		else
			str[len - 1] = (c == 'x') ? n % bs + 'a' - 10 : n % bs + 'A' - 10;
		n = n / bs;
		len--;
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


/*
int			ft_print_hex(unsigned long num, int *printed, char c)
{
	char	*str;
	int		i;

	str = ft_conv_pos(num, 16, c);
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

int			ft_print_sig(int num, int *printed)
{
	long	n_long;
	int		negative;
	char	*str;

	negative = 0;
	n_long = num;
	if (n_long < 0)
	{
		negative = 1;
		n_long = -n_long;
	}
	str = ft_conv_pos(n_long, 10, c);
	if (!str)
		return (0);
	if (negative)
		ft_putchar('-', printed);
	ft_putstr(str, printed);
	free(str);
	return (1);
}
*/

void		ft_putnchar(char c, int *printed, int n)
{
	while (n--)
		ft_putchar(c, printed);
}

void		ft_putnstr(char *str, int *printed, int n)
{
	while (*str && n)
	{
		ft_putchar(*str, printed);
		str++;
		n--;
	}
}

int			ft_print_s(char *str, int *printed, t_flags *flags)
{
	int		min;
	int		allocated;

	allocated = 0;
	if (str == NULL)
	{
		if (!(str = ft_strdup("(null)")) && (allocated = 1))
			return (0);
	}
	min = ft_strlen(str);
	if (flags->dot > -1)
	{
		if (flags->dot < min)
			min = flags->dot;
	}
	if (!flags->minus && flags->width > min)
		ft_putnchar(' ', printed, flags->width - min);
	ft_putnstr(str, printed, min);
	if (flags->minus && flags->width > min)
		ft_putnchar(' ', printed, flags->width - min);
	if (allocated)
		free(str);
	return (1);
}

int			ft_print_c(char c, int *printed, t_flags *flags)
{
	char	filler;

	filler = ' ';
	if (flags->zero)
		filler = '0';
	if (!flags->minus && flags->width > 1)
		ft_putnchar(filler, printed, flags->width - 1);
	ft_putchar(c, printed);
	if (flags->minus && flags->width > 1)
		ft_putnchar(filler, printed, flags->width - 1);
	return (1);
}

void		set_numbers(int len, t_flags *flags)
{
	int		bigger;
	
	bigger = len;
	if (flags->dot > len)
	{
		bigger = flags->dot;
		flags->dot = flags->dot - len;
	}
	else
		flags->dot = 0;
	if (flags->width > bigger)
		flags->width = flags->width - bigger;
	else
		flags->width = 0;
}


int			ft_print_u(unsigned int num, int *printed, t_flags *flags, char c)
{
	char	*str;
	int		len;
	int		fill;
	char	filler;

	filler = (flags->zero) ? '0' : ' ';
	if (num == 0 && flags->dot == 0)
		str = ft_strdup("");
	else
		str = (c == 'u') ? ft_conv_pos(num, 10, c) : ft_conv_pos(num, 16, c);
	if (!str)
		return (0);
	len = ft_strlen(str);
	set_numbers(len, flags);
	if (!flags->minus)
		ft_putnchar(filler, printed, flags->width);
	ft_putnchar('0', printed, flags->dot);
	ft_putstr(str, printed);
	if (flags->minus)
		ft_putnchar(filler, printed, flags->width);
	free(str);
	return (1);
}

int			ft_print_p(unsigned long num, int *printed, t_flags *flags)
{
	char	*str;
	int		len;

	if (num == 0 && flags->dot == 0)
		str = ft_strdup("");
	else
		str = ft_conv_pos(num, 16, 'x');
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (!flags->minus)
	{
		if (flags->width > len + 2)
			ft_putnchar(' ', printed, flags->width - len - 2);
	}
	*printed += write(1, "0x", 2);
	ft_putstr(str, printed);
	if (flags->minus)
	{
		if (flags->width > len + 2)
			ft_putnchar(' ', printed, flags->width - len - 2);
	}
	free(str);
	return (1);
}

int			ft_set_numbers_sig(char *str, int neg, t_flags *flags)
{
	int		bigger;
	int		len;
	int		nodot;

	len = ft_strlen(str);
	bigger = len;
	nodot = (flags->dot == -1) ? 1 : 0;
	if (neg && flags->width)
		flags->width--;
	if (flags->dot > bigger)
	{
		bigger = flags->dot;
		flags->dot = flags->dot - len;
	}
	else
		flags->dot = 0;
	if (flags->width > bigger)
		flags->width = flags->width - bigger;
	else
		flags->width = 0;
	return (nodot);
}

void		ft_print_sig(char *str, int *printed, int neg,
		int nodot, t_flags *flags)
{
	char	filler;

	filler = (nodot && flags->zero) ? '0' : ' ';
	if (nodot && flags->zero && neg)
	{
		ft_putchar('-', printed);
		neg = 0;
	}
	if (!flags->minus)
		ft_putnchar(filler, printed, flags->width);
	if (neg)
		ft_putchar('-', printed);
	ft_putnchar('0', printed, flags->dot);
	ft_putstr(str, printed);
	if (flags->minus)
		ft_putnchar(filler, printed, flags->width);
}

int			ft_prepare_sig(int num, int *printed, t_flags *flags)
{
	long	n;
	int		neg;
	int		nodot;
	char	*str;

	n = (long)num;
	neg = (n < 0) ? 1 : 0;
	if (neg)
		n = -n;
	if (n == 0 && flags->dot == 0)
		str = ft_strdup("");
	else
		str = ft_conv_pos(n, 10, 'i');
	if (!str)
		return (0);
	nodot = ft_set_numbers_sig(str, neg, flags);
	ft_print_sig(str, printed, neg, nodot, flags);
	free(str);
	return (1);
}


int			ft_print_parsed(const char *str, int *printed,
		va_list ap, t_flags *flags)
{
	if (*str == '%')
		return (ft_print_c('%', printed, flags));
	if (*str == 'c')
		return (ft_print_c(va_arg(ap, int), printed, flags));
	if (*str == 's')
		return (ft_print_s(va_arg(ap, char *), printed, flags));
	if (flags->dot > -1)
		flags->zero = 0;
	if (*str == 'u')
		return (ft_print_u(va_arg(ap, unsigned int), printed, flags, *str));
	if (*str == 'x' || *str == 'X')
		return (ft_print_u(va_arg(ap, unsigned int), printed, flags, *str));
	if (*str == 'p')
		return (ft_print_p(va_arg(ap, unsigned long), printed, flags));
	if (*str == 'i' || *str == 'd')
		return (ft_prepare_sig(va_arg(ap, int), printed, flags));
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
		(*form)++;
	}
	flags.width = ft_save_num(ap, form);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	if (flags.minus)
		flags.zero = 0;
	if (**form == '.')
	{
		(*form)++;
		flags.dot = ft_save_num(ap, form);
	}
	if (!ft_print_parsed(*form, printed, ap, &flags))
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
