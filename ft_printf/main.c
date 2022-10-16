#include "ft_printf.h"

char	*write_hex_array(unsigned int n, int size)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	arr[size] = 0;
	while (n != 0)
	{
		arr[--size] = "0132456789abcdef"[n % 16];
		n /= 16;
	}
	return (arr);
}

char	*ft_uitoa_hex(unsigned int n)
{
	int			size;
	long int	div;

	div = n;
	size = 0;
	if (n == 0)
		return ("0");
	while (div != 0)
	{
		size++;
		div /= 16;
	}
	return (write_hex_array(n, size));
}

int main()
{
	printf("%s", ft_uitoa_hex(10));
}