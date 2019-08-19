/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:15:10 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 17:37:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_ants: checks the first line to be read, if it not digits only, return
** error. If it is only digits, convert it to a long long, and then check
** that it is within INT range.
** no 0 or negatives allowed.
*/

int			ft_ants(char **line)
{
	long long ants;

	ants = 0;
	/*while (*line)
	{
		if (!ft_isdigit(**line))
		{
			free(line);
			ft_error();
		}
	}*/
	get_next_line(0, line);
	//ft_putendl(*line);
	ants = ft_atoll(*line);
	//ft_putnbr(ants);
	//ft_putendl("");
	if (ants < 1 || ants > 2147483647)
		ft_error();
	return (ants);
}

/*
** ft_reader: reads from standard output
** first line must be number of ants
** then continues to read rest of input to check if it is valid
** as it reads it does ft_do_line to analyse input given.
*/

void		ft_reader(void)
{
	char	*line;
	int		ants;
	int		start;
	int		end;

	line = NULL;
	end = 0;
	start = 0;
	ants = ft_ants(&line);
	ft_memdel((void**)&line);
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
