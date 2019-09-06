/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:29:52 by anorman           #+#    #+#             */
/*   Updated: 2019/09/06 09:07:32 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ptrarrlen(void **arr)
{
	int i;

	i = 0;
	if (arr)
	{
		while (*arr)
		{
			i++;
			arr++;
		}
	}
	return (i);
}

/*
** Counts up to null, hopefully any pointer array (**+) can be cast to (void **)
** Such is plausiable since pointers are (always?) 8bytes
*/
