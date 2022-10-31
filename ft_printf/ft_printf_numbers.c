/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:49:11 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/31 16:32:26 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_nbr(long int i)
{
	ft_putnbr(i);
	return (ft_size(i));
}

/* char	*write_array(long int n, int size, char *arr)
{
	arr[size] = 0;
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	if (n == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	while (n != 0)
	{
		arr[--size] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
} */

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
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}
