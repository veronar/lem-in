/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:04:33 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/30 17:16:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	int		ants;
	t_room	*head_room;

	(void)av;
	if (ac > 1)
		ft_error();
	head_room = NULL;
	ants = ft_ants();
	printf("ants = %i\n", ants);
	ft_reader(&head_room);
	//ft_printlist(&head_room);
	//ft_printlinks(&head_room);
	//sleep(60);
	return (0);
}
