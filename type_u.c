/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:19:58 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/19 01:34:33 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *type_u(t_buffer *b, t_flags *f, unsigned int num, char *str)
{
	f->b_num_zero = (num == 0) ? 1 : 0;
    f->to_write = ft_putnbr_len(b,f, num);
	str = conversion_helper(b, f, str, 'u');
	while (f->zeros-- > 0)
		add_to_buffer(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') : (b->buffer[b->buff_i] = '\0');
	else 
		ft_putnbr(b, f, num);
	if (f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
    return (str);
}
