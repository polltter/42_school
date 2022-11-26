/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:15:36 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/26 21:48:11 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_list	*find_nearest(t_list *to, t_list *elem)
{
	t_list	*nearest;
	int		diff_curr;
	int		diff_smallest;

	if (!elem || !to)
		return (NULL);
	if (elem->content < lmin(to)->content)
		return (lmin(to));
	if (elem->content > lmax(to)->content)
		return (lmin(to));
	nearest = to;
	diff_smallest = INT_MAX;
	while (to)
	{
		diff_curr = to->content - elem->content;
		if (diff_curr < diff_smallest && elem->content < to->content)
		{
			diff_smallest = diff_curr;
			nearest = to;
		}
		to = to->next;
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
	int	min;

	i = -1;
	index = 0;
	min = arr[index];
	while (++i < 4)
	{
		if (arr[i] < min)
		{
			index = i;
			min = arr[i];
		}
	}
	return (index);
}

int	cost(t_list **to, t_list **from, t_list *elem, int *path)
{
	int		cost;
	int		temp[4];
	t_list	*nearest;

	nearest = find_nearest(*to, elem);
	temp[0] = max (lstsize(*from) - lstsize(elem), \
			lstsize(*to) - lstsize(nearest));
	temp[1] = lstsize(*from) - lstsize(elem) + lstsize(nearest);
	temp[2] = lstsize(elem) + lstsize(*to) - lstsize(nearest);
	temp[3] = max(lstsize(elem), lstsize(nearest));
	cost = temp[min_array(temp)];
	*path = min_array(temp);
	return (cost);
}
