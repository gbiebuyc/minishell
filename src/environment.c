/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:04:54 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/24 20:47:54 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(char *name, char **env)
{
	char	*equ_sign;

	while (*env)
	{
		equ_sign = ft_strchr(*env, '=');
		if (ft_strnequ(name, *env, equ_sign - *env))
			return (equ_sign + 1);
		env++;
	}
	return (NULL);
}
