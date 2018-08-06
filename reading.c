/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:07:49 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/22 13:25:33 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		**parsing_xzcolor(t_fdf *fdf, t_line *list, int iy)
{
	int i;
	int	ix;

	i = 0;
	ix = -1;
	while ((list->data)[i])
	{
		while ((list->data)[i] && (list->data)[i] == ' ')
			i++;
		if (!((list->data)[i]))
			break ;
		(fdf->map)[iy][++ix].y = iy;
		(fdf->map)[iy][ix].x = ix;
		(fdf->map)[iy][ix].z = ft_atoi((list->data) + i);
		while ((list->data)[i] && (list->data)[i] != ' ' &&
			(list->data[i]) != ',')
			i++;
		if ((list->data)[i] && (list->data)[i] == ',')
			fdf->map[iy][ix].c = ft_atoi_hex((list->data) + ++i + 2);
		else
			fdf->map[iy][ix].c = ft_atoi_hex("FFFFFF");
		while ((list->data)[i] && (list->data)[i] != ' ')
			i++;
	}
	return (fdf->map);
}

t_coord		**creating_and_parsing(t_fdf *fdf, t_line *list)
{
	int		ix;
	int		iy;

	ix = 0;
	iy = 0;
	while (list)
	{
		ix = ft_countwords(list->data, ' ');
		fdf->sx = ix;
		if (!((fdf->map)[iy] = (t_coord *)ft_memalloc(sizeof(t_coord) * ix)))
		{
			ft_memdel((void **)&((fdf->map)[iy]));
			ft_error("Malloc error");
		}
		fdf->map = parsing_xzcolor(fdf, list, iy);
		iy++;
		list = list->next;
	}
	return (fdf->map);
}

int			opening(t_fdf *fdf, char *file)
{
	fdf->fd = open(file, O_RDONLY);
	if (fdf->fd == -1)
	{
		perror("Error");
		exit(1);
	}
	return (fdf->fd);
}

void		reading_and_creating(t_fdf *fdf, char *file)
{
	int		iy;
	int		gnl;
	char	*line;
	t_line	*list;

	list = NULL;
	iy = 0;
	gnl = 0;
	fdf->fd = opening(fdf, file);
	while ((gnl = get_next_line(fdf->fd, &line)) > 0 && ++iy)
		ft_lineinlist(&list, line);
	if (gnl == -1)
		ft_error("Usage: ./fdf map_file");
	fdf->sy = iy;
	close(fdf->fd);
	validation(list);
	if (!(fdf->map = (t_coord **)ft_memalloc(sizeof(t_coord *) * iy)))
	{
		ft_twoarraydel((void ***)&(fdf->map), iy);
		ft_error("Malloc error");
	}
	fdf->map = creating_and_parsing(fdf, list);
	ft_freelist(&list);
	create_image(fdf);
}
