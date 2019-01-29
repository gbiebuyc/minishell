/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:06:28 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/29 14:26:03 by gbiebuyc         ###   ########.fr       */
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

char	**split_line(char *line, int arg_count);
void	execute_line(char **args, char ***env);
void	env_init(char ***env, char **envp);
void	tilde_expansion(char **env);
void	param_expansion(char **tokens, char **env);
char	*getcwd_static(void);
size_t	shellvar_len(char *var);
char	*ft_getenv(char *name, char **env);
void	ft_putenv(char *string, char ***envptr);
void	ft_setenv(char *name, char *value, char ***env);
void	malloc_error(void);

#endif
