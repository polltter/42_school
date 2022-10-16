#ifndef FT_PRINFT_H
# define FT_PRINFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int		ft_printf(char *po, ...);
int		num_params(char *s);
char	*params(char *s);
void	print_nbr(char c, ...);
char	*ft_uitoa(unsigned int n);

#endif