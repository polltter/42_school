/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:19:04 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/16 11:40:51 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *ph, ...)
{
	va_list args;
	int		num_args;
	int		i;
	char	*print_params;

	i = -1;
	num_args = num_params(ph);
	print_params = params(ph);
	va_start(args, ph);
	while (++i < num_args)
	{
		if (print_params[i] == 'd' || print_params[i] == 'i')
			print_nbr(print_params[i], va_arg(args, int));
		else if (print_params[i] == 'u')
			print_nbr(print_params[i], va_arg(args, unsigned int));
		else if (print_params[i] == 's')
			print_chars(print_params[i], va_arg(args, char *));
		else if (print_params[i] == 'c')
			print_chars(print_params[i], va_arg(args, int));
		else if (print_params[i] == 'x' || print_params[i] == 'X')
			ft_print_x(print_params[i], va_arg(args, unsigned int));
	}
	return (1);
}