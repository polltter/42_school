#include "ft_printf.h"

size_t	ft_size_hex(long unsigned int n)
{
	size_t				size;
	long unsigned int	div;

	div = n;
	size = 0;
	if (n == 0)
		return (1);
	while (div != 0)
	{
		size++;
		div /= 16;
	}
	return (size);
}

char	*write_hex_array(long unsigned int n, size_t size, char *arr)
{
	arr[size] = 0;
	while (n != 0)
	{
		size--;
		arr[size] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (arr);
}

int main()
{
	char	*arr;
	
	arr = (char *)malloc(sizeof(char) * (ft_size_hex(0) + 1));
	arr = write_hex_array(0, ft_size_hex(0), arr);
	free(arr);
	printf("%lu\n", ft_size_hex(0));
}
