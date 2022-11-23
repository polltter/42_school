/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:31:13 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/19 19:33:41 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lstdellast(t_list *a)
{
	if (a)
	{
		while (a->next->next)
			a = a->next;
		free(a->next);
		a->next = NULL;
	}
}