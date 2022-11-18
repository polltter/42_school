/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:29 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/18 14:05:59 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate(t_list **a, t_list **b, char c)
{
	t_list	*temp;

	if (a && *a && (*a)->next)
	{
		ft_lstadd_back(a, ft_lstnew((*a)->content));
		temp = *a;
		*a = (*a)->next;
		ft_lstdelone(temp, NULL);
		ft_printf("r%c\n", c);
	}
	if (c == 'r' && b && *b && (*b)->next)
	{
		ft_lstadd_back(b, ft_lstnew((*b)->content));
		temp = *b;
		*b = (*b)->next;
		ft_lstdelone(temp, NULL);
	}
}

void	rev_rotate(t_list **a, t_list **b, char c)
{
	t_list	*temp;

	if (a && *a && (*a)->next)
	{
		ft_lstadd_back(a, ft_lstnew((*a)->content));
		temp = *a;
		*a = (*a)->next;
		ft_lstdelone(temp, NULL);
		ft_printf("r%c\n", c);
	}
	if (c == 'r' && b && *b && (*b)->next)
	{
		ft_lstadd_back(b, ft_lstnew((*b)->content));
		temp = *b;
		*b = (*b)->next;
		ft_lstdelone(temp, NULL);
	}
}

void	swap(t_list **a, t_list **b, char c)
{
	void	*temp_content;

	if (a && *a && (*a)->next)
	{
		temp_content = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp_content;
		ft_printf("s%c\n", c);
	}
	if (c == 's' && b && *b && (*b)->next)
	{
		temp_content = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp_content;
	}
}

