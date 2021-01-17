/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:56 by saugustu          #+#    #+#             */
/*   Updated: 2020/10/28 20:55:56 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	len_lit;
	size_t	counter;

	len_lit = ft_strlen(lit);
	if (len_lit == 0)
		return ((char *)(big));
	if (len_lit <= len)
	{
		counter = 0;
		while (counter <= len - len_lit)
		{
			if (!ft_strncmp(big + counter, lit, len_lit))
				return ((char *)(big + counter));
			counter++;
		}
	}
	return (NULL);
}
