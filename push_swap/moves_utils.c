/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:09:38 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/17 09:25:02 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_edge(t_stack *stack)
{
	int	i;
	int	max;
	int	min;

	i = 1;
	max = stack->arr[i];
	min = stack->arr[i];
	while (++i < stack->len)
	{
		if (max < stack->arr[i])
			stack->max = (stack->arr)[i];
		if (min > stack->arr[i])
			stack->min = (stack->arr)[i];
	}
}
