/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 00:35:31 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/14 00:40:49 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_and_clear(t_buffer *b)
{
	b->written += b->buff_i;
	write(1, b->buffer, BUFFER_SIZE);
	ft_bzero(b->buffer, sizeof(b->buffer));
	b->buff_i = 0;
}

void	add_to_buffer(t_buffer *b, t_flags *f, char c)
{
	if (b->buff_i == BUFFER_SIZE)
		write_and_clear(b);
	b->buffer[b->buff_i] = c;
	b->buff_i++;
	f->width--;
}
