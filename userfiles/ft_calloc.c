#include "libft.h"


void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*arr;

	arr = malloc(elsize);
	while (--nelem > 0)
		arr[nelem] = 0;
	arr[nelem] = 0;
	return ((void *)arr);
}