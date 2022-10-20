/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:49:11 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/18 10:27:41 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(int n)
{
	ft_putnbr_fd(n, 1);
}

void	print_usgn(unsigned int n)
{
	ft_putstr_fd(ft_uitoa(n),1);
}

/* esta funçao so leva dois parametros:
o primeiro indica o tipo 
o segundo é o numero que quero dar print, ja no tipo certo */
size_t	print_nbr(char c, ...)
{
	va_list			args;
	int				i;
	unsigned int	u;

	va_start(args, c);
	if (c == 'i' || c == 'd')
	{
		i = va_arg(args, int);
		print_int(i);
		return (ft_strlen(ft_itoa(i)));
	}
	else
	{
		u = va_arg(args, unsigned int);
		print_usgn(u);
		return (ft_strlen(ft_uitoa(u)));
	}
}
