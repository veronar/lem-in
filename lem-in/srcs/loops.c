/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:21:40 by vscott            #+#    #+#             */
/*   Updated: 2019/09/19 17:00:45 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			turn_amount(t_print *print)
{
	int	amount;
	int	i;

	i = 0;
	amount = (print->len[0] + print->ant[0]);
	while (print->len[++i])
		if (print->len[i] + print->ant[i] > amount)
			amount = print->len[i] + print->ant[i];
	return (amount);
}

void		turn_loop(t_print *print, t_move **moves)
{
	int	j;

	j = 0;
	while (j <= print->n_path && print->i < print->ant_tot + print->len_tot)
	{
		ant_turn(moves[j], (print->ant[j]-- > 0) ? print->i++ : 0,
				print->len[j]);
		j++;
	}
}

static int	check_move(t_move *move, int len)
{
	while (len--)
		if (move[len].ant)
			return (1);
	return (0);
}

// char		**colours(void)
// {
// 	char	*col[] = {COL_ARRAY};

// 	// col = {COL_ARRAY};
// 	// c = (t_col){{BLACK_RED, BLACK_GREEN, BLACK_YELLOW,
// 	// BLACK_MAG, BLACK_CYAN, BLACK_WHITE, RED_BLACK, RED_GREEN, RED_YELLOW,
// 	// RED_BLUE, RED_CYAN, RED_WHITE, GREEN_BLACK, GREEN_RED,
// 	// GREEN_BLUE, GREEN_MAG, GREEN_WHITE,
// 	// YELLOW_BLACK, YELLOW_RED, YELLOW_BLUE, YELLOW_MAG,
// 	// YELLOW_WHITE, BLUE_RED, BLUE_GREEN, BLUE_YELLOW,
// 	// BLUE_MAG, BLUE_CYAN, BLUE_WHITE, MAG_BLACK, MAG_GREEN,
// 	// MAG_YELLOW, MAG_BLUE, MAG_CYAN, MAG_WHITE, CYAN_BLACK, CYAN_RED,
// 	// CYAN_BLUE, CYAN_MAG, CYAN_WHITE, WHITE_BLACK,
// 	// WHITE_RED, WHITE_GREEN, WHITE_YELLOW, WHITE_BLUE, WHITE_MAG, WHITE_CYAN}};
// 	return (col);
// }

void		put_loop(t_print *print, t_move **moves)
{
	int		j;

	j = 0;
	while (j <= print->n_path)
	{
		put_move(moves[j], print->len[j], 0, j);
		j++;
		ft_putstr(CLEAR);
		if (check_move(moves[j], print->len[j]))
			ft_putchar(' ');
		else
			j++;
	}
}
