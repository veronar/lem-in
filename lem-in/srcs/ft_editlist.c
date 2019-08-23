/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_editlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 07:36:48 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 09:27:28 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*ft_newnode(void)
{
	t_room	*head;

	head = (t_room*)malloc(sizeof(t_room));
	head->links = NULL;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

t_room		*ft_listadd(t_room **head_room)
{
	t_room	*current;

	if (*head_room == NULL)
	{
		*head_room = ft_newnode();
		current = *head_room;
	}
	else
	{
		current = *head_room;
		while (current->next != NULL)
			current = current->next;
		current->next = ft_newnode();
		current->next->prev = current;
		current = current->next;
	}
	return (current);
}

void		ft_lst_del(t_room **head)
{
	t_room	*current;
	t_room	*second;

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		second = current->next;
		free(current);
		current = second;
	}
	*head = NULL;
}
