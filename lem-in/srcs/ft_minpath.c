/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:49:50 by anorman           #+#    #+#             */
/*   Updated: 2019/09/16 16:26:11 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		st_put_linklen(t_room *node, int len)
{
	t_room **temp;
	int	i;	//testing

	i = 0; // testing
	temp = node->links;
	if (temp)
	{
		// while (*temp)
		while (temp[i])//testing
		{
			// if ((*temp)->len == -1)//Come back here
			if (temp[i]->len == -1) //testing
			{
				// ft_putstr(temp[i]->name);//testing
				// ft_putnbr(temp[i]->start);//testing
				sleep(5); //testing
				// (*temp)->len = len + 1;
				// (*temp)->prev = node;
				temp[i]->len = len + 1;//testing
				temp[i]->prev = node;//testing
			}
			//temp++;
			i++; //testing
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
	if (!(path = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	path[len] = NULL;
	while (len)
	{
		path[--len] = room->name;
		room = room->prev;
	}
	return (path);
}

char			**ft_excl_path(t_room *room)
{
	char	**path;
	int		len;
	t_room	*temp;

	len = 0;
	temp = room;
	while (temp && ++len)
		temp = temp->prev;
	if (!(path = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	path[len] = NULL;
	while (len)
	{
		if (room->start == 0)
		{
			free(room->links);
			room->links = NULL;
		}
		path[--len] = room->name;
		room = room->prev;
	}
	return (path);
}

/*
** Returns the path like a strsplit of the roomnames.
**
** excl_path removes the links of the middle rooms making them dead end
** and thus excluded from future path finding.
**
** path needs freeing but "dont free the roomnames"
** (the roomnames are just pointing at whats in each node)
** (so those can be freed when the rooms are freed)
*/

char			**ft_minpath(t_room *rooms)
{
	t_room	*temp;
	int		len;
	int		nopath;

	temp = rooms;
	len = 0;
	nopath = 0;
	while (!nopath)
	{
		
		ft_putstr(temp->name);
		ft_putstr("->start is : ");
		ft_putnbr(temp->start);
		ft_putchar('\n');
		ft_putstr(temp->name);
		ft_putstr("->len is : ");
		ft_putnbr(temp->len);
		ft_putchar('\n');
		if (temp == rooms)
			nopath = 1;
		while (temp && temp->len != len)	//Got to here.
			temp = temp->next;
		if (temp && temp->start != -1)
		{
			st_put_linklen(temp, len);
			// ft_putendl(temp->name);
			temp = temp->next;
			nopath = 0;
		}
		else if (temp)
			return (ft_excl_path(temp));
		if (!temp && ++len)
			temp = rooms;
	}
	return (NULL);
}

/*
** Finds the minpath, will inf loop if exit cant connect to start (for now)
*/
