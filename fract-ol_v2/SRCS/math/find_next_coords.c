/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:53:26 by mvenanci          #+#    #+#             */
/*   Updated: 2022/12/24 00:42:44 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

t_im	find_coords(t_im a, double ang, double side)
{
	return (init_number(a.real + side * cos(ang), a.im - side * sin(ang)));
}

int	find_color(t_mlx_data *data, t_im first)
{
	int	offset;

	if ((int)first.im * (int)first.real > 0)
	{
		offset = (int)first.im * data->img.line_length + (int)first.real * (data->img.bits_per_pixel / 8);
		return (*((int *)(data->img.addr + offset)));
	}
	return (0);
}

int	compare_coords(t_im a, t_im b)
{
	return (abs(a.real == b.real) * abs(a.im == b.im));
}