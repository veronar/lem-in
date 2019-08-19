/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:36:07 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 11:43:18 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_rooms_func(char **arr)
{
	int			i;
	static int	room;
	int			j;

	room = 1;
	i = 0;
	ft_putstr("Room ");
	ft_putnbr(room++);
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
}
