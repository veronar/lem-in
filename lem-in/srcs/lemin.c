/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:04:33 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/23 11:12:35 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	int		ants;
	t_room	*head_room;

	(void)av;
	if (ac > 1)
		ft_usage();
	head_room = NULL;
	ants = ft_ants();
	//printf("ac = %i\n", ac);
	ft_reader(&head_room);
	ft_printlist(&head_room);
	ft_printlinks(&head_room);
	//sleep(60);
	return (0);
}
