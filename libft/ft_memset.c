/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:38 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/03 21:57:50 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char chr;
	unsigned char *tmp;

	chr = (unsigned char)c;
	tmp = (unsigned char*)s;
	while (n--)
		*tmp++ = chr;
	return (s);
}
