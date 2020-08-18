# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 22:15:55 by vvarodi           #+#    #+#              #
#    Updated: 2020/08/18 12:21:00 by vvarodi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS	= ft_printf.c read_format.c ft_printf_utils.c ft_buffer.c type_s.c \
			type_c.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

$(NAME) : ${OBJS}
	ar rcs ${NAME} ${OBJS} 

all : ${NAME}

debug:
	$(CC) -g -o ft_printf $(SRCS) 
clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
