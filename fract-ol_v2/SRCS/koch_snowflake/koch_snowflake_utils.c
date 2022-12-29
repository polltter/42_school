/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_snowflake_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:30:37 by mvenanci          #+#    #+#             */
/*   Updated: 2022/12/29 02:09:53 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

double	find_angle(t_im a, t_im b)
{
	double	diff_x;
	double	diff_y;

	diff_x = b.real - a.real;
	diff_y = a.im - b.im;
	if (diff_x >= 0)
		return (atan2(diff_y, diff_x));
	else
		return (atan2(diff_y, diff_x));	
}

t_im	find_midpoint(t_im a, t_im b)
{
	return (init_number((a.real + b.real) / 2, (a.im + b.im) / 2));
}

t_im	find_line(t_mlx_data *data, t_im first, double ang, double size)
{
	return (find_coords(first, ang, size));
}

t_im	find_vertice(t_im midpoint, double alfa, double triangle_heigth)
{
	t_im	vertice;

	vertice.real = midpoint.real + cos(PI / 2 - alfa) * triangle_heigth;
	vertice.im = midpoint.im + sin(PI / 2 - alfa) * triangle_heigth;
	return (vertice);
}

double	find_size(t_im a, t_im b)
{
	return (sqrt(pow(a.real - b.real, 2) + pow(a.im - b.im, 2)));
}