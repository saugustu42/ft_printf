/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:51 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/03 21:41:52 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** chars_cpy_count is number of chars to copy to dst
** nul_term_occ is a pointer to  null terminator in dst
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	chars_cpy_count;
	char	*nul_term_occ;

	len_src = ft_strlen(src);
	nul_term_occ = ft_memchr(dst, '\0', size);
	if (nul_term_occ == NULL)
		return (size + len_src);
	len_dst = nul_term_occ - dst;
	if (len_dst < size - 1)
	{
		chars_cpy_count = len_src;
		if (size - len_dst - 1 < len_src)
			chars_cpy_count = size - len_dst - 1;
		ft_memcpy(nul_term_occ, src, chars_cpy_count);
		dst[len_dst + chars_cpy_count] = '\0';
	}
	return (len_dst + len_src);
}
