/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:15:36 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/20 19:53:52 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_list	*find_nearest(t_list *a, t_list *elem)
{
	t_list	*nearest;
	int		diff_curr;
	int		diff_smallest;

	if (!elem || !a)
		return (NULL);
	if (elem->content < ft_lstmin(a)->content)
		return (lmax(a));
	nearest = a;
	diff_smallest = INT_MAX;
	while (a)
	{
		diff_curr = elem->content - a->content;
		if (diff_curr < diff_smallest && elem->content > a->content)
		{
			diff_smallest = diff_curr;
			nearest = a;
		}
		a = a->next;
	}
	return (nearest);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_array(int *arr)
{
	int	index;
	int	i;

	i = -1;
	index = 0;
	while (++i < 4)
		if (arr[i] < arr[index])
			index = i;
	return (index);
}

int	cost(t_list **a, t_list **b, t_list *elem, int *path)
{
	int		cost;
	int		temp[4];
	t_list	*nearest;

	nearest = find_nearest(*b, elem);
	temp[0] = max (lstsize(*a) - lstsize(elem), lstsize(*b) - lstsize(nearest));
	temp[1] = lstsize(*a) - lstsize(elem) + lstsize(nearest);
	temp[2] = lstsize(elem) + lstsize(*b) - lstsize(nearest);
	temp[3] = max(lstsize(elem), lstsize(nearest));
	cost = temp[min_array(temp)] + 1;
	*path = min_array(temp);
	return (cost);
}
