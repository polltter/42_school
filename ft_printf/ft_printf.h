#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *po, ...);
size_t	print_nbr(long int i);
size_t	ft_size(long int n);
size_t	print_char(char c);
size_t	ft_print_x(char c, unsigned int x);
size_t	ft_size_hex(long unsigned int n);
char	*write_hex_array(long unsigned int n, size_t size, char *arr);
size_t	ft_print_p(unsigned long int p);
char	*write_array(long int n, int size, char *arr);
size_t	print_strs(char *s);
void	ft_putnbr(long int n);

#endif