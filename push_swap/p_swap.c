/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/10 19:14:25 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	verify_args(char **av, int **stack_a)
{
	int			i;
	long int	n;

	i = 0;
	av++;
	while (*av)
	{
		n = ft_atoi(*av, stack_a, i);
		if (!is_d(*av) || n > INT_MAX || n < INT_MIN)
		{
			free (*stack_a);
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
	int	*stack_a;
	int	i;

	stack_a = (int *)malloc(sizeof(int) * (ac - 1));
	if (ac < 2)
		return (0);
	else if (!verify_args(av, &stack_a))
		write(2, "Error\n", 6);
	else
	{
		i = 0;
		free(stack_a);
	}
}
