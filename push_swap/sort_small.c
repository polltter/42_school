/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:49:23 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/15 17:47:11 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_2(t_stack *stack)
{
	if ((stack->arr)[0] < (stack->arr)[1])
		swap(stack);
}

void	sort_3(t_stack *stack)
{
	int	*arr;

	arr = stack->arr;
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		rev_rotate(stack);
		swap(stack);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		swap(stack);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		rev_rotate(stack);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		swap(stack);
		rev_rotate(stack);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		rotate(stack);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->len > 3)
		push(a, b);
	sort_3(a);
	if (b->len == 2)
		sort_2(b);
	if ((b->arr)[0] < (a->arr)[0])
		helper(a, b, 0);
	else if ((b->arr)[0] < (a->arr)[1])
	{
		helper(a, b, 3);
		helper_2(a, b);
	}
	else if ((b->arr)[0] < (a->arr)[2])
		cut_lines(a, b);
	else
		cut_lines_2(a, b);
}
