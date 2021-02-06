/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:32:27 by saugustu          #+#    #+#             */
/*   Updated: 2021/01/25 20:34:08 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		ft_put_sig(char *str, int *printed, int neg, t_flags *flags)
{
	char	filler;
	int		nodot;

	nodot = ft_set_numbers_sig(str, neg, flags);
	filler = (nodot && flags->zero) ? '0' : ' ';
	if (nodot && flags->zero && neg)
	{
		ft_putchar_c('-', printed);
		neg = 0;
	}
	if (!flags->minus)
		ft_putnchar(filler, printed, flags->width);
	if (neg)
		ft_putchar_c('-', printed);
	ft_putnchar('0', printed, flags->dot);
	ft_putstr_c(str, printed);
	if (flags->minus)
		ft_putnchar(filler, printed, flags->width);
}

int			ft_print_sig(int num, int *printed, t_flags *flags)
{
	long	n;
	int		neg;
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
	ft_put_sig(str, printed, neg, flags);
	free(str);
	return (1);
}
