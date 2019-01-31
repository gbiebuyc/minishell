/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:16:53 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/31 18:42:52 by gbiebuyc         ###   ########.fr       */
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
