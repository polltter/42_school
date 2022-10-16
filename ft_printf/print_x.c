/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:02:25 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/16 12:33:24 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*write_hex_array(long unsigned int n, int size)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	arr[size] = 0;
	while (n != 0)
	{
		arr[--size] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (arr);
}

char	*ft_uitoa_hex(long unsigned int n)
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
		div /= 16;
	}
	return (write_hex_array(n, size));
}

char	*ft_cap(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		s[i] = ft_toupper(s[i]);
	return (s);
}

void	ft_print_x(char c, unsigned int x)
{
	if (c == 'x')
		ft_putstr_fd(ft_uitoa_hex((long)x), 1);
	else if (c == 'X')
		ft_putstr_fd(ft_cap(ft_uitoa_hex((long)x)), 1);
}
