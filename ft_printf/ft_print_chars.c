/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:35:24 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/23 11:01:43 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_chars(char c, ...)
{
	va_list	args;
	char	a;
	char	*s;

	va_start(args, c);
	if (c == 'c')
	{
		a = va_arg(args, int);
		ft_putchar_fd(a, 1);
		return (1);
	}
	else
	{
		s = va_arg(args, char *);
		if (!s)
			return (write(1, "(null)", 6));
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
}
