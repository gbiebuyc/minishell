/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:14:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/24 13:49:01 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_process(char **args)
{
	pid_t	is_father;

	is_father = fork();
	if (is_father)
		wait(NULL);
	else
		execve(args[0], args, NULL);
}

void	builtin_exit(char **args)
{
	if (args[1])
		return (ft_putstr_fd("exit: too many arguments\n", 2));
	exit(EXIT_SUCCESS);
}

void	execute_line(char **args)
{
	if (ft_strequ(args[0], "exit"))
		builtin_exit(args);
	else
		launch_process(args);
}
