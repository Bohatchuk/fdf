/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:03:56 by dbohatch          #+#    #+#             */
/*   Updated: 2018/01/16 17:52:14 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst			*ft_createlst(t_lst *lst, const int fd)
{
	t_lst	*ptr;

	if (!lst)
	{
		ptr = (t_lst *)malloc(sizeof(t_lst));
		ptr->str = ft_strnew(0);
		ptr->fd = fd;
		lst = ptr;
		lst->next = lst;
	}
	else
	{
		ptr = ft_createlst(NULL, fd);
		ptr->next = lst->next;
		lst->next = ptr;
		lst = ptr;
	}
	return (lst);
}

static int		read_line(t_lst *lst, char **line, const int fd)
{
	int				n;
	char			*tmp;
	unsigned int	start;

	tmp = lst->str;
	start = ft_strlen_to_symb(lst->str, '\n');
	if (lst->str[start] == '\n')
		lst->str = ft_strsub(lst->str, start + 1,
			ft_strlen(&lst->str[start + 1]));
	else
		lst->str = ft_strsub(lst->str, start, ft_strlen(&lst->str[start]));
	ft_strdel(&tmp);
	while ((n = read(fd, *line, BUFF_SIZE)) && (n != -1))
	{
		(*line)[n] = '\0';
		tmp = lst->str;
		lst->str = ft_strjoin(lst->str, *line);
		ft_strclr(tmp);
		free(tmp);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	return (n);
}

int				get_next_line(const int fd, char **line)
{
	int				n;
	char			*tmp;
	static t_lst	*lst;
	int				temp;

	if (!line || !(*line = ft_strnew(BUFF_SIZE)) || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (lst)
	{
		temp = lst->fd;
		while ((lst->next)->fd != temp && lst->fd != fd)
			lst = lst->next;
	}
	if (!lst || lst->fd != fd)
		lst = ft_createlst(lst, fd);
	if ((n = read_line(lst, line, fd)) == -1)
		return (-1);
	tmp = *line;
	*line = ft_strsub(lst->str, 0, ft_strlen_to_symb(lst->str, '\n'));
	ft_strdel(&tmp);
	if (!((lst->str)[0]) && !(n))
		return (0);
	return (1);
}
