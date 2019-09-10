/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:49:50 by anorman           #+#    #+#             */
/*   Updated: 2019/09/10 11:24:12 by anorman          ###   ########.fr       */
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
			if ((*temp)->len == -1)
			{
				(*temp)->len = len + 1;
				(*temp)->prev = node;
			}
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
	while (len)
	{
		path[--len] = room->name;
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
	int		inf;

	temp = rooms;
	len = 0;
	inf = 0;
	while (!inf) //end when returned valid or infinite detected
	{
		if (temp == rooms)
			inf = 1;
		while (temp && temp->len != len) //find shortest current
			temp = temp->next;
		if (temp && temp->start != -1)
		{
			st_put_linklen(temp, len); //fill in linked nodes
			temp = temp->next;
			inf = 0;
		}
		else if (temp)
			return (ft_path(temp)); //return when we have a len in end
		if (!temp && ++len) //reset to beginning 
			temp = rooms;
	}
	write(1, "inf\n", 4);
	return (NULL);
}

/*
** Finds the minpath, will inf loop if exit cant connect to start (for now)
*/
