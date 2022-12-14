/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:11 by mvenanci          #+#    #+#             */
/*   Updated: 2022/12/14 21:42:49 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	draw_julia_utils(t_mlx_data data, t_im seed, int x, int y)
{
	t_im	temp;
	int		iterations;
	int		flag;

	temp = subtract_imaginary(init_number(x, y), \
	sum_imaginary(init_number(IMG_W_2, IMG_H_2), data.offset), data.scale);
	temp = julia(temp, seed);
	iterations = 32;
	flag = 0;
	while (iterations)
	{
		if (temp.r > 2)
		{
			my_mlx_pixel_put(&(data.img), x, y, get_color(temp, init_number(x, y)));
			flag = 1;
			break ;
		}
		temp = julia(temp, seed);
		iterations--;
	}
	if (!flag)
		my_mlx_pixel_put(&(data.img), x, y, 0x00000000);
}

void	draw_julia(t_mlx_data data, t_im seed)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= IMG_W)
	{
		y = -1;
		while (++y <= IMG_H)
		{
			draw_julia_utils(data, seed, \
			x, y);
		}	
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
}
