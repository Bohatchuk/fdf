/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:16:23 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/22 13:23:46 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ft_error("Usage: ./fdf map_file");
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		ft_error("Malloc error");
	reading_and_creating(fdf, argv[1]);
	ft_twoarraydel((void ***)&(fdf->map), fdf->sy);
	return (0);
}
