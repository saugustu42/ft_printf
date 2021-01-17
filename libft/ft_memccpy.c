/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:21 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/03 22:01:12 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		ch;
	unsigned char		*d;
	const unsigned char *s;
	size_t				index;

	ch = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (const unsigned char*)src;
	index = 0;
	while (s[index] != ch && index < n)
	{
		d[index] = s[index];
		index++;
	}
	if (index == n)
		return (NULL);
	d[index++] = ch;
	return (dst + index);
}
