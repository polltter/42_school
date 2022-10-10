#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (--n > 0)
	{
		temp_dest[n] = temp_src[n];
	}
	temp_dest[n] = temp_src[n];
	return (dest);
}