/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:53:55 by saugustu          #+#    #+#             */
/*   Updated: 2020/10/28 20:53:58 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cursor;
	t_list	*cursor_ahead;

	cursor_ahead = *lst;
	while (cursor_ahead != NULL)
	{
		cursor = cursor_ahead;
		cursor_ahead = cursor_ahead->next;
		ft_lstdelone(cursor, del);
	}
	*lst = NULL;
}
