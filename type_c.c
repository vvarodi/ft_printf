/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 01:03:29 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/14 01:48:50 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_c(t_buffer *b, t_flags *f, int c, char *str)
{
	c == '%' ? add_to_buffer(b, f, '%') : add_to_buffer(b, f, c);
	return (str);
}
