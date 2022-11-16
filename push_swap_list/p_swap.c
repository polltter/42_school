/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/13 15:07:13 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	verify_args(char **av, t_stack **stack_a)
{
	long int	n;
	t_stack		*curr;

	//av++;
	while (*av)
	{
		n = ft_atoi(*av, stack_a);
		curr = ft_lstlast(*stack_a);
		if (!is_d(*av) || n > INT_MAX || n < INT_MIN \
		|| !check_doubles(*stack_a, curr))
		{
			ft_lstclear(stack_a);
			return (0);
		}
		av++;
	}
	return (1);
}

int	check_doubles(t_stack *stack_a, t_stack *curr)
{
	while (stack_a != curr && stack_a->next)
	{
		if (stack_a->data == curr->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;
	t_stack	*head;

	stack_a = 0;
	//stack_b = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2 && !verify_args(split(av[1]), &stack_a))
		write(2, "Error\n", 6);
	else if (ac == 1 && !verify_args(++av, &stack_a))
		write(2, "Error\n", 6);
	else
	{
		head = stack_a;
		while (stack_a)
		{
			printf("%d ", stack_a->data);
			stack_a = stack_a->next;
		}
		ft_lstclear(&head);
	}
}