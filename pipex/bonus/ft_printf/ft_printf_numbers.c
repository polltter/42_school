/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:49:11 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/14 13:02:10 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_nbr(long int i)
{
	ft_putnbr(i);
	return (ft_size(i));
}

size_t	ft_size(long int n)
{
	int			size;
	long int	div;
	int			size_sign;

	size_sign = 0;
	div = n;
	size = 0;
	if (n < 0)
	{
		n *= -1;
		size_sign = 1;
	}
	if (n == 0)
		return (1);
	while (div != 0)
	{
		size++;
		div /= 10;
	}
	return (size + size_sign);
}

void	ft_putnbr(long int n)
{
	if (n < 0)
	{
		print_char('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	print_char(n % 10 + '0');
}
