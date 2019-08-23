/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:07:36 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 13:15:24 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_printlist: iterates through 'parent' list, printing room names
** and their coordinates.
** shows heading START & END for significant rooms.
*/

void		ft_printlist(t_room **head)
{
	t_room	*current;

	current = *head;
	ft_putendl("\n\n");
	while (current != NULL)
	{
		if (current->start == 1)
		{
			ft_putendl("--------START-------");
			ft_putchar('\n');
		}
		else if (current->start == -1)
		{
			ft_putendl("---------END--------");
			ft_putchar('\n');
		}
		ft_putstr("Room name = ");
		ft_putendl(current->name);
		ft_putstr("     Coordinates: ");
		ft_putnbr(current->x);
		ft_putstr(" ");
		ft_putnbr(current->y);
		ft_putchar('\n');
		current = current->next;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

/*
** ft_printlinks: iterates through 'parent' list, for each list, prints out
** its subsequent links.
*/

void		ft_printlinks(t_room **head)
{
	t_room	*current;
	t_link	*clink;

	current = *head;
	ft_putendl("\n\n");
	while (current != NULL)
	{
		ft_putstr("--------");
		ft_putstr(current->name);
		ft_putendl("--------");
		clink = current->links;
		ft_putendl("");
		while (clink != NULL)
		{
			ft_putstr("Link: ");
			ft_putstr(clink->name);
			ft_putchar(' ');
			ft_putnbr(clink->x);
			ft_putchar(' ');
			ft_putnbr(clink->y);
			ft_putendl("");
			clink = clink->next;
		}
		ft_putstr("\n");
		current = current->next;
	}
	ft_putchar('\n');
}
