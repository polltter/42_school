/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/14 17:00:33 by mvenanci         ###   ########.fr       */
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

int	verify_args(char **av, t_stack *stack_a)
{
	int			i;
	long int	n;

	i = 0;
	
	while (*av)
	{
		n = ft_atoi(*av, stack_a, i);
		if (!is_d(*av) || n > INT_MAX || n < INT_MIN \
		|| !check_doubles(stack_a->arr, i, (stack_a->arr)[i]))
		{
			free (stack_a->arr);
			return (0);
		}
		av++;
		i++;
		(stack_a->len)++;
	}
	return (1);
}


int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.arr = (int *)malloc(sizeof(int) * (ac - 1));
	stack_a.len = 0;
	stack_b.arr = (int *)malloc(sizeof(int) * (ac - 1));
	stack_b.len = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2 && !verify_args(split(av[1]), &stack_a))
		ft_printf("Error\n");	
	else if (ac > 2 && !verify_args(++av, &stack_a))
		ft_printf("Error\n");
	else
	{
		if (stack_a.len == 2)
			sort_2(stack_a.arr);
		else if (stack_a.len == 3)
			sort_3(stack_a.arr);
		else
			sort_5(&stack_a, &stack_b);
	}
}
