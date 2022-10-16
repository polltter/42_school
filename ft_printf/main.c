#include "ft_printf.h"

int	*ft_find_order(char *ph, int size)
{
	int	*order;
	int i;
	int	index;	

	index = 0;
	i = -1;
	order = (int *)malloc(sizeof(int) * size);
	while (ph[++i])
	{
		if (ph[i] == '%')
		{
			order[index] = 1;
			index++;
			i++;
		}
		else
		{
			while (ph[i] != '%' && ph[i])
			{
				if (ph[i + 1] == '%' || !ph[i + 1])
				{
					order[index] = 2;
					index++;
					break ;
				}
				i++;
			}
			
		}
	}
	return (order);
}

int main()
{
	int	*order;

	order = ft_find_order("asdas%iasdasd%isdads%i%%", 7);
	for (int i = 0; i < 7; i++)
	{
		printf("%i\n", order[i]);	
	}
}