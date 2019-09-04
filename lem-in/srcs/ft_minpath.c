/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:49:50 by anorman           #+#    #+#             */
/*   Updated: 2019/09/04 13:28:09 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		st_put_linklen(t_room *node, int len)
{
	t_room **temp;

	temp = node->links;
	if (temp)
	{
		while (*temp)
		{
			(*temp)->len = len + 1;
			(*temp)->prev = node;
			temp++;
		}
	}
}

/*
** Fills in all the (*links)->len and (*links)->prev
*/

char			**ft_path(t_room *room)
{
	char	**path;
	int		len;	
	t_room	*temp;

	len = 0;
	temp = room;
	while (temp && ++len)
		temp = temp->prev;
	if (!(path = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	path[len] = NULL;
	len = 0;
	while (room)
	{
		path[len++] = room->name;
		room = room->prev;
	}
	return (path);
}

/*
** Returns the path like a strsplit of the roomnames.
**
** path needs freeing but "dont free the roomnames"
** (the roomnames are just pointing at whats in each node)
** (so those can be freed when the rooms are freed)
*/

char			**ft_minpath(t_room *rooms)
{
	t_room	*temp;
	int		len;

	temp = rooms;
	len = 0;
	while (temp->start != -1 && temp->len != -1) //end when we have a len in end;
	{
		while (temp->len != len) //find shortest current
			temp = temp->next;
		st_put_linklen(temp, len); //fill in linked nodes
		if (!temp && ++len) //reset to beginning 
			temp = rooms;
	}
	return (ft_path(temp));
}

/*
** Finds the minpath, will inf loop if exit cant connect to start (for now)
*/
