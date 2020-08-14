/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 01:13:34 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/14 01:45:42 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_s(t_buffer *b, t_flags *f, char *print, char *str)
{
	int	length;
	int tam;

	tam = ft_strlen(print);

	if (print == NULL)
		print = "(null)";
	if (f->b_left_aligned == 1)
		return (str);
	if (f->precision == 0)
		length = ft_strlen(print);
	else
		length = tam < f->precision ? tam : f->precision;
	while (f->width > length)
		add_to_buffer(b, f, ' ');
	while (length-- > 0)
		add_to_buffer(b, f, *print++);
	return (str);
}
