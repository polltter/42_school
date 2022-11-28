/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:59:52 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/28 17:58:37 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	lsum(t_list *lst)
{
	long int		sum;

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
