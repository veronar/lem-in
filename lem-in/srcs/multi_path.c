/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:20:24 by vscott            #+#    #+#             */
/*   Updated: 2019/09/16 13:38:08 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_move	**make_moves(char ***path, int *len, int v_path)
{
	t_move	**moves;
	int		i;

	i = -1;
	moves = (t_move**)ft_memalloc(sizeof(t_move*) * (v_path + 2));
	while (++i < v_path + 1)
	{
		moves[i] = make_move(path[i], len[i]);
	}
	moves[i] = NULL;
	return (moves);
}

static int		len_total(int *len)
{
	int	count;

	count = 0;
	while (*len)
		count += *(len++);
	return (count);
}

static void		del_moves(t_move ***moves)
{
	int	i;

	i = 0;
	while ((*moves)[i])
		del_move(&(*moves)[i++]);
	free(*moves);
	*moves = NULL;
}

void			multi_path(char ***path, t_print *print)
{
	t_move	**moves;
	int		turns;

	print->i = 1;
	moves = make_moves(path, print->len, print->n_path);
	turns = turn_amount(print);
	print->len_tot = len_total(print->len);
	while (turns--)
	{
		turn_loop(print, moves);
		put_loop(print, moves);
		if (turns)
			ft_putchar('\n');
	}
	del_moves(&moves);
}
