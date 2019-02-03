/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/03 22:27:55 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	char	**env;
	char	*line;
	char	**args;

	(void)ac;
	(void)av;
	env_init(&env, envp);
	ft_setenv("PWD", getcwd_static(), &env);
	ft_setenv("SHLVL", ft_itoa_static(get_shlvl(env) + 1), &env);
	while (42)
	{
		ft_printf("{green}{bold}%s{eoc}> ", ft_getenv("PWD", env));
		if (get_next_line(STDIN_FILENO, &line) <= 0)
			break ;
		if (line[0])
		{
			if (!(args = ft_strsplit(line, ' ')))
				malloc_error();
			tilde_expansion(args);
			param_expansion(args, env);
			execute_line(args, &env);
			freestrarr(args);
		}
		free(line);
	}
}
