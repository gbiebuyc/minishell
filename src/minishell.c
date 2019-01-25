/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/25 01:14:48 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	char	*line;
	char	**args;

	(void)ac;
	(void)av;
	set_env_var("TEST", "hello", &envp);
	ft_putendl(get_env_var("TEST", envp));
	while (42)
	{
		ft_printf("{green}%s{eoc}> ", get_env_var("HOME", envp));
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
