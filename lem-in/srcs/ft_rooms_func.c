/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:36:07 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 17:47:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_rooms_func: Is the array is 3 items long,
** this prints the room name to screen, and ensures the remaining to value are
** only digits, as these are the coordinates.
*/

void		ft_rooms_func(char **arr)
{
	int			i;
	static int	room;
	int			j;

	i = 0;
	ft_putstr("Room ");
	ft_putnbr(++room);
	ft_putstr(" name = ");
	ft_putendl(arr[i]);
	i++;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (!ft_isdigit(arr[i][j]))
			{
				ft_free_her(arr);
				ft_error();
			}
			j++;
		}
		i++;
	}
	ft_putstr("     Coordinates: ");
	ft_putstr(arr[1]);
	ft_putstr(" ");
	ft_putendl(arr[2]);
}
