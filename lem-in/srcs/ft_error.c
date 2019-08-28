/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:11:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/28 14:16:50 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_error: error on standard error
*/

void		ft_error(void)
{
	ft_putendl_fd("ERROR", 2);
	//sleep(60);
	exit(1);
}

/*
** ft_usage: if incorrect usage of lem-in results.
*/

void		ft_usage(void)
{
	ft_putendl("Lem-in: requires no arguments");
	exit(1);
}

/*
** ft_freelists: iterates through 'parent' list, then iterates through
** subsequent list, frees all elements in the sub list, then frees the
** parent node;
** NB frees the names of the list, those were malloced for seperately than
** the actual node. if the name is not freed it will be a leak.
*/

void		ft_freelists(t_room **head)
{
	t_room	*current;
	t_room	*second;
	t_link	*clink;
	t_link	*clink2;

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		clink = current->links;
		while (clink != NULL)
		{
			clink2 = clink->next;
			free(clink->name);
			free(clink);
			clink = clink2;
		}
		second = current->next;
		free(current->name);
		free(current);
		current = second;
	}
	*head = NULL;
}
