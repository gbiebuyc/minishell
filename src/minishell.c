/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/24 10:25:03 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char	*line;
	char	**args;

	while (42)
	{
		ft_printf("$> ");
		if (!get_next_line(0, &line))
			break ;
		if (line[0])
		{
			args = split_line(line, ft_wordcount(line, ' '));
			execute_line(args);
			free(args);
		}
		free(line);
	}
}
