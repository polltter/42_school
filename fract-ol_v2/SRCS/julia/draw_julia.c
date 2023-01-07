/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:11 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/07 16:38:19 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	draw_julia_utils(t_mlx_data data, t_im seed, int x, int y)
{
	t_im	tmp;
	int		iter;
	int		flag;

	tmp = subtract_imaginary(init_number(x, y), \
	sum_imaginary(init_number(IMG_W_2, IMG_H_2), data.offset), data.scale);
	tmp = julia(tmp, seed);
	iter = 32;
	flag = 0;
	while (iter)
	{
		if (tmp.r > 2)
		{
			my_mlx_pixel_put(&(data.img), x, y, color_mng(tmp, tmp, iter, 0));
			flag = 1;
			break ;
		}
		tmp = julia(tmp, seed);
		iter--;
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
