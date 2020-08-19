/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:08:27 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/19 09:51:13 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_p(t_buffer *b, t_flags *f, unsigned long int num, char *str)
{
	char type;

	type = 'p';
	f->b_num_zero = (num == 0) ? 1 : 0;
	f->to_write = ft_puthexa_len(b, f, num);
	str = conversion_helper(b, f, str, 'p');
	while (f->zeros-- > 0)
		add_to_buffer(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
		ft_puthexa(b, f, num, &type);
	if (f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
	return (str);
}
