/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:04:54 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/25 15:38:13 by gbiebuyc         ###   ########.fr       */
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
}

char	*env_get_var(char *name, char **env)
{
	char	*equ_sign;

	while (*env)
	{
		if (ft_strnequ(name, *env, (equ_sign = ft_strchr(*env, '=')) - *env))
			return (equ_sign + 1);
		env++;
	}
	return (NULL);
}

void	env_set_var(char *name, char *value, char ***envptr)
{
	int		i;
	char	**env;

	env = *envptr;
	i = 0;
	while (env[i])
	{
		if (ft_strnequ(name, env[i], ft_strchr(env[i], '=') - env[i]))
		{
			free(env[i]);
			env[i] = malloc(ft_strlen(name) + 1 + ft_strlen(value));
			ft_strcat(ft_strcat(ft_strcpy(env[i], name), "="), value);
			return ;
		}
		i++;
	}
	*envptr = malloc(sizeof(char*) * (i + 2));
	ft_memcpy(*envptr, env, sizeof(char*) * i);
	free(env);
	(*envptr)[i] = malloc(ft_strlen(name) + 1 + ft_strlen(value));
	ft_strcat(ft_strcat(ft_strcpy((*envptr)[i], name), "="), value);
	(*envptr)[i + 1] = NULL;
}
