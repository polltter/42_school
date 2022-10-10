#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;

	temp = str;
	while (*str)
		str++;
	if (*str == c)
		return (str);
	while (str != temp)
	{
		if (*str == c)
			return (str);
		str--;
	}
	if (*str == c)
		return (str);
	return (NULL);
}
