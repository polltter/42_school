/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:06:43 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 15:02:01 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&new_lst, lst);
		lst = lst->next;
	}
	return (new_lst);	
}