/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:31:29 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/22 12:43:25 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf, t_coord d0, t_coord d1)
{
	float	x;
	float	y;

	x = d0.x;
	y = d0.y;
	if (fabs(d1.y - d0.y) > fabs(d1.x - d0.x))
	{
		while ((d0.y < d1.y) ? (y <= d1.y) : (y >= d1.y))
		{
			x = (((y - d0.y) / (d1.y - d0.y)) * (d1.x - d0.x) + d0.x);
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, d0.c);
			(d0.y < d1.y) ? y++ : y--;
		}
	}
	else
	{
		while ((d0.x < d1.x) ? (x <= d1.x) : (x >= d1.x))
		{
			y = (((x - d0.x) / (d1.x - d0.x)) * (d1.y - d0.y) + d0.y);
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, d0.c);
			(d0.x < d1.x) ? x++ : x--;
		}
	}
}

void	draw_image(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->sy)
	{
		j = 0;
		while (j < fdf->sx)
		{
			if ((j + 1) < fdf->sx)
				draw_line(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
			if ((i + 1) < fdf->sy)
				draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	zoom_center_image(t_fdf *fdf)
{
	int i;
	int j;

	if (fmaxf(fdf->sx, fdf->sy) == fdf->sx)
		fdf->zoom = W / fdf->sx;
	else
		fdf->zoom = H / fdf->sy;
	i = 0;
	while (i < fdf->sy)
	{
		j = 0;
		while (j < fdf->sx)
		{
			fdf->map[i][j].x =
				(fdf->map[i][j].x - (fdf->sx - 1) / 2) * fdf->zoom + W / 2;
			fdf->map[i][j].y =
				(fdf->map[i][j].y - (fdf->sy - 1) / 2) * fdf->zoom + H / 2;
			fdf->map[i][j].z = fdf->map[i][j].z * fdf->zoom;
			j++;
		}
		i++;
	}
	fdf->c_x = W / 2;
	fdf->c_y = H / 2;
}

void	create_image(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, W, H, "Dbohatch's FdF");
	zoom_center_image(fdf);
	draw_image(fdf);
	mlx_hook(fdf->win, 2, 1L << 1, key_hooks, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, exit_fdf, fdf);
	mlx_loop(fdf->mlx);
}
