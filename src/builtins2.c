/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:51:25 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/06 08:07:37 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env(char **env)
{
	while (*env)
		ft_putendl(*env++);
}

int			builtin_setenv(char **args, char ***env)
{
	if (args[0] && args[1] && args[2] && args[3])
		ft_putstr_fd("setenv: Too many arguments.\n", 2);
	else if (args[0] && args[1] && args[2])
		ft_setenv(args[1], args[2], env);
	else
		print_env(*env);
	return (EXIT_SUCCESS);
}

int			builtin_unsetenv(char **args, char **env)
{
	if (!*args++ || !*args)
		ft_putstr_fd("unsetenv: Too few arguments.\n", 2);
	while (*args)
		ft_unsetenv(*args++, env);
	return (EXIT_SUCCESS);
}

static bool	parse_options(char ***args, bool *empty)
{
	char *options;

	while (*++*args && (options = **args)[0] == '-')
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
	}
	return (true);
}

int			builtin_env(char **args, char **env)
{
	char	**modified_env;
	bool	empty;

	empty = false;
	if (!parse_options(&args, &empty))
		return (EXIT_FAILURE);
	env_init(&modified_env, empty ? NULL : env);
	while (*args && ft_strchr(*args, '='))
		ft_putenv(ft_strdup(*args++), &modified_env);
	if (*args)
	{
		if (ft_strchr(args[0], '/') || search_path(args, env))
			launch_process(args, modified_env);
		else
			ft_dprintf(2, "%s: No such file or directory\n", args[0]);
	}
	else
		print_env(modified_env);
	freestrarr(modified_env);
	return (EXIT_SUCCESS);
}
