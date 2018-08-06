/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:47:26 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/16 21:53:14 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > i)
		j--;
	str = ft_strnew(j - i + 1);
	if (str == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
