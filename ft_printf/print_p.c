/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:35:01 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/18 10:19:09 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_p(unsigned long int p)
{
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(ft_uitoa_hex(p), 1);
	return (ft_strlen(ft_uitoa_hex(p)));
}