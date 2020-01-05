/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_of_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:38:43 by vscott            #+#    #+#             */
/*   Updated: 2019/09/19 16:56:37 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	change_col(int i)
{
	char	*p[] = {COL_ARRAY};

	// p = {COL_ARRAY};
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
