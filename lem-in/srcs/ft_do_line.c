/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:35:04 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 08:57:24 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_do_line: after reading a line, this function analyses the line to
** ensure it is in the correct format.
**
** 1. checks for open line; this is void input and should return error
**
** 2. checks for "##" which indicates that the next line is a command
** there should be a ##start & ##end in order for input to be valid.
** this uses an int to keep track of if there is a start & end point.
**
** 3. checks for comment lines starts with "#" and basically ignores them
**
** 4. checks correct input of room names with ft_check_split.
*/

int		ft_do_line(t_room **head_room, char *str, int *start, int *end)
{
	if (str[0] == '\0')
		return (-1);
	else if (str[0] == '#' && str[1] == '#')
	{
		if (ft_strcmp(str, "##start") == 0)
			*start = *start + 1;
		if (ft_strcmp(str, "##end") == 0)
			*end = *end + 1;
		ft_putendl("The next line is a command");
		return (0);
	}
	else if (str[0] == '#' && str[1] != '#')
	{
		ft_putendl("Comment: IGNORE");
		return (0);
	}
	else if (!ft_check_split(head_room, str, start, end))
	{
		ft_error();
		return (0);
	}
	else
		return (0);
}
