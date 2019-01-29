/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:32 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/29 15:02:11 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(char **args)
{
	if (args[1])
		return (ft_putstr_fd("exit: too many arguments\n", 2));
	exit(EXIT_SUCCESS);
}

void	builtin_cd(char **args, char ***env)
{
	char	*new_dir;
	char	*oldpwd;

	if (!(new_dir = args[1]))
		if (!(new_dir = ft_getenv("HOME", *env)))
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2));
	if (new_dir[0] == '\0')
		return ;
	oldpwd = getcwd_static();
	if (chdir(new_dir) == 0)
	{
		ft_setenv("OLDPWD", oldpwd, env);
		ft_setenv("PWD", getcwd_static(), env);
	}
	else
	{
		if (access(args[1], F_OK) == -1)
			ft_dprintf(2, "cd: no such file or directory: %s\n", new_dir);
		else if (access(args[1], R_OK) == -1)
			ft_dprintf(2, "cd: permission denied: %s\n", new_dir);
		else
			ft_dprintf(2, "cd: not a directory: %s\n", new_dir);
	}
}
