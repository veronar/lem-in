/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:15:10 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/28 13:56:40 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_check_ants: checks that only digits are given as argument for number of
** ants
*/

void		ft_check_ants(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] && ft_isdigit(line[len]))
		len++;
	if (strlen(line) != len)
		ft_error();
}

/*
** ft_ants: checks the first line to be read, if it not digits only, return
** error. If it is only digits, convert it to a long long, and then check
** that it is within INT range.
** no 0 or negatives allowed.
** If there is a comment before the number of ants, it skips them and performs
** the read again on the next line.
*/

int			ft_ants(void)
{
	long long	ants;
	char		*line;

	line = NULL;
	ants = 0;
	get_next_line(0, &line);
	while (line[0] == '#' && line[1] != '#')
	{
		ft_memdel((void **)&line);
		get_next_line(0, &line);
	}
	ft_check_ants(line);
	ants = ft_atoll(line);
	ft_memdel((void**)&line);
	if (ants < 1 || ants > 2147483647)
		ft_error();
	printf("no. of ants: %lli\n", ants);
	return (ants);
}

/*
** ft_reader: reads from standard output
** first line must be number of ants
** then continues to read rest of input to check if it is valid
** as it reads it does ft_do_line to analyse input given.
*/

void		ft_reader(t_room **head_room)
{
	char	*line;
	int		start;
	int		end;

	line = NULL;
	end = 0;
	start = 0;
	while (get_next_line(0, &line))
	{
		if (ft_do_line(head_room, line, &start, &end) == -1)
			ft_error();
		ft_memdel((void **)&line);
	}
	ft_memdel((void**)&line);
	if (start != -1 || end != -1)
		ft_error();
	if (ft_checkdups(head_room) == -1)
	{
		ft_freelists(head_room);
		ft_error();
	}
}
