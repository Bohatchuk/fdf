/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:23:23 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/05 21:16:03 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atoi_hex(char *str)
{
	int				i;
	int				j;
	unsigned int	num;
	const char		*arr = "0123456789ABCDEF";

	i = 0;
	num = 0;
	j = -1;
	while (str[i] != ' ' && str[i] != '\0')
	{
		while (arr[++j] != '\0')
		{
			if (ft_toupper(str[i]) == arr[j])
			{
				num = num * 16 + j;
				j = -1;
				break ;
			}
		}
		i++;
	}
	return (num);
}
