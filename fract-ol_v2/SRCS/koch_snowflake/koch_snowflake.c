/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_snowflake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:58:34 by mvenanci          #+#    #+#             */
/*   Updated: 2022/12/24 13:13:43 by mvenanci         ###   ########.fr       */
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
		my_mlx_pixel_put(&(data->img), x, a, 0x0000FF00);
		x += dir;
	}
}

void	erase_line(t_mlx_data *data, t_im f, t_im s)
{
	double	slope;
	double	x;
	int		dir;

	slope = (s.im - f.im) / (s.real - f.real);
	dir = (s.real - f.real) / fabs(s.real - f.real);
	x = f.real;
	while ((int)x != (int)s.real)
	{
		my_mlx_pixel_put(&(data->img), x, slope * (x - f.real) + f.im, 0);
		x += dir;
	}
}

void	draw_triangle(t_mlx_data *data, t_im first, double side)
{
	t_im	temp;

	temp = find_coords(first, 0, side);
	draw_line(data, first, temp);
	first = find_coords(temp, PI / 2 + PI / 6, side);
	draw_line(data, temp, first);
	temp = find_coords(first, PI + PI / 3, side);
	draw_line(data, first, temp);
}

t_im	draw_basic_shape(t_mlx_data *data, t_im first, double ang, double side)
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
	return (first);
}

double	find_angle(t_mlx_data *data, t_im first, double ang, double size)
{
	if (find_color(
		data, find_coords(first, ang + 0.0, 1)))
		return (ang);
	else if (find_color(data, find_coords(first, ang - PI / 3, size)))
		return (ang - PI / 3);
	else if (find_color(data, find_coords(first, ang + 4 / 6.0 * PI , size)))
		return (ang + 4 / 6.0 * PI);
	else
		return (-1);
}

t_im	find_line(t_mlx_data *data, t_im first, double ang, double size)
{
	double	next_point_ang;

	next_point_ang = find_angle(data, first, ang, size);
	printf("new point angle: %f\n", ang);
	return (find_coords(first, ang, size));
}

void	draw_koch_snowflake(t_mlx_data *data)
{
	t_im	a;
	t_im	curr;
	t_im	temp;
	double	size_side;
	double	ang;

	a = init_number(300, 500);
	temp = a;
	curr = init_number(0, 0);
	size_side = 300 * pow((1.0 / 3.0), data->iterations);
	ang = 0;
	printf("===============================================\n");
	if (!data->iterations)
		draw_triangle(data, a, size_side);
	else
	{
		while (!compare_coords(a, curr))
		{
			printf("start angle: %f\n", ang);
			ang = find_angle(data, temp, ang, size_side);
			curr = find_line(data, temp, ang, size_side / (1 / 3.0));
			printf("curr coords: %f %f %f %f\n", curr.real, curr. im, ang, size_side);
			erase_line(data, temp, curr);
			draw_basic_shape(data, temp, ang, size_side);
			temp = curr;
		}
		
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	
}