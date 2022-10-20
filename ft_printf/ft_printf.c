/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:19:04 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/18 11:42:40 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_vars(va_list args, char *print_params, int i)
{
	size_t	total_len;

	if (print_params[i] == 'd' || print_params[i] == 'i')
		total_len = print_nbr(print_params[i], va_arg(args, int));
	else if (print_params[i] == 'u')
		total_len = print_nbr(print_params[i], va_arg(args, unsigned int));
	else if (print_params[i] == 's')
		total_len = print_chars(print_params[i], va_arg(args, char *));
	else if (print_params[i] == 'c')
		total_len = print_chars(print_params[i], va_arg(args, int));
	else if (print_params[i] == 'x' || print_params[i] == 'X')
		total_len = ft_print_x(print_params[i], va_arg(args, unsigned int));
	else if (print_params[i] == 'p')
		total_len = ft_print_p(va_arg(args, long unsigned int));
	else if (print_params[i] == '%')
		total_len = write(1, "%%", 1);
	return (total_len);
}

int	ft_printf(const char *ph, ...)
{
	va_list args;
	char	*print_params;
	int		i;
	int		count;
	size_t	total_len;

	count = 0;
	i = -1;
	total_len = 0;
	print_params = params(ph);
	va_start(args, ph);
	while (ph[++i])
	{
		if (ph[i] == '%')
		{
			total_len += print_vars(args, print_params, count);
			count++;
			i += 1;
		}
		else
			total_len += write(1, &ph[i], 1);
	}
	
	va_end(args);
	return (total_len);
}