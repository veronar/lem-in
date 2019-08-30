/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:49:50 by anorman           #+#    #+#             */
/*   Updated: 2019/08/30 11:46:09 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room 	**st_unchecked(t_room *rooms)
{
	t_room	**list;
	int		len;
	int		i;

	len = ft_lstlen(*rooms);
	list = (t_room **)malloc(sizeof(t_room *) * len + 1);
	list[len] = NULL;
	i = 0;
	while (room)
	{
		list[i] = room;
		room = room->next;
	}
	return (list);
}

/*
** Returns an array containing all the rooms to help with dijkstras use.
*/

char			*ft_minpath(t_room *rooms)
{
	t_room	**list;
	t_room	**temp;
	int		len;

	list = st_unchecked(rooms);
	temp = list;
	len = 0;
	while (temp->start != -1 && temp->len != -1) //end when we have a len to the end;
	{

	}
	return (ft_path(*temp));
}
