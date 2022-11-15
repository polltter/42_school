/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:23:51 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/15 18:25:59 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cut_lines(t_stack *a, t_stack *b)
{
	helper(a, b, 2);
	if ((b->arr)[0] > (a->arr)[3])
	{
		helper(a, b, 1);
		rev_rotate(a);
	}
	else
	{
		rev_rotate(a);
		if ((b->arr)[0] > (a->arr)[3])
			helper(a, b, 1);
		else
			helper(a, b, 2);
	}
}

void	cut_lines_2(t_stack *a, t_stack *b)
{
	push(b, a);
	if ((b->arr)[0] > (a->arr)[3])
	{
		push(b, a);
		rotate(a);
		rotate(a);
	}
	else if ((b->arr)[0] > (a->arr)[2])
	{
		helper(a, b, 2);
		helper(a, b, 4);
	}
	else if ((b->arr)[0] > (a->arr)[1])
	{
		helper(a, b, 3);
		swap(a);
	}
	else
		helper(a, b, 3);
}

void	helper_2(t_stack *a, t_stack *b)
{
	if ((b->arr)[0] > (a->arr)[3])
		helper(a, b, 1);
	else
		helper(a, b, 2);
}

void	helper(t_stack *a, t_stack *b, int i)
{
	if (i == 0)
		while (++i < b->len + 1)
			push(b, a);
	else if (i == 1)
	{
		if (b->len)
			push(b, a);
		rev_rotate(a);
	}
	else if (i == 2)
	{
		rev_rotate(a);
		if (b->len)
			push(b, a);
	}
	else if (i == 3)
	{
		rotate(a);
		if (b->len)
			push(b, a);
	}
	else if (i == 4)
		while (--i > 0)
			rotate(a);
}
