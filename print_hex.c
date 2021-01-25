/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:51:47 by saugustu          #+#    #+#             */
/*   Updated: 2021/01/25 20:53:34 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ft_putstr_c(str, printed);
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
	ft_putstr_c(str, printed);
	if (flags->minus)
	{
		if (flags->width > len + 2)
			ft_putnchar(' ', printed, flags->width - len - 2);
	}
	free(str);
	return (1);
}
