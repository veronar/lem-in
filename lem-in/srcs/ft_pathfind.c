/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:04:31 by anorman           #+#    #+#             */
/*   Updated: 2019/09/11 12:09:54 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Maxpaths will never be greater than start->links or exit->links
** (could be smaller but its a good starting point to malloc paths)
** returns (0) if there isnt a start and end (uses the first of each otherwise
*/

int		st_maxpaths(t_room *rooms)
{
	int num;
	int i;
	int fnd;

	num = 0;
	while (rooms && rooms->start != 1 && rooms->start != -1)
		rooms = rooms->next;
	fnd = rooms->start;
	i = 0;
	if (!rooms)
		return (0);
	while (rooms->links[i])
		i++;
	num = i;
	rooms = rooms->next;
	while (rooms && rooms->start != fnd * -1)
		rooms = rooms->next;
	i = 0;
	if (!rooms)
		return (0);
	while (rooms->links[i])
		i++;
	if (i < num)
		num = i;
	return (num);
}

/*
** st_findpaths finds the best set of paths, it finds the shortest first
** then using that ("will later") attempts to find better multipaths.
**
** "currently only does the shortest possible path."
*/

void	st_findpaths(char ***paths, t_room *rooms, int ants)
{
	char	**min;
	int		moves;

	min = ft_minpath(rooms);
	moves = ft_ptrarrlen((void **)min) + ants;
	paths[0] = min;
	paths[1] = NULL;
}

/*
** Findpaths returns a 3D array of paths->each_path->roomnames
**
** do maxpaths = st_maxpaths(rooms); when more paths are used
*/

char	***ft_pathfind(t_room *rooms, int ants)
{
	char	***paths;
	int		maxpaths;

	maxpaths = 1;
	if (!(paths = (char ***)malloc(sizeof(char **) * maxpaths + 1)))
	{
		write(2, "Error paths malloc failed\n", 26);
		return (NULL);
	}
	st_findpaths(paths, rooms, ants);
	return (paths);
}

/*
** Prints each path on a new line, for testing
*/

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
