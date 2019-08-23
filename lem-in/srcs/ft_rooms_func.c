/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:36:07 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 10:44:27 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_command(t_room **current, int *start, int *end)
{
	if (*start == 1)
	{
		(*current)->start = 1;
		*start = -1;
	}
	else if (*end == 1)
	{
		(*current)->start = -1;
		*end = -1;
	}
	else
		(*current)->start = 0;
}

int			ft_check_coords(char **arr)
{
	long long	y;
	long long	x;
	int			i;
	int			j;

	i = 1;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (!ft_isdigit(arr[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	x = ft_atoll(arr[1]);
	y = ft_atoll(arr[2]);
	if ((x < 0 || x > 2147483647) || (y < 0 || y > 2147483647))
	{
		return (-1);
	}
	return (1);
}

/*
** ft_rooms_func: Is the array is 3 items long,
** this prints the room name to screen, and ensures the remaining to value are
** only digits, as these are the coordinates.
*/

int		ft_rooms_func(t_room **head_room, char **arr, int *start, int *end)
{
	t_room		*current;

	current = ft_listadd(head_room);
	if (*start == 1 || *end == 1)
		ft_command(&current, start, end);
	if (!ft_check_coords(arr))
	{
		ft_free_her(arr);
		ft_list_del(head_room);
		return (-1);
	}
	current->name = ft_strdup(arr[0]);
	current->x = ft_atoi(arr[1]);
	current->y = ft_atoi(arr[2]);
	current->next = NULL;
	current->links = NULL;
	// ft_putstr("Room name = ");
	// ft_putendl(current->name);
	// ft_putstr("     Coordinates: ");
	// ft_putnbr(current->x);
	// ft_putstr(" ");
	// ft_putnbr(current->y);
	// ft_putchar('\n');
	return (1);
}
