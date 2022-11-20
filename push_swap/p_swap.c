/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/20 18:40:09 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	verify_args(char **av, t_list **stack_a, int malloced)
{
	long int	n;
	t_list		*curr;
	char		**temp;

	temp = av;
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
		if (malloced)
			free(*av);
		av++;
	}
	if (malloced)
		free(temp);
	return (1);
}

int	check_doubles(t_list *stack_a, t_list *curr)
{
	while (stack_a != curr && stack_a->next)
	{
		if (stack_a->content == curr->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_sorted(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->next->content < lst->content)
				return (0);
			lst = lst->next;
		}
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2 && !verify_args(split(av[1], ' '), &stack_a, 1))
		write(2, "Error\n", 6);
	else if (ac > 2 && !verify_args(++av, &stack_a, 0))
		write(2, "Error\n", 6);
	else
	{
		if (!is_sorted(stack_a))
		{
			if (lstsize(stack_a) == 2)
				sort_2(&stack_a);
			else if (lstsize(stack_a) == 3)
				sort_3(&stack_a);
			else
				sort(&stack_a, &stack_b);
		}
		//print_lst(stack_b);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
}
