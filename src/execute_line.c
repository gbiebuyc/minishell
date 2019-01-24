/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:14:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/24 20:51:51 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_process(char **args, char **envp)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		ft_putstr_fd("minishell: fork error\n", 2);
	else if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
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

void	execute_line(char **args, char **envp)
{
	if (ft_strequ(args[0], "exit"))
		builtin_exit(args);
	else
		launch_process(args, envp);
}
