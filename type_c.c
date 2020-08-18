/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 01:03:29 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/18 21:16:29 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_c(t_buffer *b, t_flags *f, int c, char *str)
{
	if (f->b_left_aligned)
	{
		add_to_buffer(b, f, c);
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
	}
	else
	{
		while (f->width > 1)
			f->b_zero_padding ? add_to_buffer(b, f, '0') : add_to_buffer(b, f, ' ');
		add_to_buffer(b, f, c);
	}
	return (str);
}
