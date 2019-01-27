/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:44:42 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/27 23:58:26 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tilde_expansion(char **tokens)
{
	char	*curr;
	char	*new;

	while ((curr = *tokens))
	{
		if (ft_strequ(curr, "~") || ft_strnequ(curr, "~/", 2))
			new = ft_strjoin("$HOME", curr + 1);
		else if (ft_strequ(curr, "~+") || ft_strnequ(curr, "~+/", 3))
			new = ft_strjoin("$PWD", curr + 2);
		else if (ft_strequ(curr, "~-") || ft_strnequ(curr, "~-/", 3))
			new = ft_strjoin("$OLDPWD", curr + 2);
		else
			new = NULL;
		if (new)
		{
			free(*tokens);
			*tokens = new;
		}
		tokens++;
	}
}
