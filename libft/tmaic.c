#include "libft.h"

void	itoa_tester(void)
{
	typedef struct s_case{
		int 	n;
		char	*res;
	} t_case;

	t_case itoa_tests[] = {
		{0, "0"},
		{-0, "0"},
		{42, "42"},
		{-42, "-42"},
		{215600, "215600"},
		{-215600, "-215600"},
		{INT_MAX, "2147483647"},
		{INT_MIN, "-2147483648"},
	};
	int i = 0;
	int	flag = 1;
	char	*result;
	t_case test;
	printf ("========================\n");	
	printf ("Testing ft_itoa...\n");
	while (i < 8)
	{
		test = itoa_tests[i];
		result = ft_itoa(test.n);
		if (strcmp(result, test.res))
		{
			printf("Failed test %d\n", i + 1);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_itoa\n");	
	printf ("========================\n");	
}

int	main(void)
{
	itoa_tester();
	return (0);
}