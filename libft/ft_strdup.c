#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*dest;
	int		len_s;

	len_s = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * len_s + 1);
	dest[len_s] = 0;
	while (--len_s >= 0)
		dest[len_s] = s[len_s];
	return (dest);
}
