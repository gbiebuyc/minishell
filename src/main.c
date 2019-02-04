/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/04 15:24:16 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(char ***env)
{
	char	*line;
	char	**args;

	while (42)
	{
		ft_printf("{green}{bold}%s{eoc}> ", ft_getenv("PWD", *env));
		if (get_next_line(STDIN_FILENO, &line) <= 0)
			return (ft_putstr("\nexit\n"));
		if (*line)
		{
			if (!(args = ft_strsplit(line, ' ')))
				malloc_error();
			tilde_expansion(args);
			param_expansion(args, *env);
			execute_line(args, env);
			freestrarr(args);
		}
		free(line);
	}
}

int		main(int ac, char **av, char **envp)
{
	char	**env;

	(void)ac;
	(void)av;
	env_init(&env, envp);
	ft_setenv("PWD", getcwd_static(), &env);
	ft_setenv("SHLVL", ft_itoa_static(get_shlvl(env) + 1), &env);
	shell_loop(&env);
	freestrarr(env);
}
