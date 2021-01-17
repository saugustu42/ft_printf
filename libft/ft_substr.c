/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:56:00 by saugustu          #+#    #+#             */
/*   Updated: 2020/10/28 20:56:00 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t maxlen)
{
	char	*substr;
	size_t	slen;
	size_t	len;

	slen = ft_strnlen(s, (size_t)start + maxlen);
	if ((size_t)start >= slen)
		return (ft_strdup(""));
	len = ft_strnlen(s + start, maxlen);
	if (len == 0)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (len + 1));
	if (substr)
		ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
