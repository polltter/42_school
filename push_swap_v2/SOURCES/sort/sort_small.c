/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:52:01 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/26 22:29:40 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	sort_2(t_list **a)
{
	swap(a, NULL, 'a');
}

int	*lst_to_arr(t_list *stack)
{
	int	size;
	int	*arr;

	size = lstsize(stack);
	arr = malloc(sizeof(int) * size);
	size = 0;
	while (stack)
	{
		arr[size] = stack->content;
		size++;
		stack = stack->next;
	}
	return (arr);
}

void	sort_3(t_list **stack)
{
	int	pos_0;
	int	pos_1;
	int	pos_2;

	pos_0 = (*stack)->content;
	pos_1 = (*stack)->next->content;
	pos_2 = (*stack)->next->next->content;
	if (pos_0 < pos_1 && pos_1 > pos_2 && pos_2 > pos_0)
	{
		rev_rotate(stack, NULL, 'a');
		swap(stack, NULL, 'a');
	}
	else if (pos_0 > pos_1 && pos_1 < pos_2 && pos_2 > pos_0)
		swap(stack, NULL, 'a');
	else if (pos_0 < pos_1 && pos_1 > pos_2 && pos_2 < pos_0)
		rev_rotate(stack, NULL, 'a');
	else if (pos_0 > pos_1 && pos_1 > pos_2 && pos_2 < pos_0)
	{
		swap(stack, NULL, 'a');
		rev_rotate(stack, NULL, 'a');
	}
	else if (pos_0 > pos_1 && pos_1 < pos_2 && pos_2 < pos_0)
		rotate(stack, NULL, 'a');
}

void	sort_5(t_list **a, t_list **b)
{
	t_list	*elem;
	int		path;

	send_to_b(a, b, INT_MAX);
	sort_3(a);
	while (lstsize(*b))
	{
		elem = elem_to_move(*a, *b, &path);
		organize_best(a, b, elem, path);
		push(b, a, 'a');
	}
	min_a_top(a);
}
