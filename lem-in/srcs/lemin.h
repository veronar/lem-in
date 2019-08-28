/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:12:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/28 14:17:27 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

typedef struct		s_link
{
	int				start;
	char			*name;
	int				y;
	int				x;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_room
{
	int				start;
	char			*name;
	int				y;
	int				x;
	struct s_link	*links;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

void				ft_reader(t_room **head_room);
int					ft_ants(void);
int					ft_do_line(t_room **head_room, char *str, int *start,\
					int *end);
void				ft_error(void);
void				ft_usage(void);
int					ft_check_split(t_room **head_room, char *str,\
					int *start, int *end);
void				ft_free_her(char **arr);
void				ft_link_func(t_room **head_room, char *str);
int					ft_rooms_func(t_room **head_room, char **arr,\
					int *start, int *end);
int					ft_check_coords(char **arr);
void				ft_command(t_room **current, int *start, int *end);
t_room				*ft_newnode(void);
t_room				*ft_listadd(t_room **head_room);
void				ft_list_del(t_room **head);
t_link				*ft_newlink(void);
t_link				*ft_linkadd(t_link **head_link);
void				ft_linkinfo(t_room **head, t_link **clink);
void				ft_freelists(t_room **head);
int					ft_checkdups(t_room **head);
int					ft_dupnames(t_room **head);
int					ft_dupcoords(t_room **head);

void				ft_comment(char **str);
void				ft_printlist(t_room **head);
void				ft_printlinks(t_room **head);
void				ft_check_ants(char *line);

#endif
