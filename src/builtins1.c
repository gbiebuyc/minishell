/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:32 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/05 11:39:08 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_cd(char **args, char ***env)
{
	char	*new_dir;
	char	*oldpwd;

	if (!(new_dir = args[1]))
		if (!(new_dir = ft_getenv("HOME", *env)))
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (EXIT_FAILURE);
		}
	if (new_dir[0] == '\0')
		return (EXIT_SUCCESS);
	oldpwd = getcwd_static();
	if (chdir(new_dir) == 0)
	{
		ft_setenv("OLDPWD", oldpwd, env);
		ft_setenv("PWD", getcwd_static(), env);
		return (EXIT_SUCCESS);
	}
	else
	{
		if (access(args[1], F_OK) == -1)
			ft_dprintf(2, "cd: no such file or directory: %s\n", new_dir);
		else if (access(args[1], R_OK) == -1)
			ft_dprintf(2, "cd: permission denied: %s\n", new_dir);
		else
			ft_dprintf(2, "cd: not a directory: %s\n", new_dir);
		return (EXIT_FAILURE);
	}
}

int		builtin_echo(char **args)
{
	bool	trailing_newline;

	trailing_newline = true;
	if (!*args++ || !*args)
		ft_putchar('\n');
	else
	{
		if (ft_strequ(*args, "-n"))
		{
			trailing_newline = false;
			args++;
		}
		while (*args)
		{
			ft_putstr(*args);
			if (*(args + 1))
				ft_putchar(' ');
			else if (trailing_newline)
				ft_putchar('\n');
			args++;
		}
	}
	return (EXIT_SUCCESS);
}
