/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:06:14 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/04 16:07:05 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	shellvar_len(char *var, bool specialchars)
{
	size_t	i;

	i = 0;
	while (specialchars ? (var[i] && var[i] != '=') :
			(ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return (i);
}

bool	shellvar_equ(char *var1, char *var2, bool specialchars)
{
	size_t	len;

	len = shellvar_len(var2, true);
	if (len != shellvar_len(var1, specialchars))
		return (false);
	return (ft_strnequ(var1, var2, len));
}
