/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:53:34 by vscott            #+#    #+#             */
/*   Updated: 2019/09/16 13:37:00 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_path(char ***path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}

static int	room_count(char **path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	return (i - 1);
}

static int	*path_len(char ***path, int n)
{
	int	*len;
	int	i;

	i = 0;
	if (!(len = (int*)ft_memalloc(sizeof(int) * (n + 1))))
		ft_putstr("couldn't malloc for len\n");
	while (i < n)
	{
		len[i] = room_count(path[i]);
		i++;
	}
	return (len);
}

void		del_ant_len(int **arr)
{
	free(*arr);
	*arr = NULL;
}

void		move_ants(char ***path, int n_ant)
{
	t_print	*print;

	print = (t_print*)ft_memalloc(sizeof(t_print));
	print->ant_tot = n_ant;
	print->n_path = count_path(path);
	print->len = path_len(path, print->n_path);
	print->ant = (int*)ft_memalloc(sizeof(int) * (print->n_path + 1));
	if (print->n_path == 1 || n_ant == 1)
		one_path(path[0], n_ant, print->len[0]);
	else
	{
		if (!(print->n_path = num_of_path(n_ant, print->len)))
			one_path(path[0], n_ant, print->len[0]);
		else
		{
			split_ants(print);
			multi_path(path, print);
		}
	}
	del_ant_len(&(print->ant));
	del_ant_len(&(print->len));
	free(print);
	print = NULL;
}
