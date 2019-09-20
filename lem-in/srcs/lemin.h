/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:12:24 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/20 13:01:25 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# include "colours.h"

typedef struct		s_room
{
	int				start;
	char			*name;
	int				y;
	int				x;
	int				len;
	struct s_room	**links;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct	s_move
{
	char		*room;
	int			ant;
}				t_move;

typedef struct	s_print
{
	int			i;
	int			len_tot;
	int			n_path;
	int			ant_tot;
	int			*ant;
	int			*len;
}				t_print;

void				ft_reader(t_room **head_room);
int					ft_ants(void);
int					ft_do_line(t_room **head_room, char *str, int *start,\
					int *end);
void				ft_error(int ver);
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
void				ft_freelists(t_room **head);
int					ft_checkdups(t_room **head);
int					ft_dupnames(t_room **head);
int					ft_dupcoords(t_room **head);
void				ft_free_linkarr(t_room **arr);
void				ft_linkinfo(t_room ***temp, t_room ***new, \
					t_room **pointer, int size);
int					ft_linkarr(t_room **current, t_room **pointer);

void				ft_comment(char **str);
void				ft_printlist(t_room **head);
void				ft_printlinks(t_room **head);
void				ft_check_ants(char *line);

char				**ft_path(t_room *room);
char				**ft_excl_path(t_room *room);
char				**ft_minpath(t_room *room);
char				***ft_pathfind(t_room *room, int ants);
void				ft_printpath(char ***paths);

void				move_ants(char ***path, int n_ant);

void				split_ants(t_print *print);

int					num_of_path(int n, int *len);
void				change_col(int i);

void				one_path(char **path, int n, int len);
t_move				*make_move(char **path, int len);
void				ant_turn(t_move *move, int i, int len);
void				put_move(t_move *move, int len, int one, int j);
void				del_move(t_move **move);
void				multi_path(char ***path, t_print *print);

void				turn_loop(t_print *print, t_move **moves);
void				put_loop(t_print *print, t_move **moves);
int					turn_amount(t_print *print);
t_col				colours(void);

#endif
