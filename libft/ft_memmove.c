/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:22:56 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/04 18:52:03 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)src;
	s2 = (char *)dst;
	i = -1;
	if (s2 < s1)
	{
		while (++i < len)
			s2[i] = s1[i];
	}
	else
	{
		while (len-- > 0)
			s2[len] = s1[len];
	}
	return (dst);
}
