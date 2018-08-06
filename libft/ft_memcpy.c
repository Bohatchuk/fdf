/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:44:34 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/04 18:51:42 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)src;
	s2 = (char *)dst;
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dst);
}
