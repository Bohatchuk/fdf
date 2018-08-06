/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:41:51 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/04 18:50:37 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *sc, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	symb = (unsigned char)c;
	s1 = (unsigned char *)sc;
	s2 = (unsigned char *)dst;
	i = 0;
	while (n > 0)
	{
		if (s1[i] == symb)
		{
			s2[i] = s1[i];
			return (dst + i + 1);
		}
		else
			s2[i] = s1[i];
		i++;
		n--;
	}
	return (0);
}
