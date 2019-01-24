/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:14:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/24 22:55:16 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_process(char **args, char **env)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		ft_putstr_fd("minishell: fork error\n", 2);
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			ft_putstr_fd("minishell: execve error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, NULL, 0);
}

void	builtin_exit(char **args)
{
	if (args[1])
		return (ft_putstr_fd("exit: too many arguments\n", 2));
	exit(EXIT_SUCCESS);
}

void	builtin_cd(char **args, char **env)
{
	(void)args;
	(void)env;
}

void	execute_line(char **args, char **env)
{
	if (ft_strequ(args[0], "exit"))
		builtin_exit(args);
	else if (ft_strequ(args[0], "cd"))
		builtin_cd(args, env);
	else
		launch_process(args, env);
}
