/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_editlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 07:36:48 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/06 13:06:41 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_newnode: mallocs for a new t_room struct type; returns node malloced for.
*/

t_room		*ft_newnode(void)
{
	t_room	*head;

	head = (t_room*)malloc(sizeof(t_room));
	head->len = -1;
	head->links = NULL;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

/*
** ft_listadd: takes pointer of head node (t_room). If its empty, creates
** ft_newnode for it & returns node.
** If its not NULL, it iterates to the last node, ft_newnode for a new next node
** in said list & returns this node.
*/

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

/*
** frees all nodes in a list of type t_room.
*/

void		ft_list_del(t_room **head)
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
