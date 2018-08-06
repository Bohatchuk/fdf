/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:38:32 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/22 13:09:45 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keys_scale(int key, t_fdf *f)
{
	int i;
	int j;

	i = -1;
	while (++i < f->sy)
	{
		j = -1;
		while (++j < f->sx)
		{
			if (key == 69)
			{
				f->map[i][j].x = (f->map[i][j].x - f->c_x) * 1.2 + f->c_x;
				f->map[i][j].y = (f->map[i][j].y - f->c_y) * 1.2 + f->c_y;
				f->map[i][j].z = f->map[i][j].z * 1.2;
			}
			if (key == 78)
			{
				f->map[i][j].x = (f->map[i][j].x - f->c_x) / 1.2 + f->c_x;
				f->map[i][j].y = (f->map[i][j].y - f->c_y) / 1.2 + f->c_y;
				f->map[i][j].z = f->map[i][j].z / 1.2;
			}
		}
	}
}

void	keys_rotate(int key, t_fdf *fdf)
{
	float	a;
	float	b;

	a = 0.1;
	b = -0.1;
	if (key == 12)
		rotation_x(fdf, a);
	else if (key == 13)
		rotation_x(fdf, b);
	if (key == 0)
		rotation_y(fdf, a);
	else if (key == 1)
		rotation_y(fdf, b);
	if (key == 6)
		rotation_z(fdf, a);
	else if (key == 7)
		rotation_z(fdf, b);
}

void	change_center_point(int key, t_fdf *fdf)
{
	if (key == 123)
		fdf->c_x -= 10;
	if (key == 124)
		fdf->c_x += 10;
	if (key == 126)
		fdf->c_y -= 10;
	if (key == 125)
		fdf->c_y += 10;
}

void	keys_move(int key, t_fdf *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->sy)
	{
		j = -1;
		while (++j < fdf->sx)
		{
			if (key == 123)
				fdf->map[i][j].x -= 10;
			if (key == 124)
				fdf->map[i][j].x += 10;
			if (key == 126)
				fdf->map[i][j].y -= 10;
			if (key == 125)
				fdf->map[i][j].y += 10;
		}
	}
	change_center_point(key, fdf);
}

int		key_hooks(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
		exit_fdf();
	keys_move(key, fdf);
	keys_rotate(key, fdf);
	keys_scale(key, fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_image(fdf);
	return (0);
}
