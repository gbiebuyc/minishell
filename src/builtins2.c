/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:51:25 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/29 16:17:12 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	while (*env)
		ft_putendl(*env++);
}

void	builtin_setenv(char **args, char ***env)
{
	if (args[0] && args[1] && args[2] && args[3])
		ft_putstr_fd("setenv: Too many arguments.\n", 2);
	else if (args[0] && args[1] && args[2])
		ft_setenv(args[1], args[2], env);
	else
		print_env(*env);
}
