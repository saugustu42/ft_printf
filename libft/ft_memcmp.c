/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:32 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/07 16:38:28 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int						ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	int					diff;
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char*)buf1;
	s2 = (unsigned char*)buf2;
	while (n--)
	{
		diff = *s1++ - *s2++;
		if (diff != 0)
			return (diff);
	}
	return (0);
}
