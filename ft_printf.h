/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:50:25 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/14 01:46:51 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# define BUFFER_SIZE 256

typedef struct	s_buffer
{
	va_list		args;
	char		buffer[BUFFER_SIZE];
	int			buff_i;
	int			written;
}				t_buffer;

typedef struct	s_flags
{
	int			width;
	int			precision;
	int			b_precision;
	int			b_left_aligned;
	int			b_zero_padding;
}				t_flags;

int				ft_printf(const char *s, ...);

char			*type_s(t_buffer *b, t_flags *f, char *print, char *str);
char			*type_c(t_buffer *b, t_flags *, int c, char *str);

char			*read_types(t_buffer *b, t_flags *f, char *str);
char			*placeholders(t_flags *f, char *str);

void			write_and_clear(t_buffer *b);
void			add_to_buffer(t_buffer *b, t_flags *f, char c);

void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);

#endif





