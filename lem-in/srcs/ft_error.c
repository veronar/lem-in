/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:11:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/20 13:17:24 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ft_error: error on standard error
*/

void		ft_error(void)
{
	ft_putendl_fd("ERROR", 2);
	//sleep(60);
	exit(1);
}

/*
** ft_usage: if incorrect usage of lem-in results.
*/

void		ft_usage(void)
{
	ft_putendl("Lem-in: requires no arguments");
	exit(1);
}
