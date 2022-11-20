/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:16:04 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/20 16:55:45 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	rotate_until(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	while (*a && *b && *a != elem && *b != nearest)
		rotate(a, b, 'r');
	if (*a && *a != elem)
		while (*a != elem)
			rotate(a, NULL, 'a');
	else if (*b && *b != nearest)
		while (*b != nearest)
			rotate(b, NULL, 'b');
}

void	rev_rotate_until(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	while (*a && *b && *a != elem && *b != nearest)
		rev_rotate(a, b, 'r');
	if (*a && *a != elem)
		while (*a != elem)
			rev_rotate(a, NULL, 'a');
	else if (*b && *b != nearest)
		while (*b != nearest)
			rev_rotate(b, NULL, 'b');
}

void	rot_a_rev_b(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	while (*a && *b && *a != elem && *b != nearest)
	{
		rotate(a, NULL, 'a');
		rev_rotate(b, NULL, 'b');
	}
	if (*a && *a != elem)
		while (*a != elem)
			rotate(a, NULL, 'a');
	else if (*b && *b != nearest)
		while (*b != nearest)
			rev_rotate(b, NULL, 'b');
}

void	rev_a_rot_b(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	while (*a && *b && *a != elem && *b != nearest)
	{
		rev_rotate(a, NULL, 'a');
		rotate(b, NULL, 'b');
	}
	if (*a && *a != elem)
		while (*a != elem)
			rev_rotate(a, NULL, 'a');
	else if (*b && *b != nearest)
		while (*b != nearest)
			rev_rotate(b, NULL, 'b');
}

