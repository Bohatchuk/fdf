/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workwithlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:17:56 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/22 13:29:26 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lineinlist(t_line **begin, void *data)
{
	t_line	*new_line;
	t_line	*current;

	current = *begin;
	if (!(new_line = (t_line *)malloc(sizeof(t_line))))
		return ;
	new_line->data = data;
	new_line->next = NULL;
	if (!(current))
		*begin = new_line;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_line;
	}
}

void	ft_freelist(t_line **begin)
{
	t_line	*tmp;

	while (*begin)
	{
		free((*begin)->data);
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
}
