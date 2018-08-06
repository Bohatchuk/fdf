/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:01:51 by dbohatch          #+#    #+#             */
/*   Updated: 2018/02/02 18:33:44 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 32

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*str;
	int				fd;
}					t_lst;

int					get_next_line(const int fd, char **line);
t_lst				*ft_createlst(t_lst *lst, const int fd);

#endif
