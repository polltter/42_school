#include "libft.h"

void	atoi_tester(void)
{
	typedef struct s_case{
		char *str;
	}	t_case;

	t_case	atoi_tests[] = {
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

void	bzero_tester(void)
{
	typedef struct s_case{
		int len;
	} t_case;

	t_case bzero_tests[] = {
		{10},
		{5},
		{0}
	};
	int i = 0;
	int	flag = 1;
	char *mem1 = strdup("aaaaaaaaaa");
	char *mem2 = strdup("aaaaaaaaaa");
	printf ("========================\n");	
	printf ("Testing ft_bzero...\n");	
	while (i < 3)
	{
		ft_bzero(mem1,bzero_tests[i].len);
		bzero(mem2, bzero_tests[i].len);
		if (memcmp(mem1, mem2, bzero_tests[i].len) !=  0)
		{
			printf("Failed test %d\n", i);
			flag  = 0;
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_bzero\n");	
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

void	calloc_tester(void)
{
	typedef struct s_case{
        int count;
        int size;
    } t_case;

    t_case calloc_tests[] = {
        {20, sizeof(char)},
        {0,sizeof(char)}
    };

	int i = 0;
	int	flag = 1;
	void *result;
	void *expected;
	printf ("========================\n");	
	printf ("Testing ft_calloc...\n");	
	while (i < 2)
	{
		t_case test = calloc_tests[i];
		result = ft_calloc(test.count, test.size);
		expected = calloc(test.count, test.size);
		if (!result || memcmp(result, expected, calloc_tests[i].count) != 0)
		{
			printf("Failed test %d\n", i);
			flag  = 0;
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_calloc\n");	
	printf ("========================\n");	
}

void	isalnum_tester(void)
{
	typedef struct s_case{
		int start;
		int end;
	} t_case;

	t_case isalnum_tests[] = {
		{-1, 47},
		{'0', '9'},
		{58, 64},
		{'A', 'Z'},
		{91, 96},
		{'a', 'z'},
		{123, 128}
	};

	int i = 0;
	int	flag = 1;
	int	result;
	int	expected;
	t_case test;
	printf ("========================\n");	
	printf ("Testing ft_isalnum...\n");
	while (i < 6)
	{
		test = isalnum_tests[i];
		for (int start = test.start; start <= test.end; start++)
		{
			result = ft_isalnum(start);
			expected = isalnum(start);
			if (expected != 0)
				expected = 1;
			if (result != expected)
			{
				printf("Failed test %d\n", i);
				flag = 0;
				break ;
			}
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_isalnum\n");	
	printf ("========================\n");	
}

void	isalpha_tester(void)
{
	typedef struct s_case{
		int start;
		int end;
	} t_case;

	t_case isalpha_tests[] = {
		{-1, 47},
		{'0', '9'},
		{58, 64},
		{'A', 'Z'},
		{91, 96},
		{'a', 'z'},
		{123, 128}
	};

	int i = 0;
	int	flag = 1;
	int	result;
	int	expected;
	t_case test;
	printf ("========================\n");	
	printf ("Testing ft_isalpha...\n");
	while (i < 6)
	{
		test = isalpha_tests[i];
		for (int start = test.start; start <= test.end; start++)
		{
			result = ft_isalpha(start);
			expected = isalpha(start);
			if (expected != 0)
				expected = 1;
			if (result != expected)
			{
				printf("Failed test %d\n", i);
				flag = 0;
				break ;
			}
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_isalpha\n");	
	printf ("========================\n");	
}

void	isascii_tester(void)
{
	typedef struct s_case{
		int start;
		int end;
	} t_case;

	t_case isascii_tests[] = {
		{-1, -1},
		{0, 127},
		{128, 128}
	};

	int i = 0;
	int	flag = 1;
	int	result;
	int	expected;
	t_case test;
	printf ("========================\n");	
	printf ("Testing ft_isascii...\n");
	while (i < 3)
	{
		test = isascii_tests[i];
		for (int start = test.start; start <= test.end; start++)
		{
			result = ft_isascii(start);
			expected = isascii(start);
			if (expected > 0)
				expected = 1;
			if (result != expected)
			{
				printf("Failed test %d\n", i);
				flag = 0;
				break ;
			}
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_isascii\n");	
	printf ("========================\n");	
}

void	isdigit_tester(void)
{
	typedef struct s_case{
		int start;
		int end;
	} t_case;

	t_case isdigit_tests[] = {
		{-1, 47},
		{'0', '9'},
		{58, 128}
	};

	int i = 0;
	int	flag = 1;
	int	result;
	int	expected;
	t_case test;
	printf ("========================\n");	
	printf ("Testing ft_isdigit...\n");
	while (i < 3)
	{
		test = isdigit_tests[i];
		for (int start = test.start; start <= test.end; start++)
		{
			result = ft_isdigit(start);
			expected = isdigit(start);
			if (expected > 0)
				expected = 1;
			if (result != expected)
			{
				printf("Failed test %d\n", i);
				flag = 0;
				break ;
			}
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_isdigit\n");	
	printf ("========================\n");	
}

void	isprint_tester(void)
{
	typedef struct s_case{
		int start;
		int end;
	} t_case;

	t_case isprint_tests[] = {
		{0, 31},
		{32, 126},
		{127, 127}
	};
	int i = 0;
	int	flag = 1;
	int	result;
	int	expected;
	t_case test;
	printf ("========================\n");	
	printf ("Testing ft_isprint...\n");
	while (i < 3)
	{
		test = isprint_tests[i];
		for (int start = test.start; start <= test.end; start++)
		{
			result = ft_isprint(start);
			expected = isprint(start);
			if (expected > 0)
				expected = 1;
			if (result != expected)
			{
				printf("Failed test %d\n", i + 1);
				flag = 0;
				break ;
			}
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_isprint\n");	
	printf ("========================\n");	
}

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

void	memchr_tester(void)
{
	typedef struct s_case{
		void *mem;
		int memlen;
		int c;
		int len;
	} t_case;

	t_case memchr_tests[] = {
		{"test", 4, 'a', 4},
		{"testtest", 8,'s', 8},
		{"test", 4,'s', 2},
		{"test", 4,'a', 5},
		{"abcde\0zyxw", 10, 'z', 10},
		{"potatoes", 8, '\0', 9},
		{NULL, 0, '\0', 3}
	};
	int i = 0;
	int	flag = 1;
	char	*result;
	char	*expected;
	t_case test;
	printf ("========================\n");	
	printf ("Testing ft_memchr...\n");
	while (i < 6)
	{
		test = memchr_tests[i];
		result = ft_memchr(test.mem, test.c, test.len);
		expected = memchr(test.mem, test.c, test.len);
		if (result != expected)
		{
			printf("Failed test %d\n", i + 1);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		printf ("Passed ft_memchr\n");	
	printf ("========================\n");	
}

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
	atoi_tester();
	memcmp_tester();
	bzero_tester();
	calloc_tester();
	isalnum_tester();
	isalpha_tester();
	isascii_tester();
	isdigit_tester();
	isprint_tester();
	itoa_tester();
	memchr_tester();
	memcpy_tester();
	memset_tester();
	return (0);
}