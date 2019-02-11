/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:06:14 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/11 07:56:00 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		len_till_special_char(char *var)
{
	int	i;

	i = 0;
	while (ft_isalnum(var[i]) || var[i] == '_')
		i++;
	return (i);
}

int		len_till_first_equ(char *s)
{
	char *equ_sign;

	if (!s || !(equ_sign = ft_strchr(s, '=')))
		return (-1);
	return ((int)(equ_sign - s));
}

int		len_till_last_equ(char *s)
{
	char *equ_sign;

	if (!s || !(equ_sign = ft_strrchr(s, '=')))
		return (-1);
	return ((int)(equ_sign - s));
}
