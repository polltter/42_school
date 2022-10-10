#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (--n > 0)
	{
		temp[n] = c;
	}
	temp[n] = c;
	return (s);
}