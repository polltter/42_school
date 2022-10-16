/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:35:24 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/16 10:51:28 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_chars(char c, ...)
{
	va_list	args;
	char	a;
	char	*s;

	va_start(args, c);
	if (c == 'c')
	{
		a = va_arg(args, int);	
		ft_putchar_fd(a, 1);
	}
	else if (c == 's')
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
	}
}