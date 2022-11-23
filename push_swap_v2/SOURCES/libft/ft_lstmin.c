/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:46:28 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/21 20:21:45 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lmin(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if (lst->content < min->content)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
