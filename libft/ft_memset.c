/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:19:42 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/06 16:15:55 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	symb;
	char			*str;
	size_t			i;

	symb = (unsigned char)c;
	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = symb;
		i++;
	}
	return (b);
}
