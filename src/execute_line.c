/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:14:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/06 16:57:15 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		launch_process(char **args, char **env)
{
	pid_t		pid;
	struct stat	st;
	int			status;

	if ((pid = fork()) < 0)
		ft_putstr_fd("minishell: fork error\n", 2);
	else if (pid == 0)
	{
		execve(args[0], args, env);
		if (access(args[0], F_OK) == -1)
		{
			ft_dprintf(2, "%s: No such file or directory\n", args[0]);
			exit(127);
		}
		else if (stat(args[0], &st) == 0 && S_ISDIR(st.st_mode))
			ft_dprintf(2, "%s: Is a directory\n", args[0]);
		else if (access(args[0], X_OK) == -1)
			ft_dprintf(2, "%s: Permission denied\n", args[0]);
		else
			ft_dprintf(2, "%s: No scripting in minishell\n", args[0]);
		exit(126);
	}
	else
		waitpid(pid, &status, 0);
	return (WIFEXITED(status) ? WEXITSTATUS(status) : EXIT_FAILURE);
}

bool	search_path(char **args, char **env)
{
	char	**paths;
	char	*completepath;
	int		i;

	if (!(paths = ft_strsplit(ft_getenv("PATH", env), ':')) || !paths[0])
	{
		freestrarr(paths);
		return (true);
	}
	i = 0;
	while (paths[i])
	{
		completepath = join_path(paths[i], args[0]);
		if (access(completepath, F_OK) == 0)
		{
			free(args[0]);
			args[0] = completepath;
			freestrarr(paths);
			return (true);
		}
		free(completepath);
		i++;
	}
	freestrarr(paths);
	return (false);
}

int		execute_line(char **args, char ***env)
{
	if (ft_strequ(args[0], "cd"))
		return (builtin_cd(args, env));
	if (ft_strequ(args[0], "echo"))
		return (builtin_echo(args));
	if (ft_strequ(args[0], "setenv"))
		return (builtin_setenv(args, env));
	if (ft_strequ(args[0], "unsetenv"))
		return (builtin_unsetenv(args, *env));
	if (ft_strequ(args[0], "env"))
		return (builtin_env(args, *env));
	if (ft_strchr(args[0], '/') || search_path(args, *env))
		return (launch_process(args, *env));
	ft_dprintf(STDERR_FILENO, "%s: command not found\n", args[0]);
	return (127);
}
