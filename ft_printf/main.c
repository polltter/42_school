#include "ft_printf.h"

int main()
{
	int	*order;

	order = ft_find_order("asdas%iasdasd%isdads%i%%", 7);
	for (int i = 0; i < 7; i++)
	{
		printf("%i\n", order[i]);	
	}
}