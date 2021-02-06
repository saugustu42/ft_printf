/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:14:18 by saugustu          #+#    #+#             */
/*   Updated: 2021/01/25 20:53:43 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *form, ...)
{
	int		printed;
	char	*tmp;
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
				break ;
			}
		}
		else
			ft_putchar_c(*tmp++, &printed);
	}
	va_end(ap);
	return (printed);
}
