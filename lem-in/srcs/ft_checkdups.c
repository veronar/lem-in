/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:16:56 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/28 12:00:08 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_checkdups: check for duplicate rooms
** if true, error.
*/

int			ft_checkdups(t_room **head)
{
	t_room	*start;
	t_room	*second;

	start = *head;
	while (start != NULL)
	{
		second = start->next;
		while (second != NULL)
		{
			if (ft_strcmp(start->name, second->name) == 0)
				return (-1);
			second = second->next;
		}
		start = start->next;
	}
	return (1);
}
