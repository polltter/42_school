#include <stdio.h>

char	*ft_strrchr(char const *str, int c)
{
	char	*temp;

	temp = (char *)str;
	while (*str)
		str++;
	if (*str == c)
		return ((char *)str);
	while (str != temp)
	{
		if (*str == c)
			return ((char *)str);
		str--;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
