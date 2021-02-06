/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:17:14 by saugustu          #+#    #+#             */
/*   Updated: 2021/01/25 20:26:09 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (**form == '.')
	{
		(*form)++;
		flags.dot = ft_save_num(ap, form);
		if (flags.dot < -1)
			flags.dot = -1;
	}
	if (!ft_print_parsed(*form, printed, ap, &flags))
		return (0);
	(*form)++;
	return (1);
}

void		ft_set_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = -1;
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

int			ft_print_parsed(const char *str, int *printed,
		va_list ap, t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	if (flags->minus)
		flags->zero = 0;
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
		return (ft_print_sig(va_arg(ap, int), printed, flags));
	return (0);
}
