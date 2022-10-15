/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:06:43 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 18:15:02 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*curr;

	(void)(*del);
	if (lst)
	{		
		new_lst = ft_lstnew((*f)(lst->content));
		lst = lst->next;
		while (lst)
		{
			curr = ft_lstnew((*f)(lst->content));
			ft_lstadd_back(&new_lst, curr);
			lst = lst->next;
		}
		return (new_lst);
	}
	return (NULL);
}
