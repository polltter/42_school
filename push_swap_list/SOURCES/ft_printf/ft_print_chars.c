/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:35:24 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/14 12:59:25 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(char c)
{
	return (write(1, &c, 1));
}

size_t	print_strs(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[++i])
		print_char(s[i]);
	return (i);
}
