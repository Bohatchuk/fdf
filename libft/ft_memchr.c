/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:32:05 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/04 18:50:59 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*str;
	size_t			i;

	symb = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == symb)
			return (str + i);
		i++;
		n--;
	}
	return (0);
}
