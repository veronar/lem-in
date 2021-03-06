/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 09:46:32 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/26 15:32:23 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_free_her: courtesy of fremoor, mimeyer & nreddy.
** frees all elements in an a pointer array.
** then frees itself.
*/

void	ft_free_her(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

/*
** ft_check_split: splits the string read by spaces ' '
** if there are 3 elements its a room,
** if there is one its a link;
*/

int		ft_check_split(t_room **head_room, char *str, int *start, int *end)
{
	char		**arr;
	int			a_size;
	static int	link = 0;

	arr = ft_strsplit(str, ' ');
	a_size = 0;
	while (arr[a_size] != NULL)
		a_size++;
	if (a_size != 3 && a_size != 1)
	{
		ft_free_her(arr);
		return (-1);
	}
	else if (a_size == 3)
	{
		if (ft_rooms_func(head_room, arr, start, end) == -1 || link == 1)
			return (-1);
	}
	else if (a_size == 1)
	{
		link = 1;
		ft_free_her(arr);
		return (ft_link_func(head_room, str));
	}
	return (1);
}
