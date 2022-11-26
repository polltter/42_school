/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:16:04 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/26 22:04:16 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	rotate_until(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	int	tempa;
	int	tempb;

	if (elem)
		tempb = elem->content;
	if (nearest)
		tempa = nearest->content;
	while (*a && *b && (*a)->content != tempa && (*b)->content != tempb)
		rotate(a, b, 'r');
	if (*a && (*a)->content != tempa)
		while ((*a)->content != tempa)
			rotate(a, NULL, 'a');
	else if (*b && (*b)->content != tempb)
		while ((*b)->content != tempb)
			rotate(b, NULL, 'b');
}

void	rev_rotate_until(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	int	tempa;
	int	tempb;

	if (elem)
		tempb = elem->content;
	if (nearest)
		tempa = nearest->content;
	while (*a && *b && (*a)->content != tempa && (*b)->content != tempb)
		rev_rotate(a, b, 'r');
	if (*a && (*a)->content != tempa)
		while ((*a)->content != tempa)
			rev_rotate(a, NULL, 'a');
	else if (*b && (*b)->content != tempb)
		while ((*b)->content != tempb)
			rev_rotate(b, NULL, 'b');
}

void	rot_a_rev_b(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	int	tempa;
	int	tempb;

	if (elem)
		tempb = elem->content;
	if (nearest)
		tempa = nearest->content;
	while (*a && *b && (*a)->content != tempa && (*b)->content != tempb)
	{
		rotate(a, NULL, 'a');
		rev_rotate(b, NULL, 'b');
	}
	if (*a && (*a)->content != tempa)
		while ((*a)->content != tempa)
			rotate(a, NULL, 'a');
	else if (*b && (*b)->content != tempb)
		while ((*b)->content != tempb)
			rev_rotate(b, NULL, 'b');
}

void	rev_a_rot_b(t_list **a, t_list **b, t_list *elem, t_list *nearest)
{
	int	tempa;
	int	tempb;

	if (elem)
		tempb = elem->content;
	if (nearest)
		tempa = nearest->content;
	while (*a && *b && (*a)->content != tempa && (*b)->content != tempb)
	{
		rev_rotate(a, NULL, 'a');
		rotate(b, NULL, 'b');
	}
	if (*a && (*a)->content != tempa)
		while ((*a)->content != tempa)
			rev_rotate(a, NULL, 'a');
	else if (*b && (*b)->content != tempb)
		while ((*b)->content != tempb)
			rotate(b, NULL, 'b');
}
