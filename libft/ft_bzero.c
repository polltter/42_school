#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = -1;
	temp = (unsigned char *)s;
	if (n != 0)
		while (++i < n)
			temp[i] = 0;
	return (s);
}