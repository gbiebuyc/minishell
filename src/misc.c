/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:16:53 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/03 03:13:17 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	malloc_error(void)
{
	ft_putstr_fd("minishell: malloc error\n", 2);
	exit(EXIT_FAILURE);
}

char	*getcwd_static(void)
{
	static char	buf[MAXPATHLEN];

	return (getcwd(buf, sizeof(buf)));
}

int		get_shlvl(char **env)
{
	char *shlvl;

	if (!(shlvl = ft_getenv("SHLVL", env)))
		shlvl = "0";
	return (ft_atoi(shlvl));
}

char	*join_path(char *left, char *right)
{
	char	*path;

	if (!left || !right)
		return (NULL);
	if (left[ft_strlen(left) - 1] == '/')
		return (ft_strjoin(left, right));
	if (!(path = malloc(sizeof(char) *
					(ft_strlen(left) + ft_strlen(right) + 2))))
		return (NULL);
	ft_strcat(ft_strcat(ft_strcpy(path, left), "/"), right);
	return (path);
}
