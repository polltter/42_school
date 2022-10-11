#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	i = -1;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (++i < n)
	{
		temp_dest[i] = temp_src[i]; 
	}
	return (dest);
}