/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_of_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:38:43 by vscott            #+#    #+#             */
/*   Updated: 2020/01/21 14:26:03 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	change_col(int i)
{
	static char **p;

	if (!p)
		p = ft_strsplit(C0 C1 C2 C3 C4 C5 C6 C7 C8 C9, ',');
	ft_putstr(p[(i - 1) % 46]);
}

int		num_of_path(int n, int *len)
{
	int splits;
	int i;

	i = 1;
	splits = 0;
	if ((n - i) + len[0] >= i + len[1])
	{
		while ((n - i) + len[0] >= i + len[1])
			i++;
		splits++;
	}
	if (len[2])
		splits += num_of_path(i - 1, len + 1);
	return (splits);
}
