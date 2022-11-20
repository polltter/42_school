/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:31:17 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/20 17:55:10 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_list	*elem_to_move(t_list *a, t_list *b, int *path)
{
	t_list	*elem;
	t_list	*head;
	int		min_cost;
	int		cost_elem;

	elem = a;
	head = a;
	min_cost = INT_MAX;
	while (a)
	{
		cost_elem = cost(&head, &b, elem, path);
		if (cost_elem < min_cost)
		{
			min_cost = cost_elem;
			elem = a;
		}
		a = a->next;
	}
	return (elem);
}

void	sort(t_list **a, t_list **b)
{
	int		path;
	t_list	*elem;

	while ((!is_sorted(*a) || (*a)->content < (*b)->content) && lstsize(*a))
	{
		elem = elem_to_move(*a, *b, &path);
		if (path == 0)
			rotate_until(a, b, elem, find_nearest(*b, elem));
		else if (path == 1)
			rotate_until(a, b, elem, find_nearest(*b, elem));
		else if (path == 2)
			rotate_until(a, b, elem, find_nearest(*b, elem));
		else if (path == 3)
			rotate_until(a, b, elem, find_nearest(*b, elem));
		push(a, b, 'b');
		print_lst(*b);
	}
}
