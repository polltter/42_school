/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:46:43 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/06 18:44:34 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	draw_mandelbrot(t_data *img, t_im seed, double scale)
{
	t_im	pixel;
	t_im	temp;
	int		color;
	double	real;
	double	im;
	int x = 0, y;
	int	flag;

	color = 0;
	real = -IMG_W / 2 - 1;
	while (++real < IMG_W / 2)
	{
		im = -IMG_H / 2  - 1;
		y = 0;
		while (++im < IMG_H / 2)
		{
			pixel = init_number(real / (IMG_W / scale), im / (IMG_W / scale));
			temp = mandelbrot(seed, pixel);
			flag = 0;
			for (int po = 0; po < 50; po ++)
			{
				temp = mandelbrot(temp, pixel);
				if (temp.r > 2)
				{
					int mult = 1000;
					int t = pixel.real * (IMG_W / 2);
					int u = pixel.im * (IMG_W / 2);
					color = create_trgb(0, abs(t*t) / temp.r / mult, abs(t*u) / temp.r / mult, u*u / temp.r/ mult);
					my_mlx_pixel_put(img, x, y, color);
					flag = 1;
					break ;
				}
			}
			if (!flag)
			{
				int mult = 0;
				color = create_trgb(0, x*x / temp.r / mult, x*y / temp.r / mult, y*y / temp.r/ mult);
				my_mlx_pixel_put(img, x, y, color);
			}
			y++;
		}
		x++;
	}
}
