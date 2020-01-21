/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:21:03 by vscott            #+#    #+#             */
/*   Updated: 2020/01/21 12:22:11 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_free_linkarr: adaption of ft_free_her (ft_check_split.c) - for t_room**.
** frees all elements in an a pointer array.
** then frees itself.
*/

void	ft_free_linkarr(t_room **arr)
{
	if (!arr)
		return ;
	free(arr);
}

/*
** ft_freelists: iterates through 'parent' list, then iterates through
** subsequent list, frees all elements in the sub list, then frees the
** parent node;
** NB frees the names of the list, those were malloced for seperately than
** the actual node. if the name is not freed it will be a leak.
*/

void	ft_freelists(t_room **head)
{
	t_room	*current;
	t_room	*second;

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		ft_free_linkarr((current->links));
		second = current->next;
		free(current->name);
		free(current);
		current = second;
	}
	*head = NULL;
}

void	ft_freepaths(char ****path_address)
{
	int		k;
	char	***paths;

	paths = *path_address;
	k = 0;
	while (paths[k])
	{
		free(paths[k]);
		k++;
	}
	free(paths);
	paths = NULL;
}

void	ft_free_links(t_room *room)
{
	free(room->links);
	room->links = NULL;
}
