/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:29 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/12 15:08:35 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = (stack->arr)[0];
	while (++i < stack->len)
		(stack->arr)[i - 1] = (stack->arr)[i];
	(stack->arr)[stack->len - 1] = temp;
}

void	rev_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = (stack->arr)[stack->len - 1];
	while (++i < stack->len)
		(stack->arr)[i - 1] = (stack->arr)[i];
	(stack->arr)[stack->len - 1] = temp;
}