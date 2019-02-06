/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:24:58 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/06 17:27:54 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
