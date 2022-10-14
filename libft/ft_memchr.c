#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp_s;
	size_t	i;

	i = -1;
	temp_s = (char *)s;
	while (++i < n)
		if (temp_s[i] == c)
			return (&temp_s[i]);
	return (NULL);
}
