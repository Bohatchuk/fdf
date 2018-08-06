/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_to_symb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:50:11 by dbohatch          #+#    #+#             */
/*   Updated: 2018/01/06 22:03:27 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_to_symb(const char *str, int symb)
{
	size_t			len;
	unsigned char	c;

	len = 0;
	c = (unsigned char)symb;
	while (!(str[len] == c) && str[len] != '\0')
		len++;
	return (len);
}
