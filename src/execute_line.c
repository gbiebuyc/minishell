/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:14:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/29 01:48:24 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_process(char **args, char ***env)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		ft_putstr_fd("minishell: fork error\n", 2);
	else if (pid == 0)
	{
		if (execve(args[0], args, *env) == -1)
		{
			ft_putstr_fd("minishell: execve error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, NULL, 0);
}

char	*getcwd_static(void)
{
	static char	buf[MAXPATHLEN];

	return (getcwd(buf, sizeof(buf)));
}

void	builtin_exit(char **args)
{
	if (args[1])
		return (ft_putstr_fd("exit: too many arguments\n", 2));
	exit(EXIT_SUCCESS);
}

void	builtin_cd(char **args, char ***env)
{
	char	*new_dir;
	char	*oldpwd;

	new_dir = args[1];
	if (!new_dir)
		new_dir = ft_getenv("HOME", *env);
	if (!new_dir)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2));
	oldpwd = getcwd_static();
	if (chdir(new_dir) == 0)
	{
		ft_setenv("OLDPWD", oldpwd, env);
		ft_setenv("PWD", getcwd_static(), env);
	}
	else
	{
		if (access(args[1], F_OK) == -1)
			ft_dprintf(2, "cd: no such file or directory: %s\n", args[1]);
		else if (access(args[1], R_OK) == -1)
			ft_dprintf(2, "cd: permission denied: %s\n", args[1]);
		else
			ft_dprintf(2, "cd: not a directory: %s\n", args[1]);
	}
}

void	execute_line(char **args, char ***env)
{
	if (ft_strequ(args[0], "exit"))
		builtin_exit(args);
	else if (ft_strequ(args[0], "cd"))
		builtin_cd(args, env);
	else
		launch_process(args, env);
}
