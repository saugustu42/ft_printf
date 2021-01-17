/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:52 by saugustu          #+#    #+#             */
/*   Updated: 2020/10/28 20:55:52 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	chars_cpy_count;

	len_src = ft_strlen(src);
	if (size)
	{
		chars_cpy_count = len_src;
		if (len_src > size - 1)
			chars_cpy_count = size - 1;
		ft_memcpy(dst, src, chars_cpy_count);
		dst[chars_cpy_count] = '\0';
	}
	return (len_src);
}
