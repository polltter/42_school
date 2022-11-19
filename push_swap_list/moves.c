/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:29 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/19 13:23:29 by mvenanci@st      ###   ########.fr       */
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
	if (a && *a && (*a)->next)
	{
		ft_lstadd_front(a, ft_lstnew(ft_lstlast(*a)->content));
		ft_lstdelone(ft_lstlast(*a), NULL);
		print_lst(*a);
		ft_printf("\n");
		ft_printf("rr%c\n", c);
	}
	if (c == 'r' && b && *b && (*b)->next)
	{
		ft_lstadd_front(b, ft_lstnew(ft_lstlast(*b)->content));
		ft_lstdelone(ft_lstlast(*b), NULL);
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

void	push(t_list **from, t_list **to, char c)
{
	t_list	*temp;

	if (*from)
	{
		ft_lstadd_front(to, ft_lstnew((*from)->content));
		temp = *from;
		*from = (*from)->next;
		ft_lstdelone(temp, NULL);
		ft_printf("p%c\n", c);
	}
}

void	print_lst(t_list *a)
{
	while(a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}
