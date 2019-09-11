/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:04:31 by anorman           #+#    #+#             */
/*   Updated: 2019/09/11 11:45:45 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Maxpaths will never be greater than start->links or exit->links
** (could be smaller but its a good starting point to malloc paths)
** "depends on exactly 1 start, 1 exit"
*/

int		st_maxpaths(t_room *rooms)
{
	int num;
	int i;

	num = 0;
	while (rooms->start != 1 && rooms->start != -1)
		rooms = rooms->next; //find start or exit
	i = 0;
	while (rooms->links[i])
		i++; //count links
	num = i; //set
	rooms = rooms->next; //move on
	while (rooms->start != 1 && rooms->start != -1)
		rooms = rooms->next; //find other start/exit
	i = 0;
	while (rooms->links[i])
		i++; //count links
	if (i < num) //we want the smaller one
		num = i;
	return (num); //return the smaller one
}

/*
** st_findpaths finds the best set of paths, it finds the shortest first
** then using that attempts to find better multipaths.
*/

void	st_findpaths(char ***paths, t_room *rooms, int ants)
{
	char	**min;
	int		moves;

	min = ft_minpath(rooms);
	moves = ft_ptrarrlen((void **)min) + ants;

	paths[0] = min; //for now;
	paths[1] = NULL;
}

/*
** Findpaths returns a 3D array of paths->each_path->roomnames
*/

char	***ft_pathfind(t_room *rooms, int ants)
{
	char	***paths;
	int		maxpaths;

	maxpaths = st_maxpaths(rooms); //finds max potential paths
	if (!(paths = (char ***)malloc(sizeof(char **) * maxpaths + 1)))
	{
		write(2, "Error paths malloc failed\n", 26); 
		return (NULL);
	}
	st_findpaths(paths, rooms, ants);
	return (paths);
}

void	ft_printpath(char ***paths)
{
	int i;
	int k;

	k = 0;
	while (paths[k])
	{
		i = 0;
		printf("path %d\n", k);
		while (paths[k][i] && paths[k][i + 1])
			printf("%s to ", paths[k][i++]);
		printf("%s", paths[k][i]);
		printf("\n");
		k++;
	}
}

/*
** Prints each path on a new line, for testing
*/
