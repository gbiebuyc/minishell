/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:37:22 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/31 04:32:41 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_next_token(char *newstr)
{
	static char	*s;
	char		*token;

	if (newstr)
		s = newstr;
	while (*s == ' ')
		s++;
	token = NULL;
	if (*s)
	{
		token = s;
		while (*s && *s != ' ')
			s++;
		if (*s)
			*s++ = '\0';
	}
	if (token && !(token = ft_strdup(token)))
		malloc_error();
	return (token);
}

char	**split_line(char *line, int arg_count)
{
	int		i;
	char	**tokens;

	if (!(tokens = malloc(sizeof(char*) * (arg_count + 1))))
		malloc_error();
	i = 0;
	tokens[i++] = get_next_token(line);
	while (i < arg_count)
		tokens[i++] = get_next_token(NULL);
	tokens[arg_count] = NULL;
	return (tokens);
}
