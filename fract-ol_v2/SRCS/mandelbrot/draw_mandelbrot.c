/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:46:43 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/10 15:02:15 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	draw_mandelbrot_utils(t_mlx_data *data, t_im pixel, int x, int y, t_im seed)
{
	int		iter;
	int		flag;
	float	re;
	float	im;

	iter = data->max_iter;
	flag = 0;
	re = 0;
	im = 0;
	while (iter--)
	{
		if (sqrt(pow(re, 2) + pow(im, 2)) > 2)
		{
			my_mlx_pixel_put(&(data->img), x, y, \
			color_mng(init_number(seed.real, seed.im), pixel, iter, data->color));
			flag = 1;
			break ;
		}
		re = pow(seed.real, 2) - pow(seed.im, 2) + pixel.real;
		im = 2 * seed.real*seed.im + pixel.im;
		seed.real = re;
		seed.im = im;
	}
	if (!flag)
		my_mlx_pixel_put(&(data->img), x, y, 0x00000000);
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
			draw_mandelbrot_utils(&data, \
			subtract_imaginary(init_number(x, y), \
			sum_imaginary(seed, data.offset), data.scale), \
			x, y, init_number(0, 0));
		}	
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
}
