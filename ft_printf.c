/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 00:03:38 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/14 02:01:11 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*placeholders(t_flags *f, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0')
	{
		f->b_zero_padding = 1;
		i++;
	}
	else if (str[i] == '-')
	{
		f->b_left_aligned = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		f->width = f->width * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		f->b_precision = 1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			f->precision = f->precision * 10 + str[i] - '0';
			i++;
		}
	}
	return (str + i);
}

char	*read_types(t_buffer *b, t_flags *f, char *str)
{
	str++;
	str = placeholders(f, str);
	if (*str == '%' || *str == 'c')
		str = type_c(b, f, *str == 'c' ? va_arg(b->args, int) : '%', str) + 1;
	else if (*str == 's')
		str = type_s(b, f, va_arg(b->args, char *), str) + 1;
	return (str);
}

int		ft_printf(const char *s, ...)
{
	t_buffer	b;
	t_flags		f;
	char		*string;

	string = (char *)s;
	ft_bzero(&b, sizeof(b));
	va_start(b.args, s);
	while (*string)
	{
		if (*string == '%')
		{
			ft_bzero(&f, sizeof(f));
			string = read_types(&b, &f, string);
		}
		else
			add_to_buffer(&b, &f, *string++);
	}
	write(1, b.buffer, b.buff_i);
	va_end(b.args);
	return (b.buff_i + b.written);
}
