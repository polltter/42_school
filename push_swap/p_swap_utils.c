/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:07:38 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/11 21:57:32 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_d(char *c)
{
	while (*c)
	{
		if (*c == '-')
			c++;
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

long int	ft_atoi(char *s, t_stack *stack_a, int index)
{
	int			i;
	int			sign;
	long int	n;

	n = 0;
	i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i])
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	(stack_a->arr)[index] = n * sign;
	return (n * sign);
}
