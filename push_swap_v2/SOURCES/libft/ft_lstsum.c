/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:59:52 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/21 14:13:01 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lsum(t_list *lst)
{
	int		sum;
	int		temp;
	void	*tes;

	tes = 0;
	if (lst)
	{
		sum = 0;
		while (lst)
		{
			temp = lst->content - tes;
			sum += temp;
			lst = lst->next;
		}
	}
	return (sum);
}