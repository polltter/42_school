/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/10 14:24:17 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int verify_args(char **av)
{
	av++;
	while (*av)
	{
		if (!is_d(*av) || ft_atoi(*av) > INT_MAX || ft_atoi(*av) < INT_MIN)
			return (0);
		av++;
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

int main(int ac, char **av)
{
	if (ac < 2 || !verify_args(av))
		write(2, "Error\n", 6);
	else
	{
		int	stack_a[ac - 1];
		int	i;

		i = -1;
		while (*(++av))
		{
			stack_a[++i] = ft_atoi(*av);
			if (!check_doubles(stack_a, i, stack_a[i]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
			
	}
}

