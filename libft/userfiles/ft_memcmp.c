#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	int				i;

	i = 0;
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (temp_s1[i] == temp_s2[i] && i < n)
		i++;
	return (temp_s1[i] - temp_s2[i]);
}
