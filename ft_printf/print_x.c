/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:02:25 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/21 11:08:07 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*write_hex_array(long unsigned int n, size_t size, char *arr)
{
	arr[size] = 0;
	if (n == 0)
		arr[0] = '0';
	else
	{
		while (n != 0)
		{	
			arr[--size] = "0123456789abcdef"[n % 16];
			n /= 16;
		}
	}
	return (arr);
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

char	*ft_cap(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		s[i] = ft_toupper(s[i]);
	return (s);
}

size_t	ft_print_x(char c, unsigned int x)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (ft_size_hex(x) + 1));
	arr = write_hex_array(x, ft_size_hex(x), arr);
	if (c == 'x')
		ft_putstr_fd(arr, 1);
	else if (c == 'X')
		ft_putstr_fd(ft_cap(arr), 1);
	free(arr);
	return (ft_size_hex((long)x));
}
