/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:02:25 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/01 11:50:14 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_hex_array(long unsigned int n, int cap)
{
	char	*base;

	if (cap == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		write_hex_array(n / 16, cap);
	ft_putchar_fd(base[n % 16], 1);
}

size_t	ft_size_hex(long unsigned int n)
{
	size_t				size;
	long unsigned int	div;

	div = n;
	size = 0;
	if (n == 0)
		return (1);
	while (div != 0)
	{
		size++;
		div /= 16;
	}
	return (size);
}

size_t	ft_print_x(char c, unsigned int x)
{
	if (c == 'x')
		write_hex_array(x, 0);
	else if (c == 'X')
		write_hex_array(x, 1);
	return (ft_size_hex((long)x));
}

size_t	ft_print_p(unsigned long int p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	ft_putstr_fd("0x", 1);
	write_hex_array(p, 0);
	return (ft_size_hex(p) + 2);
}
