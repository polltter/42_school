/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:59:52 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/24 18:30:49 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lsum(t_list *lst)
{
	int		sum;

	if (lst)
	{
		sum = 0;
		while (lst)
		{
			sum += lst->content;
			lst = lst->next;
		}
	}
	return (sum);
}
