/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:16:36 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/09 20:56:03 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *s1;
	char *s2;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			s1 = (char *)haystack;
			s2 = (char *)needle;
			while (*s1 && *s2 && (!(*s2 - *s1)))
			{
				s2++;
				s1++;
			}
			if (!*s2)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
