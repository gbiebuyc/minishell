/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/23 16:23:54 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	pid_t	is_father;
	char	*line;

	while (42)
	{
		ft_printf("$> ");
		if (!get_next_line(0, &line))
			break ;
		is_father = fork();
		if (is_father)
			wait(NULL);
		else
			execve("/bin/ls", (char*[]){"/bin/ls", NULL}, NULL);
		free(line);
	}
}
