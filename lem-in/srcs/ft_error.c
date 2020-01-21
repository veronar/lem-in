/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:11:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/13 16:52:14 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_error: error on standard error
*/

void	ft_error(int ver)
{
	if (ver == 1)
		ft_putendl_fd("ERROR Invalid input", 2);
	else if (ver == 2)
		ft_putendl_fd("ERROR No valid path", 2);
	else if (ver == 3)
		ft_putendl_fd("ERROR Invalid ant quantity", 2);
	else if (ver == 4)
		ft_putendl_fd("ERROR malloc failed", 2);
	else if (ver == 5)
		ft_putendl_fd("ERROR duplicate room co-ordinates", 2);
	else if (ver == 6)
		ft_putendl_fd("ERROR room linking failed", 2);
	else if (ver == 8)
		ft_putendl_fd("ERROR something strange happened", 2);
	return ;
}

int		ft_error_ret(int ver, int ret)
{
	if (ver == 1)
		ft_putendl_fd("ERROR Invalid input", 2);
	else if (ver == 2)
		ft_putendl_fd("ERROR No valid path", 2);
	else if (ver == 3)
		ft_putendl_fd("ERROR Invalid ant quantity", 2);
	else if (ver == 4)
		ft_putendl_fd("ERROR malloc failed", 2);
	else if (ver == 5)
		ft_putendl_fd("ERROR duplicate room co-ordinates", 2);
	else if (ver == 6)
		ft_putendl_fd("ERROR room linking failed", 2);
	else if (ver == 8)
		ft_putendl_fd("ERROR something strange happened", 2);
	return (ret);
}

void	ft_error_exit(int ver)
{
	if (ver == 1)
		ft_putendl_fd("ERROR Invalid input", 2);
	else if (ver == 2)
		ft_putendl_fd("ERROR No valid path", 2);
	else if (ver == 3)
		ft_putendl_fd("ERROR Invalid ant quantity", 2);
	else if (ver == 4)
		ft_putendl_fd("ERROR malloc failed", 2);
	else if (ver == 5)
		ft_putendl_fd("ERROR duplicate room co-ordinates", 2);
	else if (ver == 6)
		ft_putendl_fd("ERROR room linking failed", 2);
	else if (ver == 8)
		ft_putendl_fd("ERROR something strange happened", 2);
	exit(1);
}
