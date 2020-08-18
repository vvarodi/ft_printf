/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:22:50 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/18 22:32:24 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *type_di(t_buffer *b, t_flags *f, int num, char *str)
{
	int neg;
	int one_minus;	

    neg = 0;
    one_minus = 0;
	(num < 0) ? (neg = 1) : (neg = 0);
	f->to_write = ft_putnbr_len(b, num) + neg;	
    if (f->b_left_aligned == 1 && f->b_zero_padding == 1)
		f->b_zero_padding = 0;
	if ((f->b_preci == 1 ||f->b_preci == 2) && f->precision >= f->to_write)
		f->zeros = f->precision - f->to_write + neg;
	else if (f->b_preci == 2 && f->precision == 0 && num == 0)
		f->to_write = 0;
	if (!f->b_left_aligned)
		f->width = f->width - f->to_write - f->zeros; 
	if (f->b_zero_padding == 1 && !f->b_left_aligned && f->b_preci != 1&& f->b_preci != 2)
	{
		if (neg == 1 && f->b_zero_padding == 1 && one_minus == 0)
		{
			b->buffer[b->buff_i++] = '-';
			one_minus = 1;
		}
		while (f->width > 0)
			add_to_buffer(b, f, '0');
	}
	else if (!f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');

	if (num < 0 && f->b_zero_padding == 0)
		add_to_buffer(b,f,'-');	
	while (f->zeros-- > 0)
	{
		if (neg == 1 && f->b_zero_padding == 1 && one_minus == 0)
		{
			add_to_buffer(b, f, '-');
			one_minus = 1;
		}
		add_to_buffer(b, f, '0');
	}
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') : (b->buffer[b->buff_i] = '\0');
	else 
	{
		if (neg == 1 && f->b_zero_padding == 1 && one_minus == 0)
			add_to_buffer(b, f, '-');
		ft_putnbr(b, f, num);
	}
	if (f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
	return (str);
}