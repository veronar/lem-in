/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:39:47 by vscott            #+#    #+#             */
/*   Updated: 2019/09/16 13:39:54 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	split_ants(t_print *print)
{
	int i;
	int	n;

	n = print->ant_tot;
	i = 0;
	while (i < print->n_path)
	{
		while (print->ant[i] + print->len[i] < print->len[print->n_path])
		{
			print->ant[i]++;
			n--;
		}
		i++;
	}
	i = 0;
	while (n--)
	{
		print->ant[i++]++;
		if (i > print->n_path)
			i = 0;
	}
}
