/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarodi <vvarodi@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:35:09 by vvarodi           #+#    #+#             */
/*   Updated: 2020/08/19 00:09:52 by vvarodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(t_buffer *b, t_flags *f, long n)
{
	if (n < 0)
		n = -n;
	if (n / 10)
		ft_putnbr(b, f, n / 10);
	add_to_buffer(b, f, n % 10 + '0');
}

int		ft_putnbr_len(t_buffer *b, t_flags *f, long n)
{
	if (n < 0)
		n = -n;
	if (n / 10)
	{
		f->num_len++;
		ft_putnbr_len(b, f, n / 10);
	}
	return (f->num_len + 1);
}

void	ft_puthexa(t_buffer *b, t_flags *f, unsigned long x, char *type)
{
	if (x >= 16)
		ft_puthexa(b, f, x / 16, type);
	if (*type == 'p' && f->b_only_once == 0)
	{
		add_to_buffer(b, f, '0');
		add_to_buffer(b, f, 'x');
		f->b_only_once = 1;
	}
	if (*type == 'x' || *type == 'p')
		add_to_buffer(b, f, "0123456789abcdef"[x & 15]);
	else
		add_to_buffer(b, f, "0123456789ABCDEF"[x & 15]);
}

int		ft_puthexa_len(t_buffer *b, t_flags *f, unsigned long x)
{
	if (x >= 16)
	{
		f->num_len++;
		ft_puthexa_len(b, f, x / 16);
	}
	return (f->num_len + 1);
}
