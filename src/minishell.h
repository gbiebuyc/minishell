/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:06:28 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/11 01:47:31 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <ft_printf.h>
# include <stdint.h>
# include <stdbool.h>
# include <assert.h>

int		execute_line(char **args, char ***env);
bool	search_path(char **args, char **env);
int		launch_process(char **args, char **env);
void	env_init(char ***newenv, char **env);
char	*ft_getenv(char *name, char **env);
void	ft_putenv(char *string, char ***envptr);
void	ft_setenv(char *name, char *value, char ***env);
void	ft_unsetenv(char *name, char **env);
void	tilde_expansion(char **env);
void	param_expansion(char **tokens, char **env);
int		len_till_special_char(char *var);
int		len_till_first_equ(char *s);
int		len_till_last_equ(char *s);
char	*getcwd_static(void);
int		builtin_cd(char **args, char ***env);
int		builtin_echo(char **args);
int		builtin_setenv(char **args, char ***env);
int		builtin_unsetenv(char **args, char **env);
int		builtin_env(char **args, char **env);
int		builtin_exit(char **args, bool *loop, int exit_status);
int		get_shlvl(char **env);
bool	path_join_inplace(char **left, char *right);
void	path_truncate_last_dir(char *path);
char	*path_get_front_dir(char **path);

#endif
