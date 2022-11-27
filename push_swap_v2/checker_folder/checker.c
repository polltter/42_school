/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:46:30 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/27 18:17:51 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	aply_moves(t_list **a, t_list **b, char *move)
{
	int	code;

	code = move_code(move); 
	if (code == 209)
		checker_push(b, a);
	else if (code == 210)
		checker_push(a, b);
	else if (code == 212 && *move == 's')
		checker_swap(a, NULL, 'a');
	else if (code == 213)
		checker_swap(b, NULL, 'b');
	else if (code == 211)
		checker_rotate(a, NULL, 'a');
	else if (code == 212 && *move == 's')
		checker_rotate(b, NULL, 'b');
	else if (code == 228)
		checker_rotate(a, b, 'r');
	else if (code == 230)
		checker_swap(a, b, 's');
	else if (code == 325)
		checker_rev_rotate(a, NULL, 'a');
	else if (code == 326)
		checker_rev_rotate(b, NULL, 'b');
	else if (code == 342)
		checker_rev_rotate(a, b, 'r');
		
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*s;

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
		s = get_next_line(0);
		while (s)
		{
			aply_moves(&stack_a, &stack_b, s);
			free (s);
			s = get_next_line(0);
		}
		free(s);
		if (is_sorted(stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_lstclear(&stack_a);
}
