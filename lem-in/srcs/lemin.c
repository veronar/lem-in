/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:04:33 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/09 15:48:25 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	int		ants;
	t_room	*head_room;
	char	***paths;

	(void)av;
	if (ac > 1)
		ft_error();
	head_room = NULL;
	ants = ft_ants();
	printf("ants = %i\n", ants);
	ft_reader(&head_room);
	ft_printlist(&head_room);
	ft_printlinks(&head_room);
	write(1, "linked\n", 7);
	paths = ft_pathfind(head_room, ants);
	ft_printpath(paths);
	//sleep(60);
	return (0);
}
