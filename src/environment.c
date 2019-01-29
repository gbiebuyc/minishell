/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:04:54 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/29 13:31:32 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(char ***env, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	*env = malloc(sizeof(**env) * (i + 1));
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

size_t	shellvar_len(char *var)
{
	size_t	i;

	i = 0;
	while (ft_isalnum(var[i]) || var[i] == '_')
		i++;
	return (i);
}

bool	shellvar_equ(char *var1, char *var2)
{
	size_t	len1;
	size_t	len2;

	len1 = shellvar_len(var1);
	len2 = shellvar_len(var2);
	if (len1 != len2)
		return (false);
	return (ft_strnequ(var1, var2, len1));
}

char	*ft_getenv(char *name, char **env)
{
	while (*env)
	{
		if (shellvar_equ(name, *env))
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
		if (shellvar_equ(string, env[i]))
		{
			free(env[i]);
			env[i] = string;
			return ;
		}
		i++;
	}
	if (!(*envptr = malloc(sizeof(char*) * (i + 2))))
	{
		ft_putstr_fd("minishell: malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(*envptr, env, sizeof(char*) * i);
	free(env);
	(*envptr)[i] = string;
	(*envptr)[i + 1] = NULL;
}

void	ft_setenv(char *name, char *value, char ***env)
{
	char	*string;

	if (!(string = malloc(ft_strlen(name) + 1 + ft_strlen(value) + 1)))
	{
		ft_putstr_fd("minishell: malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_strcat(ft_strcat(ft_strcpy(string, name), "="), value);
	ft_putenv(string, env);
}
/*
void	ft_unsetenv(char *name, char ***envptr)
{
}
*/
