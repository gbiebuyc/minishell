/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:24:58 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/07 08:45:42 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_echo(char **args)
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

int		builtin_exit(char **args, bool *loop, int exit_status)
{
	char *arg;

	if (args[1] && args[2])
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	*loop = false;
	if ((arg = args[1]))
	{
		while (*arg)
		{
			if (!ft_isdigit(*arg))
			{
				ft_putstr_fd("exit: numeric argument required\n", 2);
				return (EXIT_FAILURE);
			}
			arg++;
		}
		return (ft_atoi(args[1]));
	}
	return (exit_status);
}
