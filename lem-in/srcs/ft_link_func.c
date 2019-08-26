/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:33:11 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/26 14:25:54 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_linkinfo: the link should have the same info of the actual room node in
** the 'parent' list. We use this function to find the matching parent node
** and copy the relevant information in to reflect identical data.
*/

void	ft_linkinfo(t_room **head, t_link **clink)
{
	t_room	*current;

	current = *head;
	while (ft_strcmp(current->name, (*clink)->name) != 0)
		current = current->next;
	(*clink)->start = current->start;
	(*clink)->x = current->x;
	(*clink)->y = current->y;
	(*clink)->next = NULL;
}

/*
** ft_splitlinks: takes the link string, seperates it into the rooms being
** linked, the first name is the source link, second is the destination.
** is there is more than 2 strings after the split return -1 to free & error.
** Find the relevant room node, ie the source link room, then populate its
** t_link links pointer (which will start as NULL);
** Thereafter add the rest of the info with ft_linkinfo
** Lastly free the memory used for the stringsplit at the start of function.
*/

int		ft_splitlinks(t_room **head, char *str)
{
	char	**link;
	t_room	*current;
	t_link	*clink;

	current = *head;
	link = ft_strsplit(str, '-');
	if (link[2] != NULL)
		return (-1);
	while (current != NULL && ft_strcmp(link[0], current->name) != 0)
		current = current->next;
	if (current == NULL)
		return (-1);
	clink = current->links;
	clink = ft_linkadd(&current->links);
	clink->name = ft_strdup(link[1]);
	ft_linkinfo(head, &clink);
	ft_free_her(link);
	return (1);
}

/*
** ft_link_func: if there is only one argument given.
** check if the first letter is 'L' it is invalid
** if there is a '-' in the string that means it in a LINK
** use ft_splitlinks to split & store the links.
*/

void	ft_link_func(t_room **head_room, char *str)
{
	if (str[0] == 'L')
		ft_error();
	else if (ft_strchr(str, '-'))
	{
		if (ft_splitlinks(head_room, str) == -1)
			ft_error();
	}
	else
		ft_error();
}
