/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/29 01:48:49 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int main(int ac, char **av, char **envp)
{
	char	**env;
	char	*line;
	char	**args;

	(void)ac;
	(void)av;
	env_init(&env, envp);
	while (42)
	{
		ft_printf("{green}{bold}%s{eoc}> ", ft_getenv("PWD", env));
		if (get_next_line(STDIN_FILENO, &line) <= 0)
			break ;
		if (line[0])
		{
			args = split_line(line, ft_wordcount(line, ' '));
			tilde_expansion(args);
			execute_line(args, &env);
			free_args(args);
		}
		free(line);
	}
}
