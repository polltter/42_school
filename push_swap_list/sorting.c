/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:29 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/12 16:39:07 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = create_node((*stack)->data);
	ft_lstadd_back(stack, temp);
	temp = *stack;
	*stack = temp->next;
	free(temp);
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = create_node((ft_lstlast(*stack))->data);
	ft_lstadd_front(stack, temp);
	delete_last(stack);
	*stack = temp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	new = create_node((*stack_a)->data);
	ft_lstadd_front(stack_b, new);
	rotate(stack_a);
	delete_last(stack_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	new = create_node((*stack_b)->data);
	ft_lstadd_front(stack_a, new);
	rotate(stack_b);
	delete_last(stack_b);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!((*stack)->next))
		return ;
	first = create_node((*stack)->data);
	second = create_node((*stack)->next->data);
	rotate(stack);
	rotate(stack);
	delete_last(stack);
	delete_last(stack);
	ft_lstadd_front(stack, first);
	ft_lstadd_front(stack, second);
}
