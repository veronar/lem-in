/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:07:36 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 09:11:45 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_printlist(t_room **head)
{
	t_room	*start;

	start = *head;
	while (start != NULL)
	{
		ft_putstr("Room name = ");
		ft_putendl(start->name);
		ft_putstr("     Coordinates: ");
		ft_putnbr(start->x);
		ft_putstr(" ");
		ft_putnbr(start->y);
		ft_putchar('\n');
		start = start->next;
	}
	ft_putchar('\n');
}
