/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:14:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/03 22:26:53 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_process(char **args, char ***env)
{
	pid_t		pid;
	struct stat	st;

	if ((pid = fork()) < 0)
		ft_putstr_fd("minishell: fork error\n", 2);
	else if (pid == 0)
	{
		if (execve(args[0], args, *env) == -1)
		{
			if (access(args[0], F_OK) == -1)
				ft_dprintf(2, "%s: No such file or directory\n", args[0]);
			else if (stat(args[0], &st) == 0 && S_ISDIR(st.st_mode))
				ft_dprintf(2, "%s: Is a directory\n", args[0]);
			else if (access(args[0], X_OK) == -1)
				ft_dprintf(2, "%s: Permission denied\n", args[0]);
			else
				ft_dprintf(2, "%s: No scripting in minishell\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, NULL, 0);
}

bool	search_path(char **args, char **env)
{
	char	**paths;
	char	*completepath;
	int		i;

	if (!(paths = ft_strsplit(ft_getenv("PATH", env), ':')) || !paths[0])
	{
		freestrarr(paths);
		return (false);
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

void	execute_line(char **args, char ***env)
{
	if (ft_strchr(args[0], '/'))
		launch_process(args, env);
	else if (ft_strequ(args[0], "exit"))
		builtin_exit(args);
	else if (ft_strequ(args[0], "cd"))
		builtin_cd(args, env);
	else if (ft_strequ(args[0], "echo"))
		builtin_echo(args);
	else if (ft_strequ(args[0], "setenv"))
		builtin_setenv(args, env);
	else if (ft_strequ(args[0], "unsetenv"))
		builtin_unsetenv(args, *env);
	else if (search_path(args, *env))
		launch_process(args, env);
	else
		ft_dprintf(STDERR_FILENO, "%s: command not found\n", args[0]);
}
