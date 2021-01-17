/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:53:33 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/03 21:56:41 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ch_count(int n)
{
	int		counter;

	counter = 0;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		char_count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	char_count = ch_count(n);
	str = malloc(sizeof(char) * (char_count + 1));
	if (str == NULL)
		return (NULL);
	str[char_count] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (char_count && n)
	{
		str[char_count - 1] = n % 10 + '0';
		n = n / 10;
		char_count--;
	}
	return (str);
}
