/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:46:48 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/22 12:58:18 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_fdf(void)
{
	exit(0);
}

void	valide_symbols(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == ',' ||
			(str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' &&
				str[i] <= 'f') || str[i] == '-' || str[i] == 'x')
			i++;
		else
			ft_error("Map error");
	}
}

void	validation(t_line *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (list->next)
	{
		i = ft_countwords(list->data, ' ');
		j = ft_countwords(list->next->data, ' ');
		if (j != i)
			ft_error("Map error");
		valide_symbols(list->data);
		list = list->next;
	}
}
