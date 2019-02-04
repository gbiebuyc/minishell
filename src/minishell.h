/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:06:28 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/04 02:42:47 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <signal.h>
# include <ft_printf.h>
# include <stdint.h>
# include <stdbool.h>

void	execute_line(char **args, char ***env);
bool	search_path(char **args, char **env);
void	launch_process(char **args, char **env);
void	env_init(char ***newenv, char **env);
char	*ft_getenv(char *name, char **env);
void	ft_putenv(char *string, char ***envptr);
void	ft_setenv(char *name, char *value, char ***env);
void	ft_unsetenv(char *name, char **env);
void	tilde_expansion(char **env);
void	param_expansion(char **tokens, char **env);
size_t	shellvar_len(char *var, bool specialchars);
void	malloc_error(void);
char	*getcwd_static(void);
void	builtin_exit(char **args);
void	builtin_cd(char **args, char ***env);
void	builtin_echo(char **args);
void	builtin_setenv(char **args, char ***env);
void	builtin_unsetenv(char **args, char **env);
void	builtin_env(char **args, char **env);
int		get_shlvl(char **env);
char	*join_path(char *left, char *right);

#endif
