/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/11 22:10:00 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	verify_args(char **av, t_stack *stack_a)
{
	int			i;
	long int	n;

	i = 0;
	av++;
	while (*av)
	{
		n = ft_atoi(*av, stack_a, i);
		if (!is_d(*av) || n > INT_MAX || n < INT_MIN || !check_doubles(stack_a->arr, i, (stack_a->arr)[i]))
		{
			free (stack_a->arr);
			return (0);
		}
		av++;
		i++;
	}
	return (1);
}

int	check_doubles(int *stack, int i, int a)
{
	while (--i >= 0)
		if (stack[i] == a)
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;

	stack_a.arr = (int *)malloc(sizeof(int) * (ac - 1));
	stack_a.len = ac - 1;
	if (ac < 2)
		return (0);
	else if (!verify_args(av, &stack_a))
		write(2, "Error\n", 6);
	else
	{
		rotate(&stack_a);
		for (int i = 0; i < ac - 1; i++)
			printf("%d ", stack_a.arr[i]);
		free(stack_a.arr);
	}
}
