/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:35:04 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 09:11:37 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_do_line(char *str, int *start, int *end)
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
		ft_putendl("That line was a comment: ignore");
		return (0);
	}
	else
		return (0);
}
