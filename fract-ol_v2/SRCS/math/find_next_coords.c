/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:53:26 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/08 17:41:01 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

t_im	find_coords(t_im a, double ang, double side)
{
	return (init_number(a.real + side * cos(ang), a.im - side * sin(ang)));
}

int	print_coords(t_im a)
{
	printf("x: %f\ny: %f\n", a.real, a.im);
	return (1);
}

int	find_color(t_mlx_data *data, t_im first)
{
	int	offset;
	int	x;
	int	y;
	int	sum;

	sum = 0;
	y = (int)first.im - 5;
	while (++y - (int)first.im < 5)
	{
		x = (int)first.real - 5;
		while (++x - (int)first.real < 5)
		{
			if (y * x > 0)
			{
				offset = y * data->img.line_length + \
				x * (data->img.bits_per_pixel / 8);
				sum += *((int *)(data->img.addr + offset));
			}
		}
	}
	return (sum);
}
