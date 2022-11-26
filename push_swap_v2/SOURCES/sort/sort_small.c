/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:52:01 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/24 18:44:04 by mvenanci@st      ###   ########.fr       */
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
