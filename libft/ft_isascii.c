/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:52:43 by saugustu          #+#    #+#             */
/*   Updated: 2020/10/28 20:53:07 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
