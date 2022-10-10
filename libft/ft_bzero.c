#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	if (n != 0)
	{
		while (--n > 0)
		{
			temp[n] = 0;
		}
	}
	temp[n] = 0;
	return (s);
}