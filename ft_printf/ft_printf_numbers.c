/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:49:11 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/23 11:03:37 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_nbr(char c, ...)
{
	va_list		args;
	long int	i;
	char		*arr;

	va_start(args, c);
	i = va_arg(args, long int);
	arr = (char *)malloc(sizeof(char) * (ft_size(i) + 1));
	arr = write_array(i, ft_size(i), arr);
	ft_putstr_fd(arr, 1);
	free(arr);
	return (ft_size(i));
}

char	*write_array(long int n, int size, char *arr)
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
