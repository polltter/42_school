#include "libft.h"

void	memcpy_tester(void)
{
	typedef struct s_case{
		char *cpy;
		int cpylen;
		int len;
	} t_case;

	t_case memcpy_tests[] = {
		{"abcdefghijklmnop", 16, 20},
		{"abcdefghijklmnop", 16, 10},
		{"abcdefghijklmnop", 16, 0},
		{"ab\0cd\0ef\0gh", 11, 11},
		{NULL, 0, 20},
		{NULL, 0, 0}
	};
	int i = 0;
	int	flag = 1;
	t_case test;
	void *mem1 = malloc(sizeof(char) * 20);
	void *mem2 = malloc(sizeof(char) * 20);
	printf ("========================\n");	
	printf ("Testing ft_memcpy...\n");
	while (i < 4)
	{
		memset(mem1, 'a', 20);
		memset(mem2, 'a', 20);
		test = memcpy_tests[i];
		mem1 = ft_memcpy(mem1, test.cpy, test.cpylen);
		mem2 = memcpy(mem1, test.cpy, test.cpylen);
		if (memcmp(mem1, mem2, 20) != 0)
		{
			printf("Failed test %d\n", i + 1);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_memcpy\n");	
	printf ("========================\n");	
}

int	main(void)
{
	memcpy_tester();
	return (0);
}