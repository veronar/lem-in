/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:35:04 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/16 11:19:10 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_do_line(char *str)
{
	if (str[0] == '\0')
		return (-1);
	else if (str[0] == '#' && str[1] == '#')
	{
		ft_putendl("The next line is a command");
		return (0);
	}
	//else if (str[0] == '#' && str[1] != '#')
//		return (0);
	else
		return (0);
}
