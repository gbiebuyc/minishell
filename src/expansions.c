/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:44:42 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/11 01:48:15 by gbiebuyc         ###   ########.fr       */
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

char	*expand_one_token_param(char *token, char **env)
{
	size_t	left_len;
	char	*subst;
	char	*right_start;
	char	*tokencpy;
	char	*new;

	tokencpy = token;
	left_len = 0;
	while (token[left_len] != '$')
		if (token[left_len++] == '\0')
			return (NULL);
	token += left_len + 1;
	token += (*token == '{') ? 1 : 0;
	if (!(subst = ft_getenv(token, env)))
		subst = "";
	token += len_till_special_char(token);
	token += (*token == '}') ? 1 : 0;
	right_start = token;
	new = malloc(left_len + ft_strlen(subst) + ft_strlen(right_start) + 1);
	assert(new);
	new[0] = '\0';
	ft_strncat(new, tokencpy, left_len);
	ft_strcat(ft_strcat(new, subst), right_start);
	return (new);
}

void	param_expansion(char **tokens, char **env)
{
	char	*new;

	while (*tokens)
	{
		while ((new = expand_one_token_param(*tokens, env)))
		{
			free(*tokens);
			*tokens = new;
		}
		tokens++;
	}
}
