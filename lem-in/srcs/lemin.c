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
	//if (ac > 1)
	//	ft_error();
	head_room = NULL;
	ants = ft_ants();
	ft_putnbr(ants);
	ft_putchar('\n');
	// printf("ants = %i\n", ants);
	ft_reader(&head_room);
	if (!ants)
	{
		ft_freelists(&head_room);
		return (0);
	}
	// ft_printlinks(&head_room);
	// ft_printlist(&head_room);
	// write(1, "linked\n", 7);
	// paths = ft_pathfind(head_room, ants);
	if (!(paths = ft_pathfind(head_room)))
	{
		ft_freelists(&head_room);
		return(-1);
	}
	// ft_printpath(paths);
	ft_putchar('\n');
	move_ants(paths,ants);
	//sleep(60);
	return (0);
}
