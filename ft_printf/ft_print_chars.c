/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:35:24 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/31 15:34:06 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	print_strs(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
