/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:44:42 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/29 14:30:48 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tilde_expansion(char **tokens)
{
	char	*curr;
	char	*new;

	while ((curr = *tokens))
	{
		if (ft_strequ(curr, "~") || ft_strnequ(curr, "~/", 2))
			new = ft_strjoin("$HOME", curr + 1);
		else if (ft_strequ(curr, "~+") || ft_strnequ(curr, "~+/", 3))
			new = ft_strjoin("$PWD", curr + 2);
		else if (ft_strequ(curr, "~-") || ft_strnequ(curr, "~-/", 3))
			new = ft_strjoin("$OLDPWD", curr + 2);
		else
			new = NULL;
		if (new)
		{
			free(*tokens);
			*tokens = new;
		}
		tokens++;
	}
}

bool	expand_one_token_param(char **token_ptr, char **env)
{
	char	*token;
	size_t	left_len;
	char	*subst;
	char	*right_start;

	token = *token_ptr;
	left_len = 0;
	while (token[left_len] != '$')
		if (token[left_len++] == '\0')
			return (false);
	token += left_len + 1;
	token += (*token == '{') ? 1 : 0;
	if (!(subst = ft_getenv(token, env)))
		subst = "";
	token += shellvar_len(token);
	token += (*token == '}') ? 1 : 0;
	right_start = token;
	if (!(token = malloc(left_len + ft_strlen(subst) + ft_strlen(right_start) + 1)))
		malloc_error();
	token[0] = '\0';
	ft_strncat(token, *token_ptr, left_len);
	ft_strcat(ft_strcat(token, subst), right_start);
	free(*token_ptr);
	*token_ptr = token;
	return (true);
}

void	param_expansion(char **tokens, char **env)
{
	while (*tokens)
	{
		while (expand_one_token_param(&*tokens, env))
			;
		tokens++;
	}
}
