/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 01:13:34 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/15 19:47:53 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_s_left(t_buffer *b, t_flags *f, char *print, char *str)
{
	if (f->b_precision == 0)
	{
		while (*print != '\0')
			add_to_buffer(b, f, *print++);
	}
	else
	{
		while (*print && f->precision-- > 0)
			add_to_buffer(b, f, *print++);
	}
	while (f->width > 0)
		f->b_zero_padding == 1 ? add_to_buffer(b, f, '0') :
			add_to_buffer(b, f, ' ');
	return (str);
}

char	*type_s(t_buffer *b, t_flags *f, char *print, char *str)
{
	int	length;
	int tam;

	if (print == NULL)
		print = "(null)";
	tam = ft_strlen(print);
	if (f->b_left_aligned == 1)
		return (type_s_left(b, f, print, str));
	if (f->precision == 0)
	{
		length = ft_strlen(print);
		if (f->b_precision == 2)
			length = 0;
	}
	else if (f->precision < 0)
		length = tam;
	else
		length = tam < f->precision ? tam : f->precision;
	while (f->width > length)
		f->b_zero_padding == 1 ? add_to_buffer(b, f, '0') :
			add_to_buffer(b, f, ' ');
	while (length-- > 0)
		add_to_buffer(b, f, *print++);
	return (str);
}
