/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:46 by saugustu          #+#    #+#             */
/*   Updated: 2020/11/05 17:55:26 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t		words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void		ft_clean(char **tab, size_t index)
{
	while (index)
		free(tab[--index]);
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	char		**words;
	size_t		words_count;
	size_t		word_index;

	words_count = count(s, c);
	words = malloc(sizeof(char*) * (words_count + 1));
	if (words != NULL)
	{
		word_index = 0;
		while (word_index < words_count)
		{
			while (*s == c)
				s++;
			words[word_index] = ft_substr(s, 0, ft_wordlen(s, c));
			if (words[word_index] == NULL)
			{
				ft_clean(words, word_index);
				return (NULL);
			}
			s += ft_wordlen(s, c);
			word_index++;
		}
		words[words_count] = NULL;
	}
	return (words);
}
