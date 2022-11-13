/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:08:02 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/13 17:30:42 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*create_node(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{		
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*curr;

	if (lst && new)
	{
		if (*lst)
		{
			curr = *lst;
			while (curr->next)
				curr = curr->next;
			curr->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	delete_last(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	if (!temp->next)
	{
		free(temp);
		*stack = NULL;
		return ;
	}
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	free(last);
	temp->next = NULL;
}

int	list_size(char c, int p, int increase)
{
	static int	size_a;
	static int	size_b;

	if (c == 'a')
	{
		size_a += increase;
		size_b -= p;
		return (size_a);
	}
	else
	{
		size_b += increase;
		size_a -= p;
		return (size_b);
	}
}
