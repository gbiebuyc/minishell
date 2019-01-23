/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:22:51 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/18 23:25:21 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		fill_arr(char **arr, char const *s, size_t word_count, char c)
{
	size_t len;

	while (word_count--)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (!(*arr++ = ft_strsub(s, 0, len)))
			return (0);
		s += len;
	}
	*arr = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char **arr;

	if (!s)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	if (!fill_arr(arr, s, ft_wordcount(s, c), c))
		return (NULL);
	return (arr);
}
