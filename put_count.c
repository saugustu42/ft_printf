/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:28:30 by saugustu          #+#    #+#             */
/*   Updated: 2021/01/25 20:30:36 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar_c(char c, int *printed)
{
	*printed += write(1, &c, 1);
}

void		ft_putstr_c(char *str, int *printed)
{
	while (*str)
	{
		ft_putchar_c(*str, printed);
		str++;
	}
}

void		ft_putnchar(char c, int *printed, int n)
{
	while (n--)
		ft_putchar_c(c, printed);
}

void		ft_putnstr(char *str, int *printed, int n)
{
	while (*str && n)
	{
		ft_putchar_c(*str, printed);
		str++;
		n--;
	}
}
