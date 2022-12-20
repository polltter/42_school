/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:46:43 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/18 00:00:18 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../INCS/fractol.h"

void	draw_mandelbrot_utils(t_data *img, t_im pixel, int x, int y)
{
	t_im	temp;
	int		iterations;
	int		flag;

	temp = mandelbrot(init_number(0, 0), pixel);
	iterations = 50;
	flag = 0;
	while (iterations)
	{
		if (temp.r > 2)
		{
			my_mlx_pixel_put(img, x, y, color_manager(temp, pixel, iterations, 0));
			flag = 1;
			break ;
		}
		temp = mandelbrot(temp, pixel);
		iterations--;
	}
	if (!flag)
		my_mlx_pixel_put(img, x, y, 0x00000000);
}

void	draw_mandelbrot(t_mlx_data data, t_im seed)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= IMG_W)
	{
		y = -1;
		while (++y <= IMG_H)
		{
			draw_mandelbrot_utils(&(data.img), \
			subtract_imaginary(init_number(x, y), \
			sum_imaginary(seed, data.offset), data.scale), \
			x, y);
		}	
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
}
