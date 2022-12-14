/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_snowflake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:58:34 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/08 18:03:25 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	draw_line(t_mlx_data *data, t_im f, t_im s)
{
	double	slope;
	double	x;
	int		dir;
	int		a;

	slope = (s.im - f.im) / (s.real - f.real);
	dir = (s.real - f.real) / fabs(s.real - f.real);
	x = f.real;
	while ((int)x != (int)s.real)
	{
		a = slope * (x - f.real) + f.im + 0.00001;
		if (x <= IMG_W && a <= IMG_H && x > 0 && a > 0)
			my_mlx_pixel_put(&(data->img), x, a, \
			color_mng_kt(data, x, a));
		x += dir;
	}
}

void	clean_screen(t_mlx_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= IMG_H)
	{
		x = -1;
		while (++x <= IMG_W)
			my_mlx_pixel_put(&(data->img), x, y, 0);
	}
}

t_im	init_point(t_mlx_data *data, double x, double y)
{
	t_im	new;
	int		c_off_x;
	int		c_off_y;

	c_off_x = (x - IMG_W_2) * data->kscale / 1 ;
	c_off_y = (y - IMG_H_2) * data->kscale / 1;
	new = init_number(x + c_off_x, y + c_off_y);
	new = sum_imaginary(new, data->offset);
	return (new);
}

void	draw_koch_curve(t_mlx_data *data, t_im a, t_im b, int iter)
{
	t_im	x1;
	t_im	x2;
	t_im	vertice;
	double	alfa;
	double	height;

	if (iter == 0)
	{
		draw_line(data, a, b);
		return ;
	}
	alfa = find_angle(a, b);
	height = sqrt(3) / 2 * find_size(a, b) / 3;
	vertice = find_vertice(find_midpoint(a, b), alfa, height);
	x1 = find_coords(a, alfa, find_size(a, b) / 3.0);
	x2 = find_coords(a, alfa, find_size(a, b) / 3.0 * 2);
	draw_koch_curve(data, a, x1, iter - 1);
	draw_koch_curve(data, x1, vertice, iter - 1);
	draw_koch_curve(data, vertice, x2, iter - 1);
	draw_koch_curve(data, x2, b, iter - 1);
}

void	draw_koch_snowflake(t_mlx_data *data)
{
	t_im	a;
	t_im	b;
	t_im	c;

	a = init_point(data, 350, 486.6025404);
	b = init_point(data, 650, 486.6025404);
	c = init_point(data, 500, 226.7949192);
	clean_screen(data);
	draw_koch_curve(data, a, b, data->iterations);
	draw_koch_curve(data, b, c, data->iterations);
	draw_koch_curve(data, c, a, data->iterations);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
