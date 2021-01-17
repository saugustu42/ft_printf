/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:59 by saugustu          #+#    #+#             */
/*   Updated: 2020/10/28 20:55:59 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_start(char const *str, char const *set)
{
	size_t		start;

	start = 0;
	while (str[start] && (ft_strchr(set, str[start]) != NULL))
		start++;
	return (start);
}

static size_t	ft_find_end(char const *str, char const *set)
{
	size_t		end;
	size_t		len;

	len = ft_strlen(str);
	end = 0;
	if (len)
	{
		end = len - 1;
		while (end && (ft_strchr(set, str[end]) != NULL))
			end--;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		result_len;
	char		*result;

	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	result_len = end - start + 1;
	result = ft_substr(s1, start, result_len);
	return (result);
}
