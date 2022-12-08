/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:46:43 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/08 18:47:39 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	draw_mandelbrot(t_data *img, t_im seed, t_im offset, double scale)
{
	int		x;
	int		y;
	t_im	pixel;
	t_im	temp;
	int 	iterations;
	int		flag;
	
	x = -1;
	while (++x <= IMG_W)
	{
		y = -1;
		while (++y <= IMG_H)
		{
			pixel = subtract_imaginary(init_number(x, y), sum_imaginary(seed, offset), scale);
			temp = mandelbrot(init_number(0, 0), pixel);
			iterations = 32;
			flag = 0;
			while (iterations)
			{
				if (temp.r > 2)
				{
					my_mlx_pixel_put(img, x, y, 0x00FF00FF);
					flag = 1;
					break ;
				}
				temp = mandelbrot(temp, pixel);
				iterations--;
			}
			if (!flag)
				my_mlx_pixel_put(img, x, y, 0x00000000);
		}	
	}
}

/* void	draw_mandelbrot(t_data *img, t_im seed, t_im offset, double scale)
{
	t_im	pixel;
	t_im	temp;
	int		color;
	double	real;
	double	im;
	int x = 0, y;
	int	flag;
	int mult = 1000;
	int t;
	int u;
	unsigned long int	div;
	
	color = 0;
	real = -IMG_W_2 - 1;
	while (++real < IMG_W_2)
	{
		im = -IMG_H_2  - 1;
		y = 0;
		while (++im < IMG_H_2)
		{
			pixel = init_number(real / (IMG_W / scale), im / (IMG_W / scale));
			temp = mandelbrot(seed, pixel);
			flag = 0;
			for (int po = 0; po < 32; po ++)
			{
				temp = mandelbrot(temp, pixel);
				if (temp.r > 2)
				{
					div = temp.r / mult;
					t = pixel.real * (IMG_W_2);
					u = pixel.im * (IMG_W_2);
					color = create_trgb(0, abs(t*t) / temp.r / mult, abs(t*u) / temp.r / mult, u*u / temp.r / mult);
					my_mlx_pixel_put(img, x, y, color);
					flag = 1;
					break ;
				}
			}
			if (!flag)
			{
				color = create_trgb(0, 0, 0, 0);
				my_mlx_pixel_put(img, x, y, color);
			}
			y++;
		}
		x++;
	}
} */
