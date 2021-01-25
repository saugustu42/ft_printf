/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:35:47 by saugustu          #+#    #+#             */
/*   Updated: 2021/01/25 20:51:10 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_s(char *str, int *printed, t_flags *flags)
{
	int		min;
	int		allocated;

	allocated = 0;
	if (str == NULL)
	{
		if (!(str = ft_strdup("(null)")))
			return (0);
		else
			allocated = 1;
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
	ft_putchar_c(c, printed);
	if (flags->minus && flags->width > 1)
		ft_putnchar(filler, printed, flags->width - 1);
	return (1);
}
