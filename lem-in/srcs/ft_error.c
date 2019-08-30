/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:11:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/30 11:17:26 by vesingh          ###   ########.fr       */
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
** ft_free_linkarr: adaption of ft_free_her (ft_check_split.c) - for t_room**.
** frees all elements in an a pointer array.
** then frees itself.
*/

void	ft_free_linkarr(t_room **arr)
{
	int	i;

	i = 0;
	if (*arr == NULL)
		return ;
	while (arr[i])
	{
		ft_memdel((void **)&arr[i]);
		i++;
	}
	free(arr);
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

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		ft_free_linkarr(current->links);
		second = current->next;
		free(current->name);
		free(current);
		current = second;
	}
	*head = NULL;
}
