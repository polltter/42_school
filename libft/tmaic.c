#include "libft.h"

void	memset_tester(void)
{
	typedef struct s_case{
		char c;
		int len;
	} t_case;

	t_case memset_tests[] = {
		{'b', 10},
		{'b', 5},
		{'b', 0},
		{'\0', 15}
	};
	int i = 0;
	int	flag = 1;
	t_case test;
	void *mem1 = malloc(sizeof(char) * 15);
	void *mem2 = malloc(sizeof(char) * 15);
	printf ("========================\n");	
	printf ("Testing ft_memset...\n");
	while (i < 4)
	{
		ft_memset(mem1, 'a', 20);
		memset(mem2, 'a', 20);
		test = memset_tests[i];
		ft_memset(mem1, test.c, test.len);
		memset(mem2, test.c, test.len);
		if (memcmp(mem1, mem2, 15) != 0)
		{
			printf("Failed test %d\n", i + 1);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_memset\n");	
	printf ("========================\n");	
}

int	main(void)
{
	memset_tester();
	return (0);
}