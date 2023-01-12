/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:51:27 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/14 13:01:37 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *po, ...);
size_t	print_nbr(long int i);
size_t	ft_size(long int n);
size_t	print_char(char c);
size_t	ft_print_x(char c, unsigned int x);
size_t	ft_size_hex(long unsigned int n);
void	write_hex_array(long unsigned int n, int cap);
size_t	ft_print_p(unsigned long int p);
size_t	print_strs(char *s);
void	ft_putnbr(long int n);

#endif