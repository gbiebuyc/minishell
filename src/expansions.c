/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:44:42 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/27 17:42:56 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tilde_expansion(char **env)
{
	char	*to_free;

	while (*env)
	{
		to_free = *env;
		if (ft_strequ(*env, "~") || ft_strnequ(*env, "~/", 2))
			*env = ft_strjoin("$HOME", *env + 1);
		else if (ft_strequ(*env, "~+") || ft_strnequ(*env, "~+/", 3))
			*env = ft_strjoin("$PWD", *env + 2);
		else if (ft_strequ(*env, "~-") || ft_strnequ(*env, "~-/", 3))
			*env = ft_strjoin("$OLDPWD", *env + 2);
		else
			to_free = NULL;
		free(to_free);
		env++;
	}
}
