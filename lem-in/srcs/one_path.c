/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:17:43 by vscott            #+#    #+#             */
/*   Updated: 2019/09/19 16:57:48 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	put_move(t_move *move, int len, int one, int j)
{
	int	i;

	i = 0;
	while (len--)
	{
		if (move[len].ant)
		{
			if (i++)
			{
				if (!one)
					ft_putstr(CLEAR);
				ft_putchar(' ');
			}
			change_col((one) ? move[len].ant : j + 1);
			ft_putchar('L');
			ft_putnbr((move[len]).ant);
			ft_putchar('-');
			ft_putstr((move[len]).room);
			if (one)
				ft_putstr(CLEAR);
		}
	}
}

void	del_move(t_move **move)
{
	free(*move);
	*move = NULL;
}

t_move	*make_move(char **path, int len)
{
	int		i;
	t_move	*move;

	i = 0;
	move = (t_move*)ft_memalloc(sizeof(t_move) * len + 1);
	while (i < len)
	{
		(move[i]).room = path[i + 1];
		(move[i++]).ant = 0;
	}
	move[i].room = NULL;
	return (move);
}

void	ant_turn(t_move *move, int i, int len)
{
	while (len)
	{
		move[len].ant = move[len - 1].ant;
		len--;
	}
	move[0].ant = i;
}

void	one_path(char **path, int n_ant, int len)
{
	t_move	*move;
	int		i;

	i = 1;
	move = make_move(path, len);
	while (i < n_ant + len)
	{
		ant_turn(move, (i <= n_ant) ? i : 0, len);
		put_move(move, len, 1, 0);
		ft_putchar('\n');
		i++;
	}
	del_move(&move);
}
