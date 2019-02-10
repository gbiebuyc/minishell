/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:04:54 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/10 22:55:47 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(char ***new, char **env)
{
	if (env)
	{
		*new = dupstrarr(env);
		assert(*new);
	}
	else
	{
		*new = malloc(sizeof(**new));
		assert(*new);
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
	*envptr = malloc(sizeof(char*) * (i + 2));
	assert(*envptr);
	ft_memcpy(*envptr, env, sizeof(char*) * i);
	free(env);
	(*envptr)[i] = string;
	(*envptr)[i + 1] = NULL;
}

void	ft_setenv(char *name, char *value, char ***env)
{
	char	*string;
	size_t	value_len;

	if (!name)
		return ;
	if (!value)
		value = "";
	value_len = ft_strlen(value);
	if (value_len > 0 && value[0] == '"' && value[value_len - 1] == '"')
	{
		value[value_len - 1] = '\0';
		value++;
	}
	string = malloc(ft_strlen(name) + 1 + ft_strlen(value) + 1);
	assert(string);
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
