/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 07:57:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/07 07:58:33 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	path_join_inplace(char **left, char *right)
{
	size_t	left_len;
	char	*new;

	if (!left || !*left || !right)
		return (false);
	left_len = ft_strlen(*left);
	if (left_len == 0 || (*left)[left_len - 1] == '/')
		new = ft_strjoin(*left, right);
	else
	{
		if ((new = malloc(sizeof(char) *
						(left_len + ft_strlen(right) + 2))))
			ft_strcat(ft_strcat(ft_strcpy(new, *left), "/"), right);
	}
	free(*left);
	return ((*left = new) ? true : false);
}

void	path_truncate_last_dir(char *path)
{
	char *slash;

	slash = ft_strrchr(path, '/');
	*(slash + 1) = '\0';
	if (!ft_strequ(path, "/"))
		*slash = '\0';
}

char	*path_get_front_dir(char **path)
{
	char *dir;
	char *slash;

	if ((*path)[0] == '/')
	{
		dir = ft_strdup("/");
		(*path)++;
	}
	else if ((slash = ft_strchr((*path), '/')))
	{
		dir = ft_strsub((*path), 0, slash - (*path));
		(*path) = slash + 1;
	}
	else
	{
		dir = ft_strdup((*path));
		(*path) = NULL;
	}
	return (dir);
}
