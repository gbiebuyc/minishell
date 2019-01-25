/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/26 23:23:55 by gbiebuyc         ###   ########.fr       */
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
	while (42)
	{
		ft_printf("{green}%s{eoc}> ", env_get_var("HOME", env));
		if (get_next_line(STDIN_FILENO, &line) <= 0)
			break ;
		if (line[0])
		{
			args = split_line(line, ft_wordcount(line, ' '));
			execute_line(args, envp);
			free(args);
		}
		free(line);
	}
}
