#ifndef FT_PRINFT_H
# define FT_PRINFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(char *po, ...);
int		num_params(char *s);
char	*params(char *s);
void	print_nbr(char c, ...);
char	*ft_uitoa(unsigned int n);
void	print_chars(char c, ...);
void	ft_print_x(char c, unsigned int x);
char	*ft_uitoa_hex(long unsigned int n);
char	*write_hex_array(long unsigned int n, int size);
void	ft_print_p(unsigned long int p);
char	**ft_split_mod(char const *s, char c);
int		word_counter(const char *s, char c);
int		*ft_find_order(char *ph, int size);

#endif