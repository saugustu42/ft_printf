/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:31 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/03 21:58:47 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char ch;
	unsigned char *tmp;

	ch = (unsigned char)c;
	tmp = (unsigned char*)s;
	while (n--)
	{
		if (*tmp == ch)
			return (tmp);
		tmp++;
	}
	return (NULL);
}
