/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:55:53 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/13 21:48:39 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_arr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);
}

void rotate(int **arr, int len)
{
	int i = -1;
	int temp = (*arr)[0];
	while ( ++i < len -1)
		(*arr)[i] = (*arr)[i + 1];
	(*arr)[i] = temp;
}

void rev_rotate(int **arr, int len)
{
	int i = len;
	int temp = (*arr)[len -1];
	while ( --i > 0)
		(*arr)[i] = (*	arr)[i - 1];
	(*arr)[i] = temp;
}

void swap(int **arr)
{
	int temp = (*arr)[0];
	(*arr)[0] = (*arr)[1];
	(*arr)[1] = temp;
}

int	main(void)
{
	int *arr = malloc(12);
	arr[0] = 3;
	arr[1] = 1;
	arr[2] = 2; 
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		rev_rotate(&arr, 3);
		swap(&arr);
		write(1, "rr\nsa\n", 6);
	}
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		swap(&arr);
		write(1, "sa\n", 3);
	}
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		rev_rotate(&arr, 3);
		write(1, "rr\n", 3);
	}
	if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		swap(&arr);
		rev_rotate(&arr, 3);
		write(1, "sa\nrr\n", 6);
	}
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
	{
		rotate(&arr, 3);
		write(1, "r\n", 2);
	}
	print_arr(arr, 3);
}
