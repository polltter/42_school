/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:32:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/20 19:53:45 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lmax(t_list *lst)
{
	t_list	*max;

	max = lst;
	while (lst)
	{
		if (lst->content > max->content)
			max = lst;
		lst = lst->next;
	}
	return (max);
}
