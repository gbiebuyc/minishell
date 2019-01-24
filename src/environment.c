/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:41:18 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/24 17:40:28 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***envp_static(void)
{
	static char	**envp;

	return (&envp);
}

void	remember_envp(char **new)
{
	*envp_static() = new;
}

char	**get_envp(void)
{
	return (*envp_static());
}
