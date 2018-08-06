/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:16:10 by dbohatch          #+#    #+#             */
/*   Updated: 2018/01/30 16:13:57 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	char	*dst;
	long	i;
	long	num;
	int		j;

	i = 10;
	num = nbr;
	j = 1;
	if (nbr < 0 && j++)
		num = -num;
	while (num / i > 0 && ++j)
		i *= 10;
	if (!(dst = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	j = 0;
	if (nbr < 0)
		dst[j++] = '-';
	while ((i = i / 10) > 0)
		dst[j++] = (num / i) % 10 + '0';
	dst[j] = '\0';
	return (dst);
}
