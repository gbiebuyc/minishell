/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/05 11:11:10 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(char ***env, int *exit_status)
{
	char	*line;
	char	**args;
	bool	loop;

	loop = true;
	while (loop)
	{
		ft_printf("{green}{bold}%s{eoc}> ", ft_getenv("PWD", *env));
		if (get_next_line(STDIN_FILENO, &line) <= 0)
			break ;
		if (*line)
		{
			if (!(args = ft_strsplit(line, ' ')))
				malloc_error();
			tilde_expansion(args);
			param_expansion(args, *env);
			if (ft_strequ(args[0], "exit"))
				loop = false;
			else
				*exit_status = execute_line(args, env);
			freestrarr(args);
		}
		free(line);
	}
}

int		main(int ac, char **av, char **envp)
{
	char	**env;
	int		exit_status;

	(void)ac;
	(void)av;
	exit_status = EXIT_SUCCESS;
	env_init(&env, envp);
	ft_setenv("PWD", getcwd_static(), &env);
	ft_setenv("SHLVL", ft_itoa_static(get_shlvl(env) + 1), &env);
	if (!ft_getenv("PATH", env))
		ft_setenv("PATH", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", &env);
	shell_loop(&env, &exit_status);
	freestrarr(env);
	return (exit_status);
}
