/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:15:36 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/19 12:18:44 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/nfs/homes/mvenanci/Documents/42_school/push_swap_list/header.h"

t_list	*find_nearest(t_list *a, t_list *elem)
{
	t_list	*nearest;

	nearest = a;
	if (!elem)
		return (NULL);
	while (a)
	{
		if (elem->content - a->content > 0 && \
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

int	cost(t_list **a, t_list **b, t_list *elem)
{
	int		cost;
	int		temp;
	t_list	*nearest;

	nearest = find_nearest(*b, elem);
	cost = max (ft_lstsize(*a) - ft_lstsize(elem), \
	ft_lstsize(*b) - ft_lstsize(nearest));
	temp = ft_lstsize(*a) - ft_lstsize(elem) + ft_lstsize(nearest);
	if (temp < cost)
		cost = temp;
	temp = ft_lstsize(elem) + ft_lstsize(*b) - ft_lstsize(nearest);
	if (temp < cost)
		cost = temp;
	temp = max(ft_lstsize(elem), ft_lstsize(nearest));
	if (temp < cost)
		cost = temp;
	return (cost);
}
