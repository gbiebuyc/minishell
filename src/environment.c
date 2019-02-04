/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:04:54 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/04 16:06:56 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(char ***new, char **env)
{
	if (env)
	{
		if (!(*new = dupstrarr(env)))
			malloc_error();
	}
	else
	{
		if (!(*new = malloc(sizeof(**new))))
			malloc_error();
		(*new)[0] = NULL;
	}
}

char	*ft_getenv(char *name, char **env)
{
	while (*env)
	{
		if (shellvar_equ(name, *env, false))
			return (ft_strchr(*env, '=') + 1);
		env++;
	}
	return (NULL);
}

void	ft_putenv(char *string, char ***envptr)
{
	int		i;
	char	**env;

	env = *envptr;
	i = 0;
	while (env[i])
	{
		if (shellvar_equ(string, env[i], true))
		{
			free(env[i]);
			env[i] = string;
			return ;
		}
		i++;
	}
	if (!(*envptr = malloc(sizeof(char*) * (i + 2))))
		malloc_error();
	ft_memcpy(*envptr, env, sizeof(char*) * i);
	free(env);
	(*envptr)[i] = string;
	(*envptr)[i + 1] = NULL;
}

void	ft_setenv(char *name, char *value, char ***env)
{
	char	*string;

	if (!(string = malloc(ft_strlen(name) + 1 + ft_strlen(value) + 1)))
		malloc_error();
	ft_strcat(ft_strcat(ft_strcpy(string, name), "="), value);
	ft_putenv(string, env);
}

void	ft_unsetenv(char *name, char **env)
{
	bool	found;

	found = false;
	while (*env)
	{
		if (!found && shellvar_equ(name, *env, true))
			found = true;
		if (found)
			*env = *(env + 1);
		env++;
	}
}
