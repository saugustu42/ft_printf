/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:37 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/04 22:54:31 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memrcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dst);
}
