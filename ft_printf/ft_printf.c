/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:19:04 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/21 11:05:46 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_vars(va_list args, char c)
{
	size_t	total_len;

	if (c == 'd' || c == 'i')
		total_len = print_nbr(c, (long)va_arg(args, int));
	else if (c == 'u')
		total_len = print_nbr(c, va_arg(args, unsigned int));
	else if (c == 's')
		total_len = print_chars(c, va_arg(args, char *));
	else if (c == 'c')
		total_len = print_chars(c, va_arg(args, int));
	else if (c == 'x' || c == 'X')
		total_len = ft_print_x(c, va_arg(args, unsigned int));
	else if (c == 'p')
		total_len = ft_print_p(va_arg(args, long unsigned int));
	else if (c == '%')
		total_len = write(1, "%%", 1);
	return (total_len);
}

int	ft_printf(const char *ph, ...)
{
	va_list args;
	int		i;
	int		count;
	size_t	total_len;

	count = 0;
	i = -1;
	total_len = 0;
	va_start(args, ph);
	while (ph[++i])
	{
		if (ph[i] == '%')
		{
			i += 1;
			total_len += print_vars(args, ph[i]);
			count++;
		}
		else
			total_len += write(1, &ph[i], 1);
	}
	
	va_end(args);
	return (total_len);
}