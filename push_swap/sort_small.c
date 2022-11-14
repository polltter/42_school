/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:49:23 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/14 16:57:57 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_2(int *arr)
{
	if (arr[0] > arr[1])
		ft_printf("%s", "sa\n");
}

void	sort_3(int *arr)
{
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		rev_rotate(&arr, 3);
		swap(&arr);
		ft_printf("%s", "rra\nsa\n");
	}
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		swap(&arr);
		ft_printf("%s", "sa\n");
	}
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		rev_rotate(&arr, 3);
		ft_printf("%s", "rra\n");
	}
	if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		swap(&arr);
		rev_rotate(&arr, 3);
		ft_printf("%s", "sa\nrra\n");
	}
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
	{
		rotate(&arr, 3);
		ft_printf("%s", "ra\n");
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	ft_printf("pa\npa\n");
	push(a, b);
	push(a, b);
	sort_3(a->arr);
}