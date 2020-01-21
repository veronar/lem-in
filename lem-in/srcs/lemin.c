/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:04:33 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/20 13:59:10 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	int		ants;
	t_room	*head_room;
	char	***paths;

	(void)av;
	(void)ac;
	head_room = NULL;
	ants = ft_ants();
	ft_putchar('\n');
	ft_reader(&head_room);
	if (!ants)
	{
		ft_freelists(&head_room);
		return (0);
	}
	if (!(paths = ft_pathfind(head_room)))
	{
		ft_freelists(&head_room);
		return (-1);
	}
	ft_putchar('\n');
	move_ants(paths, ants);
	ft_freelists(&head_room);
	ft_freepaths(&paths);
	return (0);
}
