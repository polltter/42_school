/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:46:28 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/20 18:32:40 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmin(t_list *lst)
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
