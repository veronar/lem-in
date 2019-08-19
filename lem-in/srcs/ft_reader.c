/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:15:10 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 09:08:22 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_ants(char **line)
{
	long long ants;

	ants = 0;
	while (*line)
	{
		if (!ft_isdigit(**line))
		{
			free(line);
			ft_error();
		}
	}
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
	int		start;
	int		end;

	end = 0;
	start = 0;
	ants = ft_ants(&line);
	printf("no. of ants: %i\n", ants);
	while (get_next_line(0, &line))
	{
		printf("line = %s\n", line);
		if (ft_do_line(line, &start, &end) == -1)
			ft_error();
		ft_memdel((void **)&line);
	}
	ft_memdel((void**)&line);
	if (start != 1 || end != 1)
		ft_error();
}
