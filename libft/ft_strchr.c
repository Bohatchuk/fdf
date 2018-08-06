/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:03:29 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/06 17:24:53 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	symb;

	symb = (unsigned char)c;
	while (*s != symb)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}
