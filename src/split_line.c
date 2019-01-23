/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:37:22 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/23 23:09:05 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_next_arg(char *newstr)
{
	static char	*s;
	char		*ret;

	if (newstr)
		s = newstr;
	while (*s == ' ')
		s++;
	ret = NULL;
	if (*s)
	{
		ret = s;
		while (*s && *s != ' ')
			s++;
		*s++ = '\0';
	}
	return (ret);
}

char	**split_line(char *line, int arg_count)
{
	int		i;
	char	**ret;

	ret = malloc(sizeof(char*) * (arg_count + 1));
	i = 0;
	ret[i++] = get_next_arg(line);
	while (i < arg_count)
		ret[i++] = get_next_arg(NULL);
	ret[arg_count] = NULL;
	return (ret);
}
