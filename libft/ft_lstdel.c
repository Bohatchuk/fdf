/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:53:08 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/20 18:56:49 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*buf;

	buf = *alst;
	if (del)
	{
		while (buf)
		{
			tmp = buf->next;
			del(buf->content, buf->content_size);
			free(buf);
			buf = tmp;
		}
		*alst = NULL;
	}
}
