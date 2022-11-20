/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:04:28 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 16:17:20 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

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
