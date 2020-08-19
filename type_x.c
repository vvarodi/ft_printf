/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 00:00:58 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/19 09:37:39 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_x(t_buffer *b, t_flags *f, unsigned int c, char *str)
{
	char type;

	type = *str;
	f->b_num_zero = (c == 0) ? 1 : 0;
	f->to_write = ft_puthexa_len(b, f, c);
	str = conversion_helper(b, f, str, type);
	while (f->zeros-- > 0)
		add_to_buffer(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && c == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
		ft_puthexa(b, f, c, &type);
	if (f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
	return (str);
}
