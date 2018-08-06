/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:20:25 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/11 18:36:41 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	n;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		str[i] = f(n, s[i]);
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}
