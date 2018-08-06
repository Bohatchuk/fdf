/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:17:08 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/08 15:06:13 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define W 1000
# define H 1000

typedef struct	s_line
{
	struct s_line	*next;
	char			*data;
}				t_line;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
	long int	c;
}				t_coord;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_coord	**map;
	int		fd;
	double	sx;
	double	sy;
	double	zoom;
	double	c_x;
	double	c_y;
}				t_fdf;

/*
**	functions from draw.c
*/
void			create_image(t_fdf *fdf);
void			zoom_center_image(t_fdf *fdf);
void			draw_image(t_fdf *fdf);
void			draw_line(t_fdf *fdf, t_coord d0, t_coord d1);
/*
**	functions from functions.c
*/
void			validation(t_line *list);
void			valide_symbols(char *str);
int				exit_fdf(void);
/*
**	functions from key_hooks.c
*/
int				key_hooks(int key, t_fdf *fdf);
void			keys_move(int key, t_fdf *fdf);
void			change_center_point(int key, t_fdf *fdf);
void			keys_rotate(int key, t_fdf *fdf);
void			keys_scale(int key, t_fdf *fdf);
/*
**	functions from reading.c
*/
void			reading_and_creating(t_fdf *fdf, char *file);
int				opening(t_fdf *fdf, char *file);
t_coord			**creating_and_parsing(t_fdf *fdf, t_line *list);
t_coord			**parsing_xzcolor(t_fdf *fdf, t_line *list, int iy);
/*
**	functions from rotation.c
*/
void			rotation_x(t_fdf *fdf, float n);
void			rotation_y(t_fdf *fdf, float n);
void			rotation_z(t_fdf *fdf, float n);
/*
**	functions from workwithlist
*/
void			ft_lineinlist(t_line **begin, void *data);
void			ft_freelist(t_line **begin);

#endif
