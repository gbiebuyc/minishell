/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:51:25 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/04 02:14:35 by gbiebuyc         ###   ########.fr       */
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

void	builtin_unsetenv(char **args, char **env)
{
	if (!*args++ || !*args)
		ft_putstr_fd("unsetenv: Too few arguments.\n", 2);
	while (*args)
		ft_unsetenv(*args++, env);
}

bool	parse_options(char *options, bool *empty)
{
	while (*++options)
	{
		if (*options == 'i')
			*empty = true;
		else
		{
			ft_dprintf(2, "env: invalid option -- '%c'\n", *options);
			return (false);
		}
	}
	return (true);
}

void	builtin_env(char **args, char **env)
{
	char	**modified_env;
	bool	empty;

	empty = false;
	while (*++args && (*args)[0] == '-')
		if (!parse_options(*args, &empty))
			return ;
	if (!empty)
		env_init(&modified_env, env);
	else
		env_init(&modified_env, NULL);
	while (*args && ft_strchr(*args, '='))
		ft_putenv(ft_strdup(*args++), &modified_env);
	if (*args)
	{
		if (!ft_strchr(args[0], '/'))
			search_path(args, env);
		launch_process(args, &modified_env);
	}
	else
		print_env(modified_env);
	freestrarr(modified_env);
}
