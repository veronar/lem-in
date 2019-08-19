/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:11:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 07:55:44 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void		ft_usage(void)
{
	ft_putendl("Lem-in: requires no arguments");
	exit(1);
}
