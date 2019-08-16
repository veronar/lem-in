/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:15:10 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/16 12:05:46 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_ants(char **line)
{
	int ants;
	
	ants = 0;
	while (*line)
	{
		if (!ft_isdigit(**line))
		{
			free(line);
			ft_error();
		}
	}
	ants = 0;
	get_next_line(0, line);
	ants = ft_atoll(*line);
	if (ants < 1 || ants > 2147483647)
		ft_error();
	return (ants);
}

void		ft_reader(void)
{
	char	*line;
	int		ants;

	ants = ft_ants(&line);
	/*get_next_line(0, &line);
	ants = ft_atoi(line);
	free(line);
	if (ants < 1)
		ft_error();*/
	printf("no. of ants: %i\n", ants);
	while (get_next_line(0, &line))
	{
		printf("line = %s\n", line);
		if (ft_do_line(line) == -1)
			ft_error();
		ft_memdel((void **)&line);
	}
	ft_memdel((void**)&line);
}
