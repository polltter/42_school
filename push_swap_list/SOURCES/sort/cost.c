/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:15:36 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/20 18:04:17 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_list	*find_nearest(t_list *a, t_list *elem)
{
	t_list	*nearest;

	if (!elem || !a)
		return (NULL);
	if (elem->content < ft_lstmin(a)->content)
		return (ft_lstmin(a));
	nearest = a;
	while (a)
	{
		if (elem->content - a->content < 0 && \
		elem->content - a->content < elem->content - nearest->content)
			nearest = a;
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
	if (nearest)
		ft_printf("nearest is: %p\n", nearest->content);
	temp[0] = max (lstsize(*a) - lstsize(elem), lstsize(*b) - lstsize(nearest));
	temp[1] = lstsize(*a) - lstsize(elem) + lstsize(nearest);
	temp[2] = lstsize(elem) + lstsize(*b) - lstsize(nearest);
	temp[3] = max(lstsize(elem), lstsize(nearest));
	cost = temp[min_array(temp)] + 1;
	*path = min_array(temp);
	return (cost);
}
