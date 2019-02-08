/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:32 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/08 07:58:23 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_options(char ***args, bool *follow_symlink)
{
	char *options;

	while (*++*args && (options = **args)[0] == '-' && options[1])
	{
		while (*++options)
			if (*options != 'L' && *options != 'P')
				return ;
		options = **args;
		while (*++options)
		{
			if (*options == 'L')
				*follow_symlink = true;
			else if (*options == 'P')
				*follow_symlink = false;
		}
	}
}

static bool	cd_follow_symlink(char *userpath, char *abspath, char ***env)
{
	char *nextdir;

	if (!userpath || !*userpath)
	{
		if (chdir(abspath) == 0)
		{
			ft_setenv("OLDPWD", ft_getenv("PWD", *env), env);
			ft_setenv("PWD", abspath, env);
			free(abspath);
			return (true);
		}
		free(abspath);
		return (false);
	}
	nextdir = path_get_front_dir(&userpath);
	if (ft_strequ(nextdir, "."))
		;
	else if (ft_strequ(nextdir, ".."))
		path_truncate_last_dir(abspath);
	else if (ft_strequ(nextdir, "/"))
		ft_strcpy(abspath, "/");
	else
		path_join_inplace(&abspath, nextdir);
	free(nextdir);
	return (cd_follow_symlink(userpath, abspath, env));
}

static bool	cd_resolve_symlink(char *target_dir, char ***env)
{
	char *cwd;

	if (!*target_dir)
		return (true);
	cwd = getcwd_static();
	if (chdir(target_dir) != 0)
		return (false);
	ft_setenv("OLDPWD", cwd, env);
	ft_setenv("PWD", getcwd_static(), env);
	return (true);
}

static char	*get_target_path(char *arg, char **env)
{
	char *ret;

	if (ft_strequ(arg, "-"))
	{
		if (!(ret = ft_getenv("OLDPWD", env)))
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
	}
	else if (!(ret = arg ? arg : ft_getenv("HOME", env)))
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
	return (ret);
}

int			builtin_cd(char **args, char ***env)
{
	char	*target_dir;
	bool	follow_symlink;

	follow_symlink = true;
	parse_options(&args, &follow_symlink);
	if (!(target_dir = get_target_path(*args, *env)))
		return (EXIT_FAILURE);
	if ((follow_symlink && cd_follow_symlink(target_dir,
					ft_strdup(ft_getenv("PWD", *env)), env)) ||
			(!follow_symlink && cd_resolve_symlink(target_dir, env)))
		return (EXIT_SUCCESS);
	if (access(target_dir, F_OK) == -1)
		ft_dprintf(2, "cd: no such file or directory: %s\n", target_dir);
	else if (access(target_dir, R_OK) == -1)
		ft_dprintf(2, "cd: permission denied: %s\n", target_dir);
	else
		ft_dprintf(2, "cd: not a directory: %s\n", target_dir);
	return (EXIT_FAILURE);
}
