/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:36 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/03 21:23:01 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char ch;
	unsigned char *tmp;

	ch = (unsigned char)c;
	tmp = (unsigned char*)s;
	while (n)
	{
		if (*(tmp + n - 1) == ch)
			return (tmp + n - 1);
		n--;
	}
	return (NULL);
}
