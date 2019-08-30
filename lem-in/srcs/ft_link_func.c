/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:33:11 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/30 17:14:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_linkinfo: copies the pointers from the previous array, into the newly
** malloced array. adds the new link and a null terminator at the end.
*/

void	ft_linkinfo(t_room ***temp, t_room ***new, t_room **pointer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*new)[i] = (*temp)[i];
		i++;
	}
	(*new)[i] = *pointer;
	i++;
	(*new)[i] = NULL;
}

/*
** ft_linkarr: creates an array of pointers, each pointer points to the room
** that the parent node is linked to.
** These arrays are initally equal to NULL, and once populated the arrays are
** NULL-terminated.
** If the pointer is NULL to start it mallocs a new **t_rooms, adds the
** *pointer and then adds a NULL.
** If it isnt equal to NULL, it works out the size of the current array,
** mallocs for a new array of current size + 2 (1 for new pointer + 1 for NULL)
** It then calls ft_linkinfo to copy in the pointers from current array to
** new array.
*/

int		ft_linkarr(t_room **current, t_room **pointer)
{
	t_room	**temp;
	t_room	**new;
	int		size;

	temp = (*current)->links;
	size = 0;
	if (temp == NULL)
	{
		if (!(temp = (t_room**)malloc(sizeof(t_room*) * 2)))
			return (-1);
		temp[0] = *pointer;
		temp[1] = NULL;
		(*current)->links = temp;
		return (1);
	}
	while (temp[size] != NULL)
		size++;
	if (!(new = (t_room**)malloc(sizeof(t_room*) * (size + 2))))
		return (-1);
	ft_linkinfo(&temp, &new, pointer, size);
	free(temp);
	(*current)->links = new;
	return (1);
}

/*
** ft_splitlinks: takes the link string, seperates it into the rooms being
** linked, the first name is the source link, second is the destination.
** is there is more than 2 strings after the split return -1 to free & error.
** current pointer find the source room, pointer finds the destination room.
** Both these pointers are then passed to ft_linkarr to add them to the array
** of link pointers.
** If either are == NULL, then error.
*/

int		ft_splitlinks(t_room **head, char *str)
{
	char	**link;
	t_room	*current;
	t_room	*pointer;

	current = *head;
	pointer = *head;
	link = ft_strsplit(str, '-');
	if (link[2] != NULL)
		return (-1);
	while (current != NULL && ft_strcmp(link[0], current->name) != 0)
		current = current->next;
	while (pointer != NULL && ft_strcmp(link[1], pointer->name) != 0)
		pointer = pointer->next;
	ft_free_her(link);
	if (current == NULL || pointer == NULL)
		return (-1);
	if (ft_linkarr(&current, &pointer) == -1)
		return (-1);
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
