#include <string.h>
#include "libft.h"


void	atoi_tester(void)
{
	typedef struct s_case{
		char *str;
	} t_case;

	t_case atoi_tests[] = {
		{"42"},
		{"-42"},
		{"+42"},
		{"0"},
		{"-0"},
		{"2147483647"},
		{"-2147483648"},
		{"+++++69"},
		{"-+-+-69"},
		{"+6-9"},
		{"-6+9"},
		{"\n-216500"},
		{"-\n216500"},
		{"00000177013"},
		{"7a6"},
		{"     97 8\n5"},
		{"\e177013"},
		{"\t\n\r\v\f  177013abc"},
	};
	int i = 0;
	int	flag = 1;
	printf ("========================\n");	
	printf ("Testing ft_atoi...\n");	
	while (i < 18)
	{
		if (atoi(atoi_tests[i].str) == ft_atoi(atoi_tests[i].str))
			;
		else
		{
			printf("Failed test %d.\nExpected: %d but got: %d\n", i, atoi(atoi_tests[i].str), ft_atoi(atoi_tests[i].str));
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_atoi\n");	
	printf ("========================\n");	
}

void	memcmp_tester(void)
{
	typedef struct s_case{
		char *s1;
		char *s2;
		int len;
	} t_case;

	t_case tests[] = {
		{"test","test",4},
		{"tests","test",5},
		{"testt","tests",5},
		{"","a",1},
		{NULL, "test", 4},
		{"test", NULL, 4},
		{"a","",1},
		{"a\0","a\200",2},
		{"123456789","123459876", 5},
		{"123456789","123459876", 9},
		{"987654321","123456789",0}
	};
	int i = 0;
	int	flag = 1;
	printf ("========================\n");	
	printf ("Testing ft_memcmp...\n");	
	while (i < 11)
	{
		if (i != 4 && i != 5)
		{
			if (ft_memcmp(tests[i].s1, tests[i].s2, tests[i].len) == memcmp(tests[i].s1, tests[i].s2, tests[i].len))
				;
			else
			{
				printf("Failed test %d.\nExpected: %d but got: %d\n", i, \
				memcmp(tests[i].s1, tests[i].s2, tests[i].len), \
				ft_memcmp(tests[i].s1, tests[i].s2, tests[i].len));
				flag = 0;
			}
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_memcmp\n");	
	printf ("========================\n");	
}

int	main(void)
{
	atoi_tester();
	memcmp_tester();
	return (0);
}