/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:27:08 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/06 17:57:18 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	symb;
	size_t			len;

	symb = (unsigned char)c;
	len = ft_strlen(s);
	while (len > 0 && s[len] != symb)
		len--;
	if (s[len] == symb)
		return ((char *)&s[len]);
	else
		return (NULL);
}
