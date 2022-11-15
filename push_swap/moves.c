/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:48:18 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/15 08:51:05 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_arr(int *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_printf("%d\n", arr[i]);
}

void	rotate(t_stack *stack)
{
	int i;
	int temp;

	i = -1;
	temp = (stack->arr)[0];
	while ( ++i < stack->len -1)
		(stack->arr)[i] = (stack->arr)[i + 1];
	(stack->arr)[i] = temp;
	ft_printf("rr%c\n", stack->c);
}

void	rev_rotate(t_stack *stack)
{
	int i;
	int temp;

	i = stack->len;
	temp = (stack->arr)[stack->len -1];
	while ( --i > 0)
		(stack->arr)[i] = (stack->arr)[i - 1];
	(stack->arr)[i] = temp;
	ft_printf("r%c\n", stack->c);
}

void	swap(t_stack *stack)
{
	int temp;
	
	temp = (stack->arr)[0];
	(stack->arr)[0] = (stack->arr)[1];
	(stack->arr)[1] = temp;
	ft_printf("s%c\n", stack->c);
}

void	push(t_stack *from, t_stack *to)
{
	int	i;
	
	i = to->len + 1;
	while (i != 0 && --i > 0)
		(to->arr)[i] = (to->arr)[i - 1]; 
	(to->arr)[i] = (from->arr)[i];
	i--;
	while (++i < (from->len - 1))
		(from->arr)[i] = (from->arr)[i + 1];
	(to->len)++;
	(from->len)--;
	ft_printf("p%c\n", from->c);
}
