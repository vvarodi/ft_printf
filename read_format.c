/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:20:54 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/19 03:04:23 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_type(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

void	read_flags(t_buffer *b, t_flags *f, char *str, int *i)
{
	while (str[*i] == '0' || str[*i] == '*' || str[*i] == '-')
	{
		if (str[*i] == '*')
		{
			f->width = va_arg(b->args, int);
			(*i)++;
			if (f->width < 0)
			{
				f->width *= -1;
				f->b_left_aligned = 1;
			}
		}
		if (str[*i] == '0')
		{
			f->b_zero_padding = 1;
			(*i)++;
		}
		else if (str[*i] == '-')
		{
			f->b_left_aligned = 1;
			(*i)++;
		}
	}
}

void	width_precision(t_buffer *b, t_flags *f, char *str, int *i)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		f->width = f->width * 10 + str[*i] - '0';
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
		{
			f->b_preci = 1;
			f->precision = va_arg(b->args, int);
			(*i)++;
		}
		if (((ft_is_type(str[*i]) || str[*i] == '0') && f->b_preci == 0)
				|| (ft_is_type(str[*i]) || str[*i] == '0'))
			f->b_preci = 2;
		else
			f->b_preci = 1;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			f->precision = f->precision * 10 + str[*i] - '0';
			(*i)++;
		}
	}
}

char	*placeholders(t_buffer *b, t_flags *f, char *str)
{
	int	i;

	i = 0;
	read_flags(b, f, str, &i);
	width_precision(b, f, str, &i);
	if (ft_is_type(*(str + i)))
		return (str + i);
	else
		return (str - 1);
}

char	*read_format(t_buffer *b, t_flags *f, char *str)
{
	str++;
	str = placeholders(b, f, str);
	if (*str == '%' || *str == 'c')
		str = type_c(b, f, *str == 'c' ? va_arg(b->args, int) : '%', str) + 1;
	else if (*str == 's')
		str = type_s(b, f, va_arg(b->args, char *), str) + 1;
	else if (*str == 'd' || *str == 'i')
		str = type_di1(b, f, va_arg(b->args, int), str) + 1;
	else if (*str == 'u')
		str = type_u(b, f, va_arg(b->args, unsigned int), str) + 1;
	else if (*str == 'x' || *str == 'X')
		str = type_x(b, f, va_arg(b->args, unsigned int), str, *str) + 1;
	else if (*str == 'p')
		str = type_p(b, f, va_arg(b->args, unsigned long int), str) + 1;
	return (str);
}
