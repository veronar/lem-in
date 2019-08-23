/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:33:11 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 11:24:57 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

int		ft_splitlinks(t_room **head, char *str)
{
	char	**link;
	t_room	*current;
	t_link	*clink;

	current = *head;
	link = ft_strsplit(str, '-');
	if (link[2] != NULL)
		return (-1);
	while (ft_strcmp(link[0], current->name) != 0)
		current = current->next;
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
