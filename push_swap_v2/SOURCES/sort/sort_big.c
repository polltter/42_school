/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:31:17 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/28 19:37:10 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_list	*elem_to_move(t_list *to, t_list *from, int *path)
{
	t_list	*elem;
	t_list	*head_from;
	int		min_cost;
	int		cost_elem;
	int		temp_path;

	temp_path = 0;
	elem = from;
	head_from = from;
	min_cost = INT_MAX;
	while (from)
	{
		cost_elem = cost(&to, &head_from, from, &temp_path);
		if (cost_elem < min_cost)
		{
			min_cost = cost_elem;
			elem = from;
			*path = temp_path;
		}
		from = from->next;
	}
	return (elem);
}

void	sort(t_list **a, t_list **b)
{
	t_list	*elem;
	int		path;

	send_to_b(a, b, lmean(*a) * 0.42);
	sort_3(a);
	while (lstsize(*b))
	{
		elem = elem_to_move(*a, *b, &path);
		organize_best(a, b, elem, path);
		push(b, a, 'a');
	}
	min_a_top(a);
}

void	min_a_top(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (lstsize(*a) - lstsize(lmin(*a)) < lstsize(lmin(*a)))
		rotate_until(a, &b, NULL, lmin(*a));
	else
		rev_rotate_until(a, &b, NULL, lmin(*a));
}

void	organize_best(t_list **a, t_list **b, t_list *elem, int path)
{
	t_list	*nearest;

	nearest = find_nearest(*a, elem);
	if (path == 0)
		rotate_until(a, b, elem, nearest);
	else if (path == 1)
		rev_a_rot_b(a, b, elem, nearest);
	else if (path == 2)
		rot_a_rev_b(a, b, elem, nearest);
	else if (path == 3)
		rev_rotate_until(a, b, elem, nearest);
}

void	send_to_b(t_list **a, t_list **b, long int abs_mean_a)
{
	long int	dyn_mean_a;

	if (lstsize(*a) > 3)
	{
		dyn_mean_a = lmean(*a);
		if ((*a)->content < dyn_mean_a)
		{
			push(a, b, 'b');
			if ((*b)->content < abs_mean_a)
				rotate(b, NULL, 'b');
		}
		else
			rotate(a, NULL, 'a');
		send_to_b(a, b, abs_mean_a);
	}
	return ;
}
