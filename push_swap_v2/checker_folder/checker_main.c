/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:46:30 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/29 19:43:11 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	verify_args(char **av, t_list **stack_a, int malloced, long int n)
{
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
			if (malloced)
				free(*av);
			if (malloced)
				free(temp);
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

void	aply_moves(t_list **a, t_list **b, char *move)
{
	if (move_code(move) == 209 && *move == 'p' && ft_sl(move) == 2)
		checker_push(b, a);
	else if (move_code(move) == 210 && *move == 'p' && ft_sl(move) == 2)
		checker_push(a, b);
	else if (move_code(move) == 212 && *move == 's' && ft_sl(move) == 2)
		checker_swap(a, NULL, 'a');
	else if (move_code(move) == 213 && *move == 's' && ft_sl(move) == 2)
		checker_swap(b, NULL, 'b');
	else if (move_code(move) == 211 && *move == 'r' && ft_sl(move) == 2)
		checker_rotate(a, NULL, 'a');
	else if (move_code(move) == 212 && *move == 'r' && ft_sl(move) == 2)
		checker_rotate(b, NULL, 'b');
	else if (move_code(move) == 228 && *move == 'r' && ft_sl(move) == 2)
		checker_rotate(a, b, 'r');
	else if (move_code(move) == 230 && *move == 's' && ft_sl(move) == 2)
		checker_swap(a, b, 's');
	else if (move_code(move) == 325 && ft_sl(move) == 3 && move[2] == 'a')
		checker_rev_rotate(a, NULL, 'a');
	else if (move_code(move) == 326 && ft_sl(move) == 3 && move[2] == 'b')
		checker_rev_rotate(b, NULL, 'b');
	else if (move_code(move) == 342 && ft_sl(move) == 3 && move[2] == 'r')
		checker_rev_rotate(a, b, 'r');
	else if (write(2, "Error\n", 6))
		exit(0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;git@vogsphere.42lisboa.com:vogsphere/intra-uuid-d6271173-8258-40ba-8bbd-9fefae16493a-4570522-mvenanci

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2 && !verify_args(split(av[1], ' '), &stack_a, 1, 0))
		write(2, "Error\n", 6);
	else if (ac > 2 && !verify_args(++av, &stack_a, 0, 0))
		write(2, "Error\n", 6);
	else
		cut_lines(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
