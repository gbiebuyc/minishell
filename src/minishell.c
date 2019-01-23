/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/23 23:17:18 by gbiebuyc         ###   ########.fr       */
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
		args = split_line(line, ft_wordcount(line, ' '));
		execute_line(args);
		free(line);
		free(args);
	}
}
