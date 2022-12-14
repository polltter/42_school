/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:40:52 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/29 19:09:42 by mvenanci@st      ###   ########.fr       */
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

int	ft_sl(char *move)
{
	int	i;

	i = 0;
	if (!move)
		return (0);
	while (move[i] && move[i] != '\n')
		i++;
	return (i);
}

void	cut_lines(t_list **stack_a, t_list **stack_b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
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
