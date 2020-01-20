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

void		ft_error(int ver)
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
	//sleep(60);
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
	//sleep(60);
	return (ret);
}

void		ft_error_exit(int ver)
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
	// sleep(30);
	exit (1) ;
}




/*
** ft_free_linkarr: adaption of ft_free_her (ft_check_split.c) - for t_room**.
** frees all elements in an a pointer array.
** then frees itself.
*/

void	ft_free_linkarr(t_room **arr)
{
	// int	i;

	// i = 0;
	// if (!arr || !*arr)
	if (!arr)
		return ;
	// while (arr[i])
	// {
	// 	// ft_putendl(arr[i]->name);
	// 	ft_memdel((void **)&arr[i]);
	// 	i++;
	// }
	free(arr);
}

/*
** ft_freelists: iterates through 'parent' list, then iterates through
** subsequent list, frees all elements in the sub list, then frees the
** parent node;
** NB frees the names of the list, those were malloced for seperately than
** the actual node. if the name is not freed it will be a leak.
*/

void		ft_freelists(t_room **head)
{
	t_room	*current;
	t_room	*second;

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		// test_here();
		// ft_putendl(current->name);
		ft_free_linkarr((current->links));
		// free(current->links);
		second = current->next;
		free(current->name);
		free(current);
		current = second;
	}
	*head = NULL;
}
