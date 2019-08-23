/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:07:36 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 11:16:01 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
			ft_putendl(clink->name);
			clink = clink->next;
		}
		ft_putstr("\n");
		current = current->next;
	}
	ft_putchar('\n');
}
