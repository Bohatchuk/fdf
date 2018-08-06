/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:57:39 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/04 19:55:50 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*res;
	unsigned int	len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(res = (char *)malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		res[len] = s1[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
