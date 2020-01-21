/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:16:56 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/06 11:22:03 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_dupcoords: check for duplicate room coordinates, ie two rooms in the
** same place.
** if true, error.
*/

int			ft_dupcoords(t_room **head)
{
	t_room	*start;
	t_room	*second;

	start = *head;
	while (start != NULL)
	{
		second = start->next;
		while (second != NULL)
		{
			if (start->x == second->x && start->y == second->y)
				return (-1);
			second = second->next;
		}
		start = start->next;
	}
	return (1);
}

/*
** ft_dupnames: check for duplicate rooms
** if true, error.
*/

int			ft_dupnames(t_room **head)
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

/*
** ft_checkdups: calls to check dup name & coords
*/

int			ft_checkdups(t_room **head)
{
	if (ft_dupnames(head) == -1 || ft_dupcoords(head) == -1)
		return (-1);
	else
		return (1);
}
