/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:33:11 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 17:49:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_link_func: if there is only one argument given.
** check if the first letter is 'L' it is invalid
** if there is a '-' in the string that means it in a LINK
*/

void	ft_link_func(char *str)
{
	if (str[0] == 'L')
		ft_error();
	else if (ft_strchr(str, '-'))
		ft_putendl("LINK");
	else
		ft_error();
}
