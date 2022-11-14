/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:49:23 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/14 13:44:44 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_2(int *arr)
{
	if (arr[0] > arr[1])
		ft_printf("%s", "sa\n");
}

void	sort_3(int *arr)
{
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		ft_printf("%s", "rra\nsa\n");
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		ft_printf("%s", "sa\n");
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		ft_printf("%s", "rra\n");
	if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		ft_printf("%s", "sa\nrra\n");
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ft_printf("%s", "ra\n");
}
