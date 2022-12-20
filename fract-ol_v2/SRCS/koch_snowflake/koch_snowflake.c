/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_snowflake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:58:34 by mvenanci          #+#    #+#             */
/*   Updated: 2022/12/20 01:39:26 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	draw_line(t_mlx_data *data, t_im f, t_im s)
{
	double	slope;
	double	x;
	int		dir;

	slope = (s.im - f.im) / (s.real - f.real);
	dir = (s.real - f.real) / fabs(s.real - f.real);
	x = f.real;
	while ((int)x != (int)s.real)
	{
		my_mlx_pixel_put(&(data->img), x, slope * (x - f.real) + f.im, 0x0000FF00);
		x += dir;
	}
}

void	draw_triangle(t_mlx_data *data, t_im first, double side)
{
	t_im	temp;

	temp = find_coords(first, 0, side);
	draw_line(data, first, temp);
	first = find_coords(temp, PI / 2 + PI / 6, side);
	printf("%f %f\n", first.real, first.im);
	draw_line(data, temp, first);
	temp = find_coords(first, PI + PI / 3, side);
	draw_line(data, first, temp);
}

void draw_basic_shape(t_mlx_data *data, t_im first, double ang, double side)
{
	t_im	temp;

	temp = find_coords(first, ang, side);
	draw_line(data, first, temp);
	first = find_coords(temp, ang - PI / 3, side);
	draw_line(data, temp, first);
	temp = find_coords(first, ang + PI / 3, side);
	draw_line(data, first, temp);
	first = find_coords(temp, ang, side);
	draw_line(data, temp, first);
}

void	draw_koch_snowflake(t_mlx_data data, int iter)
{
	t_im	a = init_number(300, 500);
	t_im	b = init_number(600, 500);
	double	size_side;

	size_side = 100 * pow((1 / 3), iter);
	draw_basic_shape(&data, a, 0, size_side);
	draw_basic_shape(&data, find_coords(a, 0, 300), PI / 2 + PI / 6, size_side);	
	draw_basic_shape(&data, find_coords(a, PI / 3, 300), PI + PI / 3, size_side);	
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
}