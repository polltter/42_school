/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:52:01 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/18 17:22:22 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_list/header.h"

void	sort_2(t_list **a)
{
	swap(a, NULL, 'a');
}

int	*lst_to_arr(t_list *stack)
{
	int	size;
	int	*arr;

	size = ft_lstsize(stack);
	arr = malloc(sizeof(int) * size);
	size = 0;
}

void	sort_3(t_list *stack)
{
	
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