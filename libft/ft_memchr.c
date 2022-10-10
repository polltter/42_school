#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				len;
	unsigned char	*temp_s;
	int				i;

	i = -1;
	temp_s = (unsigned char *)s;
	len = ft_strlen(s);
	while (++i < len && i < n)
		if (temp_s[i] == c)
			return (&temp_s[i]);
	return (NULL);
}
