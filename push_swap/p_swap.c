/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/15 18:06:05 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_doubles(int *stack, int i, int a)
{
	while (--i >= 0)
		if (stack[i] == a)
			return (0);
	return (1);
}

int	verify_args(char **av, t_stack *stack_a, int malloced)
{
	int			i;
	long int	n;
	char		**temp;

	i = 0;
	temp = av;
	while (*av)
	{
		n = ft_atoi(*av, stack_a, i);
		if (!is_d(*av) || n > INT_MAX || n < INT_MIN \
		|| !check_doubles(stack_a->arr, i, (stack_a->arr)[i]))
		{
			free (stack_a->arr);
			return (0);
		}
		if (malloced)
			free(*av);
		av++;
		i++;
		(stack_a->len)++;
	}
	if (malloced)
		free(temp);
	return (1);
}

void	create_stacks(t_stack *a, t_stack *b, char *av, int ac)
{
	int	n;

	n = word_count(av);
	if (n > ac - 1)
	{
		a->arr = (int *)malloc(sizeof(int) * n);
		b->arr = (int *)malloc(sizeof(int) * n);
	}
	else
	{
		a->arr = (int *)malloc(sizeof(int) * (ac - 1));
		b->arr = (int *)malloc(sizeof(int) * (ac - 1));
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.len = 0;
	stack_a.c = 'a';
	stack_b.len = 0;
	stack_b.c = 'b';
	create_stacks(&stack_a, &stack_b, av[1], ac);
	if (ac < 2)
		return (0);
	else if (ac == 2 && !verify_args(split(av[1]), &stack_a, 1))
		ft_printf("Error\n");
	else if (ac > 2 && !verify_args(++av, &stack_a, 0))
		ft_printf("Error\n");
	else
	{
		if (stack_a.len == 2)
			sort_2(&stack_a);
		else if (stack_a.len == 3)
			sort_3(&stack_a);
		else
			sort_5(&stack_a, &stack_b);
	}
	free(stack_a.arr);
	free(stack_b.arr);
}
