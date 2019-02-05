/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:41:12 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/02/05 20:17:57 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function works similarly to getopt() from the POSIX C Library.
** At each call it returns the next option character from argv.
** It automatically advances argv so that when you parsed all options,
** argv points to the string just after the options.
** Remember to increment argv before calling the function because argv[0]
** contains the program name.
**
**	Example:
**
**	int main(int ac, char **av)
** 	{
** 		char c;
**
** 		av++;
** 		while ((c = get_next_opt(&av)))
** 		{
** 			if (c == 'a')
** 				printf("aaaaaa\n");
** 			else if (c == 'b')
** 				printf("bbbbbb\n");
** 			else
** 				printf("unknown\n");
** 		}
**
**		// remaining args
** 		while (*av)
**			printf("%s\n", *av++);
** 	}
*/

char	get_next_opt(char ***argvptr)
{
	static char	*lastchar;

	if (!argvptr || !*argvptr || !**argvptr || ***argvptr != '-')
		return (0);
	if (!lastchar || !*lastchar)
		lastchar = **argvptr;
	lastchar++;
	while (!*lastchar && *++*argvptr && (***argvptr == '-'))
		lastchar = **argvptr + 1;
	if (*lastchar)
		return (*lastchar);
	lastchar = NULL;
	return (0);
}
