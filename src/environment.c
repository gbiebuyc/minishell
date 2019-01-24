/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:41:18 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/24 17:22:51 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**remember_envp(bool replace, char **new)
{
	static char	**envp;

	return ((envp = replace ? new : envp));
}

char	**get_envp(void)
{
	return (remember_envp(false, NULL));
}
