/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:35:01 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/20 18:05:53 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_p(unsigned long int p)
{
	char	*arr;
	if (!p)
		return (write(1, "(nil)", 5));
	arr = (char *)malloc(sizeof(char) * (ft_size_hex(p) + 1));
	arr = write_hex_array(p, ft_size_hex(p), arr);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(arr, 1);
	free(arr);
	return (ft_size_hex(p) + 2);
}