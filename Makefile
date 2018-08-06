# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 17:15:28 by dbohatch          #+#    #+#              #
#    Updated: 2018/02/22 17:15:30 by dbohatch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

FRAM = -lmlx -framework OpenGL -framework AppKit

SRCS =	draw.c \
		functions.c \
		key_hooks.c \
		main.c \
		reading.c \
		rotation.c \
		workwithlist.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft/

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(FRAM) $(SRCS) $(LIBFT) -o $(NAME)

.c.o.:
	$(CC) $(FLAGS) $(FRAM) -c $< -o $@

clean:
	/bin/rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all