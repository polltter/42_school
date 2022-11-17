/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/17 16:00:43 by mvenanci@st      ###   ########.fr       */
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
			return (0);
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*head;

	stack_a = NULL;
	head = stack_a;
	if (ac < 2)
		return (0);
	else if (ac == 2 && !verify_args(split(av[1]), &stack_a, 1))
		write(2, "Error\n", 6);
	else if (ac > 2 && !verify_args(++av, &stack_a, 0))
		write(2, "Error\n", 6);
	ft_lstclear(&head, NULL);
}
