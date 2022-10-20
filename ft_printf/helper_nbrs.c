/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:06:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/18 10:29:34 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_write_array(long int n, int size)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	arr[size] = 0;
	while (n != 0)
	{
		arr[--size] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}

char	*ft_uitoa(unsigned int n)
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
	return (printf_write_array((long)n, size));
}