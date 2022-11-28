/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:40:52 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/28 11:56:37 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	move_code(char *move)
{
	int	code;
	int	i;

	i = -1;
	code = 0;
	while (move[++i] && move[i] != '\n')
		code += move[i];
	return (code);
}

void	cut_lines(t_list **stack_a, t_list **stack_b)
{
	char	*s;
	// int i = 0;
	s = get_next_line(0);
	while (s)
	{
		// ft_printf("%d, %s\n", i++, s);
		aply_moves(stack_a, stack_b, s);
		free(s);
		s = get_next_line(0);
	}
	free(s);
	if (is_sorted(*stack_a) && !lstsize(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
