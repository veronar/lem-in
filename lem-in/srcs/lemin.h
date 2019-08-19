/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:12:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/19 09:08:40 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# include <stdio.h>

void		ft_reader();
int		ft_do_line(char *str, int *start, int *end);
void		ft_error(void);
void		ft_usage(void);

void		ft_comment(char **str);

#endif