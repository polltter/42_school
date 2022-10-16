/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:11:08 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 16:11:09 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*write_array(long int n, int size)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	arr[size] = 0;
	if (n == INT_MIN)
	{
		arr[--size] = '8';
		arr[0] = '-';
		n = 214748364;
	}
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		arr[--size] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int			size;
	long int	div;

	div = n;
	size = 0;
	if (n == 0)
		return ("0");
	while (div != 0)
	{
		size++;
		div /= 10;
	}
	if (n < 0)
		size++;
	return (write_array((long)n, size));
}
