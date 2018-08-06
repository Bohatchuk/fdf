/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:41:59 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/22 13:29:06 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_fdf *fdf, float n)
{
	int		i;
	int		j;
	double	tmp;

	i = -1;
	while (++i < fdf->sy)
	{
		j = -1;
		while (++j < fdf->sx)
		{
			tmp = fdf->map[i][j].y - fdf->c_y;
			fdf->map[i][j].y =
				tmp * cos(n) + fdf->map[i][j].z * sin(n) + fdf->c_y;
			fdf->map[i][j].z = -(tmp * sin(n)) + fdf->map[i][j].z * cos(n);
		}
	}
}

void	rotation_y(t_fdf *fdf, float n)
{
	int		i;
	int		j;
	double	tmp;

	i = -1;
	while (++i < fdf->sy)
	{
		j = -1;
		while (++j < fdf->sx)
		{
			tmp = fdf->map[i][j].x - fdf->c_x;
			fdf->map[i][j].x =
				tmp * cos(n) - fdf->map[i][j].z * sin(n) + fdf->c_x;
			fdf->map[i][j].z = tmp * sin(n) + fdf->map[i][j].z * cos(n);
		}
	}
}

void	rotation_z(t_fdf *fdf, float n)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	i = -1;
	while (++i < fdf->sy)
	{
		j = -1;
		while (++j < fdf->sx)
		{
			tmp_x = fdf->map[i][j].x - fdf->c_x;
			tmp_y = fdf->map[i][j].y - fdf->c_y;
			fdf->map[i][j].x = tmp_x * cos(n) + tmp_y * sin(n) + fdf->c_x;
			fdf->map[i][j].y = -(tmp_x * sin(n)) + tmp_y * cos(n) + fdf->c_y;
		}
	}
}
