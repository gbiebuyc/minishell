/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:04:54 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/31 02:07:04 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(char ***env, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	if (!(*env = malloc(sizeof(**env) * (i + 1))))
		malloc_error();
	i = 0;
	while (envp[i])
	{
		(*env)[i] = ft_strdup(envp[i]);
		i++;
	}
	(*env)[i] = NULL;
	ft_setenv("PWD", getcwd_static(), env);
	ft_setenv("OLDPWD", getcwd_static(), env);
}

size_t	shellvar_len(char *var, bool specialchars)
{
	size_t	i;

	i = 0;
	while (specialchars ? (var[i] && var[i] != '=') :
			(ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return (i);
}

bool	shellvar_equ(char *var1, char *var2, bool specialchars)
{
	size_t	len;

	len = shellvar_len(var2, true);
	if (len != shellvar_len(var1, specialchars))
		return (false);
	return (ft_strnequ(var1, var2, len));
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
