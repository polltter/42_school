/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:29 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/11 22:10:40 by mvenanci         ###   ########.fr       */
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
		(stack->arr)[i] = (stack->arr)[i - 1]; 
	(stack->arr)[stack->len - 1] = temp;
}