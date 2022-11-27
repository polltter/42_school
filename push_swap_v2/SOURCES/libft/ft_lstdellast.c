/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:31:13 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/27 10:53:21 by mvenanci@st      ###   ########.fr       */
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
