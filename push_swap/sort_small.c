/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:49:23 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/15 08:58:27 by mvenanci         ###   ########.fr       */
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
	sort_2(b);
}