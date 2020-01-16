/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startfirst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:51:06 by vscott            #+#    #+#             */
/*   Updated: 2020/01/16 08:51:12 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_startfirst(t_room **head_room)
{
	t_room	*current;
	t_room	*temp;

	if (head_room)
	{
		current = *head_room;
		if (current->start != 1)
		{
			while (current->next->start != 1 || !(current->next))
				current = current->next;
			if (current->next)
			{
				temp = current->next;
				current->next = current->next->next;
				// ft_listadd(head_room, temp);
				temp->next = *head_room;
				*head_room = temp;
			}
		}	
	}
}