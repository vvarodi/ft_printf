/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:08:27 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/18 22:55:33 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *type_p(t_buffer *b, t_flags *f, unsigned long int num, char *str)
{
    char type;

    type = 'p';
    f->to_write = ft_puthexa_len(b, num);	
    if (f->b_left_aligned == 1 && f->b_zero_padding == 1)
		f->b_zero_padding = 0;
    if ((f->b_preci == 1 || f->b_preci == 2) && f->precision >= f->to_write)
		f->zeros = f->precision - f->to_write;
	else if (f->b_preci == 2 && f->precision == 0 && num == 0)
		f->to_write = 0;
	if (!f->b_left_aligned)
		f->width = f->width - f->to_write - f->zeros - 2; 
	if (f->b_zero_padding == 1 && !f->b_left_aligned && f->b_preci != 1 && f->b_preci != 2)
		while (f->width > 0)
			add_to_buffer(b, f, '0');
	else if (!f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
	while (f->zeros-- > 0)
		add_to_buffer(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') : (b->buffer[b->buff_i] = '\0');
	else 
		ft_puthexa(b, f, num, &type);
	if (f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
    return (str);
}