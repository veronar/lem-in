/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:12:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/20 13:05:27 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

typedef struct		s_link
{
	int				start;
	char			*name;
	int				coord_y;
	int				coord_x;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_room
{
	int				start;
	char			*name;
	int				coord_y;
	int				coord_x;
	struct s_link	*links;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

void				ft_reader(void);
int					ft_do_line(char *str, int *start, int *end);
void				ft_error(void);
void				ft_usage(void);
int					ft_check_split(char *str);
void				ft_free_her(char **arr);
void				ft_link_func(char *str);
void				ft_rooms_func(char **arr);

void				ft_comment(char **str);

#endif
