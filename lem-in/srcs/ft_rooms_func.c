/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:36:07 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 12:48:28 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_command: if there was a start command, the start integer will be
** positive. The next room name read will become the start (as per the command)
** if the start value is 1, make the current->start value 1, to indicate that
** node / room isthe start. Then change the start value to -1.
** Do the same with the ##end command.
** This way at the end of reading if both start && end values are not '-1'
** return an error.
** If there is a second (or even 3rd) start command in the file the value will
** increment with each command, ie start would equal 0, or 1, or more. It will
** be equal to -1 and hence still error.
*/

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

/*
** ft_check_coords: checks the coordinates given are only digits.
** if not, return error;
** if they are all digits, converts them to long long, and thereafter
** checks if they are in INT range. If any number is not within INT;
** error.
*/

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
** ft_rooms_func: If the array is 3 items long,
** checks if it is a start or end room with ft_command
** then checks the coords for only digits, frees & errors if its not
** lastly if both checks and int conversions are met, it stores the
** room name in the node, its coordinates and frees the 2d array of the
** read information.
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
	ft_free_her(arr);
	return (1);
}
