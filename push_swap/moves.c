/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:48:18 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/14 16:47:04 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void print_arr(int *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_printf("%d\n", arr[i]);
}

void rotate(int **arr, int len)
{
	int i;
	int temp;

	i = -1;
	temp = (*arr)[0];
	while ( ++i < len -1)
		(*arr)[i] = (*arr)[i + 1];
	(*arr)[i] = temp;
}

void rev_rotate(int **arr, int len)
{
	int i;
	int temp;

	i = len;
	temp = (*arr)[len -1];
	while ( --i > 0)
		(*arr)[i] = (*	arr)[i - 1];
	(*arr)[i] = temp;
}

void swap(int **arr)
{
	int temp;
	
	temp = (*arr)[0];
	(*arr)[0] = (*arr)[1];
	(*arr)[1] = temp;
}

void	push(t_stack *from, t_stack *to)
{
	int	i;
	
	i = to->len;
	while (i != 0 && --i > 0)
		(to->arr)[i] = (to->arr)[i - 1]; 
	(to->arr)[i--] = (from->arr)[i];
	while (++i < from->len - 1)
		(from->arr)[i] = (from->arr)[i - 1];
	(to->len)++;
	(from->len)--;
	
}