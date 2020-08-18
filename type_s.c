/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 01:13:34 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/19 00:30:12 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_s_left(t_buffer *b, t_flags *f, char *print, char *str)
{
	if (f->b_preci == 0)
	{
		while (*print != '\0')
			add_to_buffer(b, f, *print++);
	}
	else
	{
		if (f->precision < 0)
		{
			while (*print && f->precision++ < 0)
				add_to_buffer(b, f, *print++);
		}
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
	int length;

	if (print == NULL)
		print = "(null)";
	length = ft_strlen(print);
	if (f->b_left_aligned == 1)
		return (type_s_left(b, f, print, str));
	if (f->precision == 0)
	{
		f->to_write = ft_strlen(print);
		if (f->b_preci == 2)
			f->to_write = 0;
	}
	else if (f->precision < 0)
		f->to_write = length;
	else
		f->to_write = length < f->precision ? length : f->precision;
	while (f->width > f->to_write)
		f->b_zero_padding == 1 ? add_to_buffer(b, f, '0') :
			add_to_buffer(b, f, ' ');
	while (f->to_write-- > 0)
		add_to_buffer(b, f, *print++);
	return (str);
}
