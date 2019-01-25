/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:06:28 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/25 15:37:34 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <ft_printf.h>
# include <stdint.h>
# include <stdbool.h>

char	**split_line(char *line, int arg_count);
void	execute_line(char **args, char **env);
void	env_init(char ***env, char **envp);
char	*env_get_var(char *name, char **env);
void	env_set_var(char *name, char *value, char ***envptr);

#endif
