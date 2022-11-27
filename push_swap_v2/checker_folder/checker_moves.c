/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:29 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/27 18:16:02 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_rotate(t_list **a, t_list **b, char c)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (a && *a && (*a)->next)
	{
		ft_lstadd_back(a, ft_lstnew((*a)->content));
		temp_a = *a;
		*a = (*a)->next;
		ft_lstdelone(temp_a, NULL);
	}
	if (c == 'r' && b && *b && (*b)->next)
	{
		ft_lstadd_back(b, ft_lstnew((*b)->content));
		temp_b = *b;
		*b = (*b)->next;
		ft_lstdelone(temp_b, NULL);
	}
}

void	checker_rev_rotate(t_list **a, t_list **b, char c)
{
	if (a && *a && (*a)->next)
	{
		ft_lstadd_front(a, ft_lstnew(ft_lstlast(*a)->content));
		ft_lstdellast(*a);
	}
	if (c == 'r' && b && *b && (*b)->next)
	{
		ft_lstadd_front(b, ft_lstnew(ft_lstlast(*b)->content));
		ft_lstdellast(*b);
	}
}

void	checker_swap(t_list **a, t_list **b, char c)
{
	int	temp_content;

	if (a && *a && (*a)->next)
	{
		temp_content = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp_content;
	}
	if (c == 's' && b && *b && (*b)->next)
	{
		temp_content = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp_content;
	}
}

void	checker_push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (*from)
	{
		ft_lstadd_front(to, ft_lstnew((*from)->content));
		temp = *from;
		*from = (*from)->next;
		ft_lstdelone(temp, NULL);
	}
}

void	checker_print_lst(t_list *a)
{
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}
